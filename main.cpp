#include "include/string.hpp"

#include <string>

int main() {

	teg::String array[5];

	for (std::size_t i = 0; i < std::size(array); ++i)
		std::cin >> array[i];

	return 0;

}