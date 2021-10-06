#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>


void insert_sorted(std::vector<int>& v, const int _value) {
	std::vector<int>::iterator low;
	low = std::lower_bound(v.begin(), v.end(), _value);
	std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
	v.insert(low, _value);
}

template <typename T>
void insert_sorted(T& container, const int _value) {
	auto low = std::lower_bound(container.begin(), container.end(), _value);
	container.insert(low, _value);
}


int main() {
	//1.
	srand(time(NULL));
	std::vector<int> digits(10);
	std::generate(digits.begin(), digits.end(), []() {
		return rand() % 100;
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
	insert_sorted(l, 15);
	std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
	
	
//2.


	return 0;
}