#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
#include <filesystem>



std::string readFile(const std::filesystem::path& file) {
    std::ifstream f(file, std::ios::binary);
    const auto sz = std::filesystem::file_size(file);
    std::string line(sz, '\0');
    if (f.is_open())
        std::cout << "SUCCESSFUL" << std::endl;
    else std::cout << "ERROR" << std::endl;

    f.read(line.data(), sz);

    return line;
}

class Sentences {
public:
    explicit Sentences(const std::string& line) {
        int id{};
        std::string temp{};
        for (char c : line) {
            if (c != '.') {
                temp += c;
                ++id;
            }
            else {
                m_Sentences.insert({ id, temp });
                temp.clear();
                id = 0;
            }
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Sentences& sentences) {
        for (const auto& i : sentences.m_Sentences) {
            os << "[" << i.first << "] " << i.second << std::endl;
        }
        return os;
    }
private:
    std::map<int, std::string> m_Sentences;
};



template<typename T>
void uniqueWords(T& begin, T& end) {
    //Manual, without STL.
        /*for (auto ptr = begin; ptr != end; ++ptr) {
            T str;
            for (str = begin; str != ptr; ++str) {
                if (*ptr == *str) {
                    break;
                }
            }
            if (ptr == str) {
                std::cout << *ptr << " ";
            }

        }*/
        //Used STL.
    std::map<std::string, int> words;
    for (auto ptr = begin; ptr != end; ++ptr) {
        if (words.count(*ptr) == 0) {
            words[*ptr]++;
        }

    }
    for (const auto& i : words) {
        std::cout << i.first << " ";
    }
}

int main() {
    //1.
    std::vector<std::string> s{ "Hello", "world", "i", "i", "so", "tired", "so", "learn", "Cpp", "you", "know", "you" };
    auto begin = s.begin();
    auto end = s.end();
    for (const auto& i : s) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    uniqueWords(begin, end);
    std::cout << std::endl;
    std::list<std::string> s2{ "Hello", "world", "i", "i", "so", "tired", "so", "learn", "Cpp", "you", "know", "you" };
    auto list_begin = s2.begin();
    auto list_end = s2.end();
    std::cout << "List iterators: " << std::endl;
    for (const auto& i : s2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    uniqueWords(list_begin, list_end);
    std::cout << std::endl;

    //2.
    std::string fileName = readFile("../sentences.txt");
    Sentences file(fileName);
    std::cout << file;

    return 0;
}
