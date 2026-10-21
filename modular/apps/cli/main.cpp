#include "myproject/math/calculator.h"

#include <stdexcept>
#include <iostream>

class CmdLineArguments {
    int m_number = 0;
    bool m_calculateFibonacci = false;
    bool m_calculateFactorial = false;

public:
    int number()
    {
        return m_number;
    }

    bool calculateFibonacci()
    {
        return m_calculateFibonacci;
    }

    bool calculateFactorial()
    {
        return m_calculateFactorial;
    }

    void parse(int argc, char* argv[])
    {
        bool number_found = false;

        for(int i = 1; i < argc; ++i) {
            if(argv[i][0] == '\0') {
                throw std::invalid_argument("Empty string argument");
            }
            else if(argv[i][0] == '-') {
                switch(argv[i][1]) {
                    case 'b':
                        m_calculateFibonacci = true;
                        break;
                    case 'f':
                        m_calculateFactorial = true;
                        break;
                    default:
                        throw std::invalid_argument("Invalid argument");
                }
            }
            else {
                m_number = atoi(argv[i]);
                if(m_number == 0)
                    throw std::invalid_argument("Invalid number");
                number_found = true;
            }
        }

        if( ! number_found )
            throw std::invalid_argument("No number was specified");
    }
};

int main(int argc, char* argv[])
{
    CmdLineArguments cmdArgs;

    try {
        cmdArgs.parse(argc, argv);
    }
    catch (std::invalid_argument& e) {
        std::cerr << "Error parsing command line arguments: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "N = " << cmdArgs.number() << std::endl;

    if (cmdArgs.calculateFactorial())
        std::cout << cmdArgs.number() << "! = " << myproject::math::factorial(cmdArgs.number()) << std::endl;

    if (cmdArgs.calculateFibonacci())
        std::cout << "Number " << cmdArgs.number() << " in the Fibonacci sequence is " << myproject::math::fibonacci(cmdArgs.number()) << std::endl;

    return 0;
}
