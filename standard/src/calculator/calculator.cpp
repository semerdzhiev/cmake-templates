#include "mathlib/mathlib.h"
#include "tclap/CmdLine.h"

class CmdLineArguments {
    int m_number = 0;
    bool m_calculateFibbonachi = false;
    bool m_calculateFactorial = false;

public:
    int number()
    {
        return m_number;
    }

    bool calculateFibbonachi()
    {
        return m_calculateFibbonachi;
    }

    bool calculateFactorial()
    {
        return m_calculateFactorial;
    }

    void parse(int argc, char* argv[])
    {
        TCLAP::CmdLine cmd("A simple calculator", ' ', "1.0");
        
        TCLAP::ValueArg<int> number("n", "number", "The number N to use in the calculations", true, 0, "An integer");
        cmd.add(number);

        TCLAP::SwitchArg fibbonachi("b", "fibbonachi", "Calculate the N-th fibbonachi number", false);
        cmd.add(fibbonachi);
        
        TCLAP::SwitchArg factorial("f", "factorial", "Calculate factorial of N", false);
        cmd.add(factorial);

        cmd.parse(argc, argv);

        m_number = number.getValue();
        m_calculateFactorial = factorial.getValue();
        m_calculateFibbonachi = fibbonachi.getValue();
    }
};

int main(int argc, char* argv[])
{
    CmdLineArguments cmdArgs;

    try {
        cmdArgs.parse(argc, argv);
    }
    catch (TCLAP::ArgException& e) {
        std::cerr << "Error parsing command line arguments: " << e.error() << " for arg " << e.argId() << std::endl;
        return 1;
    }

    std::cout << "N = " << cmdArgs.number() << std::endl;

    if (cmdArgs.calculateFactorial())
        std::cout << cmdArgs.number() << "! = " << factorial(cmdArgs.number()) << std::endl;

    if (cmdArgs.calculateFibbonachi())
        std::cout << "Number " << cmdArgs.number() << " in the Fibbonachi sequence is " << fibbonachi(cmdArgs.number()) << std::endl;

    return 0;
}