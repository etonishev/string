#include "include/string.hpp"

#include <string>

int main() {

	teg::String str;
	teg::String copyStr(str);

	copyStr = copyStr + str;

	std::cout << copyStr << '\n';

	return 0;

}