#include <cstdlib>
#include <iostream>
#include <filesystem>

#include "library.h"

namespace fs = std::filesystem;

void displayUsage(const char* executablePath)
{
	try {
		fs::path ep(executablePath);
		
		std::cout
			<< "Usage:\n\t"
			<< ep.filename()
			<< " <integer>\n";
	}
	catch (...) {
		std::cout << "Cannot parse path from argv[0]";
	}
}

int main(int argc, char* argv[])
{
	if (argc <= 0) {
		std::cout << "Invalid argument list!\n";
		return 1;
	}
	
	if (argc != 2) {
		displayUsage(argv[0]);
		return 2;
	}

	int value = std::atoi(argv[1]);
	std::cout << value << "! = " << fibonacci(value) << std::endl;
}