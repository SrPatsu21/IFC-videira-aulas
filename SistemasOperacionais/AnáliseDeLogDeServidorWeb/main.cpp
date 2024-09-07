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

    //* verify if status is 200 ok
    void verifyOk200(std::string str)
    {
        if(std::regex_match (str, std::regex(".*(\\\".*\\\"\\ 200\\ ).*") ))
        {
            this->ok_200++;
        }
    }

    //* verify the hour that the connection happened
    void verifyHour(std::string str)
    {
        std::smatch match;
        std::regex double_dot(".*(\\[\\:\\:.*\\]).*");
        int pos[2];
        regex_search(str, match, double_dot);
        pos[0]=match.position(0);
        pos[1]=match.position(1);
        //* find the rest of the string.
        str = match.suffix().str();
        if (pos[1]-pos[0] <= 2)
        {
            str = str.substr(pos[0],pos[1]);
            this->hours[std::stoi(str)]++;
            std::cout << std::stoi(str) << std::endl;
        }
    }

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
            //* ok 200
            verifyOk200(str);
            //* <https://www.geeksforgeeks.org/program-to-find-all-match-of-a-regex-in-a-string/>
            //* find hour
            verifyHour(str);
            //* remove string from the list
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
    logf.open("./access2.log");
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