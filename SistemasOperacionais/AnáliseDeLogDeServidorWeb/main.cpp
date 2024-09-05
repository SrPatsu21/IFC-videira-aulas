#include <iostream>
#include <fstream>

int main()
{
    std::ifstream logf;
    logf.open("./access1.log");
    std::string helper;

    if (logf.is_open())
    {
        while (std::getline(logf, helper))
        {
            std::cout << helper << '\n';
        }
        logf.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
}