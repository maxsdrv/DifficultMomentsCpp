#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <numeric>
#include <future>
#include <map>

using namespace std::chrono_literals;
using Map = std::map<int, std::string>;

std::mutex mtx;


class Host {
public:
	void addThing(int cost, std::string name) {
        std::lock_guard lg(m);
        std::this_thread::sleep_for(1000ms);
		std::cout << "ID thread = " << std::this_thread::get_id() <<
        " ===================\tADD THING STARTED\t ===================" << std::endl;
        std::this_thread::sleep_for(1000ms);

        std::cout << "HOST ADDED " << name << " " << cost << "$" << std::endl;

		m_Vault.insert({ cost, std::move(name) });

        std::cout << "ID thread = " << std::this_thread::get_id() <<
                  " ===================\tADD THING STOPPED\t ===================" << std::endl;
	}
	void stealThing() {
        std::this_thread::sleep_for(1000ms);
        std::lock_guard lg(m);
        std::cout << "ID thread = " << std::this_thread::get_id() <<
                  " ===================\tSTEAL THING STARTED\t ===================" << std::endl;
        std::this_thread::sleep_for(1000ms);

		auto exp = std::max_element(m_Vault.begin(), m_Vault.end(), [](const auto& lhs, const auto& rhs) {
			return lhs.first < rhs.first;
		});

		if (m_Vault.empty()) {
			std::cout << "HOUSE IS EMPTY: " << std::endl;
		}
		else {
            std::this_thread::sleep_for(500ms);
            std::cout << "THIEF STOLE : " << exp->second << std::endl;

			m_Vault.erase(exp);
		}
        std::cout << "ID thread = " << std::this_thread::get_id() <<
        " ===================\tSTEAL THING STOPPED\t ===================" << std::endl;
		
	}

	friend std::ostream& operator<<(std::ostream& os, const Host& host) {
		for (const auto& i : host.m_Vault) {
			os << i.first << " " << i.second << std::endl;
		}
		return os;
	}
	
private:
    Map m_Vault;
    std::mutex m;
};

int SumToVectors(const std::vector<int>& one, const std::vector<int>& two) {
	std::future<int> f = std::async([&one] {
        std::cout << "Thread N2 =";
		return std::accumulate(one.begin(), one.end(), 0);
	});
	std::cout << "Thread N1 + ";
	int result = std::accumulate(two.begin(), two.end(), 0);

    return result + f.get();
}



void pcout(int number) {
	std::lock_guard lg(mtx);
	std::cout << "Start thread " << number << std::endl;
	std::this_thread::sleep_for(1000ms);
	std::cout << "Stop thread " << number << std::endl;
}



int main() {
//1.
/*Создайте потокобезопасную оболочку для объекта cout.Назовите ее pcout.Необходимо, чтобы несколько
потоков могли обращаться к pcout и информация выводилась в консоль.Продемонстрируйте работу pcout.*/
    std::cout << "==============================TASK N1======================================" << std::endl;
	std::thread th1(pcout, 1);
	std::thread th2(pcout, 2);
	std::thread th3(pcout, 3);

	th1.join();
	th2.join();
	th3.join();

//2.
/*Реализовать функцию, возвращающую i-ое простое число (например, миллионное простое число равно 15485863).
Вычисления реализовать во вторичном потоке. В консоли отображать прогресс вычисления. 
*/
    std::cout << "==============================TASK N2======================================" << std::endl;
    std::cout << "Result = ";
	std::cout << SumToVectors({ 1, 1, 1, 1 }, { 3, 3, 3, 3 }) << std::endl;

/*Промоделировать следующую ситуацию.Есть два человека(2 потока) : хозяин и вор.Хозяин приносит домой вещи.
При этом у каждой вещи есть своя ценность.Вор забирает вещи, каждый раз забирает вещь с наибольшей ценностью.
*/
    std::cout << "==============================TASK N3======================================" << std::endl;
	Host general;

    std::thread host([&general]() {
        general.addThing(1000, "Notebook");
        general.addThing(5000, "Car");
        general.addThing(800, "Bicycle");
        general.addThing(300, "Mobile Phone");
    });

    std::thread thief([&general] {
        general.stealThing();
    });

    for (size_t i = 0; i <= 10; ++i) {
        std::cout << "ID of thread = " << std::this_thread::get_id() << "\tmain thread\t" << i << std::endl;
        std::this_thread::sleep_for(500ms);
    }

    host.join();
    thief.join();




	


	return 0;
}