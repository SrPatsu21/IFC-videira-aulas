#include <iostream>
#include <fstream> //* File handling
#include <thread> //* Threads
#include <string> //* Strins functions
#include <list> //* Linked list

//* Number of lines that every thread will handle
#define PACKAGE_SIZE 10000

//* Create a package, the threads will work on them
std::list<std::string>* createPackage(std::fstream* logf)
{
    std::string helper;
    std::list<std::string>* new_package = new std::list<std::string>;
    //* feed the list
    int count = 0;
    while (count < PACKAGE_SIZE && std::getline(*logf, helper))
    {
        new_package->push_back(helper);
        count++;
    }
    //* verify if the file end
    if (logf->eof())
    {
        logf->close();
    }

    return new_package;
}

//* thread
void search(int id, std::list<std::string>* package)
{
    std::cout << id << " size:" << package->size() << std::endl;
}

int main()
{
    int thread_ids = 0;
    //* file
    std::fstream logf;
    logf.open("./access1.log");
    //* list of threads
    std::list<std::thread *> threads_list;

    if (logf.is_open())
    {
        //* thread loop
        while (logf.is_open())
        {
            thread_ids++;
            //* add on list
            // threads_list.push_back();
            std::thread(search, thread_ids, createPackage(&logf)).detach();
            //* like a join, but this loop won`t waint this thread
            // threads_list.back()->detach();
        }
    }
    else
    {
        std::cout << "Unable to open file";
    }
}