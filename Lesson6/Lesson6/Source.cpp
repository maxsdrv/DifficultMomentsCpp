#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <future>

using namespace std::chrono_literals;

std::mutex mtx;


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

	std::cout << SumToVectors({ 1, 1, 1, 1 }, { 3, 3, 3, 3 });
	




	return 0;
}