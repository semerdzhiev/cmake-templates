#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "A total of " << argc << " argument(s) passed.\n";
	
	for(int i = 0; i < argc; ++i)
		std::cout << i << ": " << argv[i] << "\n";
}