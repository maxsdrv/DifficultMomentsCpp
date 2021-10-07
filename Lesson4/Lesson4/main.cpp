#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <random>
#include <numeric>
#include <iomanip>


void insert_sorted(std::vector<int>& v, const int _value) {
	std::vector<int>::iterator low;
	low = std::lower_bound(v.begin(), v.end(), _value);
	std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
	v.insert(low, _value);
}

template <typename T, typename U>
void insert_sorted_template(T& container, const U _value) {
	auto low = std::lower_bound(container.begin(), container.end(), _value);
	container.insert(low, _value);
}


int main() {
	//1.
	std::cout << "\n Task 1 **********************************************" << '\n';
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distInt(-10, 10);
	std::vector<int> digits(10);
	int i;
	std::generate(digits.begin(), digits.end(), [&]() {
		i = distInt(rd);
		return i;
	});
	std::sort(digits.begin(), digits.end());
	std::copy(digits.begin(), digits.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
	insert_sorted(digits, 9);
	std::copy(digits.begin(), digits.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n" << "List = " << '\n';
	std::list<int> l{ 2, -5, 44, 7, -56, 133, 4};
	l.sort();
	std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
	insert_sorted_template(l, 15);
	std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
	
	
//2.
	std::cout << "\n Task 2 **********************************************" << '\n';
	std::cout.precision(4);
	std::uniform_real_distribution<float> distFloat(-99.9, 99.9);
	std::vector<float> analog(100);
	float n = 0.0f;
	std::generate(analog.begin(), analog.end(), [&]() {
		n = distFloat(rd);
		return n;
	});
	std::cout << "ANALOG SIGNAL: " << std::endl;
	std::copy(analog.begin(), analog.end(), std::ostream_iterator<float>(std::cout, "] ["));
	std::cout << '\n';
	std::vector<int> digitals;
	
	std::copy_if(analog.begin(), analog.end(), std::back_inserter(digitals), [](float x) {
		return std::truncf(x);
	});
	std::cout << "DIGITAL SIGNAL: " << std::endl;
	std::copy(digitals.begin(), digitals.end(), std::ostream_iterator<int>(std::cout, "] ["));
	std::cout << '\n';
	std::cout << "Error analog signal: " << '\n';

	auto logAnalog = std::accumulate(analog.begin(), analog.end(), 0, [](float x, float y) {
		return pow(x - y, 2);
		});
	auto logDigital = std::accumulate(digitals.begin(), digitals.end(), 0, [](int x, int y) {
		return pow(x - y, 2);
	});
	
	std::cout << "Analog = " << logAnalog << " Digital = " << logDigital << std::endl;

	return 0;
}