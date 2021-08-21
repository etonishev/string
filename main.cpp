#include "include/string.hpp"

#include <string>

int main() {

	teg::String str;
	teg::String copyStr(std::string("dsf"));

	copyStr = copyStr + str;

	std::cout << copyStr << '\n';

	return 0;

}