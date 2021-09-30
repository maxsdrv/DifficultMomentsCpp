#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <fstream>
#include <algorithm>

#include "Timer.h"


enum class Algorithms {
    COUNT_IF_FIND,
    COUNT_IF_FOR,
    FOR_FIND,
    FOR_FOR
};


class ReadFile {
public:
    explicit ReadFile(std::ifstream& file) {
        if (file.is_open()) {
            std::cout << "File was read successfully" << std::endl;
        }
        else std::cout << "ERROR::File cannot be read!!!" << std::endl;

        std::istreambuf_iterator<char> eos;
        text.append(std::istreambuf_iterator<char>(file), {});
    }

    long countVowelLetters(Algorithms a) {
        std::string str {"aeiouyAEIOUY"};
        if (a == Algorithms::COUNT_IF_FIND) {
            std::cout << "Algorithms COUNT_IF_FIND: " << std::endl;
            auto result = std::count_if(text.begin(), text.end(), [&](char c) {
                return str.find(c) != std::string::npos;
            });
            return result;
        }
        else if (a == Algorithms::COUNT_IF_FOR) {
            std::cout << "Algorithms COUNT_IF_FOR: " << std::endl;
            auto result = std::count_if(text.begin(), text.end(), [&](char c) {
                for (int i = 0; i < str.size(); ++i) {
                    if (c == str[i]) {
                        return true;
                    }
                }
                return false;
            });

            return result;
        }
        else if (a == Algorithms::FOR_FIND) {
            std::cout << "Algorithms FOR_FIND" << std::endl;
            int count = 0;
            for (char i : text) {
                if (str.find(i) != std::string::npos) {
                    ++count;
                }
            }
            return count;
        }
        else if (a == Algorithms::FOR_FOR) {
            std::cout << "Algorithms FOR_FOR" << std::endl;
            int count = 0;
            for (char i : str) {
                for (char j : text) {
                    if (j == i) {
                        ++count;
                    }
                }
            }
            return count;
        }

        return 0;
    }
    friend std::ostream& operator<<(std::ostream& os, const ReadFile& rFile) {
        std::cout << rFile.text << std::endl;
        return os;
    }
private:
    std::string text;
};

template<typename Value>
void mySwap(Value *a, Value *b) {
    Value temp = std::move(*a);
    *a = std::move(*b);
    *b = std::move(temp);
}


template<typename Vr>
void SortPointers(std::vector<Vr *> &prV) {
    std::sort(prV.begin(), prV.end(), [](const int *left, const int *right) {
        return *left < *right;
    });
}



int main() {

//1.
    std::cout << "-------------------No_1--------------" << '\n';
    int x = 10;
    int y = 20;
    mySwap<int>(&x, &y);
    std::cout << x << " " << y << '\n';
    std::cout << "-------------------No_2--------------" << '\n';
//2.
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 55);
    std::vector<int *> someVec;
    int *ptr;
    for (int i = 0; i < 10; ++i) {
        ptr = new int(dist(mt));
        someVec.push_back(ptr);
    }
    std::cout << "Before sort: " << '\n';
    for (const auto &i: someVec) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::cout << "After sort: " << '\n';
    SortPointers(someVec);
    for (const auto &i: someVec) {
        std::cout << *i << " ";
    }
    std::cout << '\n';

    for (auto &it: someVec) {
        delete it;
    }
    someVec.clear();


//3.
    std::string path = "War and peace.txt";
    std::ifstream filename(path);
    ReadFile warPeace(filename);
    Timer timer;
    timer.start("COUNT_IF_FIND ");
    std::cout << warPeace.countVowelLetters(Algorithms::COUNT_IF_FIND) << std::endl;
    timer.print();
    timer.start("COUNT_IF_FOR ");
    std::cout << warPeace.countVowelLetters(Algorithms::COUNT_IF_FOR) << std::endl;
    timer.print();
    timer.start("FOR_FIND ");
    std::cout << warPeace.countVowelLetters(Algorithms::FOR_FIND) << std::endl;
    timer.print();
    timer.start("FOR_FOR ");
    std::cout << warPeace.countVowelLetters(Algorithms::FOR_FOR) << std::endl;
    timer.print();



    return 0;
}








