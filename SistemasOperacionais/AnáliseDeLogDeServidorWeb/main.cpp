#include <iostream>
#include <fstream> //* File handling
#include <thread> //* Threads
#include <string> //* Strins functions
#include <list> //* Linked list
#include <regex>//* Regular Expression

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

//* Thread Class
class ThreadClass
{
private:
    int id;
    int ok_200 = 0;
    int hours[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool running = true;
public:
    ThreadClass(int id)
    {
        this->id = id;
    };
    //* main function
    void search(std::list<std::string>* package)
    {
        //* analysis package
        while (package->size())
        {
            std::string str = package->back();
            // // +[0-9]\\.+[0-9]\\.+[0-9]\\.+[0-9]  - - \\[.*\\] \".*\" 200
            // if(std::regex_match (str, std::regex("^([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+\.)") ))
            // {
            //     this->ok_200++;
            // }
            if(true)
            {
                this->ok_200++;
            }
            package->pop_back();
        }
        running = false;
    }

    bool isRunning()
    {
        return this->running;
    }
    void printValues()
    {
        //* print the results
        std::cout << this->id << " ended with, 200 status:" << ok_200 << ", hours:";
        for (size_t i = 0; i < 24; i++)
        {
            std::cout << " " << hours[i];
        }
        std::cout << std::endl;
    }
};

int main()
{
    int thread_ids = 0;
    //* file
    std::fstream logf;
    logf.open("./access1.log");
    //* list of threads
    std::list<ThreadClass *> threads_list;
    std::list<ThreadClass *>::iterator it;

    if (logf.is_open())
    {
        //* thread loop
        while (logf.is_open() || threads_list.size())
        {
            if (logf.is_open())
            {
                thread_ids++;
                //* create object
                ThreadClass* thread_obj = new ThreadClass(thread_ids);
                //* create package
                std::list<std::string>* package = createPackage(&logf);
                //* create and run the thread
                std::cout << thread_ids << " started , package size:" << package->size() << std::endl;
                std::thread(&ThreadClass::search, thread_obj, package).detach();
                //* add on list
                threads_list.push_back(thread_obj);
            }

            //* veryfy when threads end
            it = threads_list.begin();
            if (threads_list.size())
            {
                while ((*it) != (threads_list.back()))
                {
                    if ((*it)->isRunning())
                    {
                        ++it;
                    }else
                    {
                        (*it)->printValues();
                        threads_list.erase(it++);
                    }
                }
                if ((*it)->isRunning())
                {
                }else
                {
                    (*it)->printValues();
                    threads_list.erase(it);
                }
            }
        }
    }
    else
    {
        std::cout << "Unable to open file";
    }

    return 0;
}