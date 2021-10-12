#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <future>
#include <map>
#include <iterator>

using namespace std::chrono_literals;
using Map = std::map<int, std::string>;

std::mutex mtx;


class Host {
public:
	
	
	Map addThing(int cost, std::string name) {
		std::lock_guard lg(mtx);
		std::cout << "Thread start" << std::endl;
		std::cout << std::this_thread::get_id() << std::endl;
		m_Vault.insert({ cost, std::move(name) });

		return m_Vault;
	}
	bool stealThing() {
		
		auto exp = std::max_element(m_Vault.begin(), m_Vault.end(), [](const auto& lhs, const auto& rhs) {
			return lhs.first < rhs.first;
		});
		std::cout << std::this_thread::get_id() << std::endl;
		std::lock_guard lg2(mtx);
		if (m_Vault.empty()) {
			std::cout << "map is empty" << std::endl;

			return false;
		}
		else {
			std::cout << "Thread 2" << std::endl;
			std::for_each(m_Vault.begin(), m_Vault.end(), [](const auto& p) {
				std::cout << p.first << " " << p.second << std::endl;
			});
			m_Vault.erase(exp);
			std::cout << "Stop" << std::endl;

			return true;
		}
		
	}
	friend std::ostream& operator<<(std::ostream& os, const Host& host) {
		for (const auto& i : host.m_Vault) {
			os << i.first << " " << i.second << std::endl;
		}
		return os;
	}
	
private:
	 Map m_Vault;
};

int SumToVectors(const std::vector<int>& one, const std::vector<int>& two) {
	std::future<int> f = std::async([&one] {
		std::cout << "Thread N2 = ";
		return std::accumulate(one.begin(), one.end(), 0);
	});
	std::cout << "Thread N1" << std::endl;
	int result = std::accumulate(two.begin(), two.end(), 0);
	
	return result + f.get();
}



void pcout(int number) {
	std::lock_guard lg(mtx);
	std::cout << "Start thread " << number << std::endl;
	std::this_thread::sleep_for(1000ms);
	std::cout << "Stop thread " << number << std::endl;
}


Map addThing(int cost, std::string name) {
	Map temp;
	temp.insert({ cost, std::move(name) });
	return temp;
}

int main() {
//1.
/*Создайте потокобезопасную оболочку для объекта cout.Назовите ее pcout.Необходимо, чтобы несколько 
потоков могли обращаться к pcout и информация выводилась в консоль.Продемонстрируйте работу pcout.*/

	/*std::thread th1(pcout, 1);
	std::thread th2(pcout, 2);
	std::thread th3(pcout, 3);

	th1.join();
	th2.join();
	th3.join();*/

//2.
/*Реализовать функцию, возвращающую i-ое простое число (например, миллионное простое число равно 15485863).
Вычисления реализовать во вторичном потоке. В консоли отображать прогресс вычисления. 
*/

	/*std::cout << SumToVectors({ 1, 1, 1, 1 }, { 3, 3, 3, 3 });
	*/

/*Промоделировать следующую ситуацию.Есть два человека(2 потока) : хозяин и вор.Хозяин приносит домой вещи.
При этом у каждой вещи есть своя ценность.Вор забирает вещи, каждый раз забирает вещь с наибольшей ценностью.
*/
	Host general;
	/*Host host_class;*/

	auto host1(std::async(std::launch::async, &Host::addThing, general, 1000, "notebook"));
	auto host2 (std::async(std::launch::async, &Host::addThing, general, 500, "TV"));
	auto host3(std::async(std::launch::async, &Host::addThing, general, 100, "phone"));
	for (const auto& [key, value] : host3.get()) {
		std::cout << key << " " << value << std::endl;
	}
	std::cout << general;
	/*auto host = std::async(std::launch::async, addThing, 1000, "notebook");
	for (const auto& [key, value] : host.get()) {
		std::cout << key << " " << value << std::endl;
	}*/
	
	
	
	

	
	/*host_class.addThing(1000, "notebook");
	host_class.addThing(200, "phone");
	host_class.addThing(500, "TV");
	std::cout << host_class << std::endl;
	host_class.stealThing();
	std::cout << host_class << std::endl;*/

	return 0;
}