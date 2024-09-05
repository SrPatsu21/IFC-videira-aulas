#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <list>

#define PACKAGE_SIZE 10000

std::list<std::string>* createPackage(std::fstream* logf)
{
    std::string helper;
    std::list<std::string>* new_package = new std::list<std::string>;
    int count = 0;
    while (count < PACKAGE_SIZE && std::getline(*logf, helper))
    {
        new_package->push_back(helper);
        count++;
    }
    if (logf->eof())
    {
        logf->close();
    }
    return new_package;
}

void search(int id, std::list<std::string>* package)
{
    std::cout << id << " size:" << package->size() << std::endl;
}

int main()
{
    int thread_ids = 0;
    std::fstream logf;
    logf.open("./access1.log");


    if (logf.is_open())
    {
        while (logf.is_open())
        {
            thread_ids++;
            std::thread th(search, thread_ids, createPackage(&logf));
            th.detach();
        }
    }
    else
    {
        std::cout << "Unable to open file";
    }
}