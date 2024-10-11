#include <iostream>
#include <fstream> //* File handling
#include <thread> //* Threads
#include <string> //* Strins functions
#include <list> //* Linked list
#include <regex> //* Regular Expression
#include <cstring> //* strcpy()

//* Number of lines that every thread will handle
#define PACKAGE_SIZE 10000
#define DAYHOURS 24

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
    int hours[DAYHOURS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool running = true;

    //* verify if status is 200 ok
    void verifyOk200(std::smatch* match)
    {
        if ((*match)[10].str() == "200") {
            this->ok_200++;
        }
    }
    //* verify the hour that the connection happened
    void verifyHour(std::smatch* match)
    {
        int hour = stoi((*match)[5].str());
        this->hours[hour]++;
    }

public:
    ThreadClass(int id)
    {
        this->id = id;
    };
    //* main function
    void search(std::list<std::string>* package)
    {
        const std::regex _pattern {"^([0-9\\.]*)(?:\\s[^\\s]*\\s[^\\s]*\\s)(?:\\[)(\\d{2})(?:\\/)([a-zA-z]{3})(?:\\/)(\\d{4})(?:\\:)(\\d{2})(?:\\:)(\\d{2})(?:\\:)(\\d{2})(?:\\s)([\\+\\d]*)(?:\\])(?:\\s\")([^\"]*)(?:\"\\s)([\\d]*)(?:\\s)([\\d]*)(?:\\s\")([^\"]*\")(?:\\s\")([^\"]*\")(?:\\s\")(.[^\"]*\")$"};
        //* analysis package
        while (package->size())
        {
            std::string str = package->back();
            //* regex
            std::smatch match;
            std::regex_search(str, match, _pattern);
            //* verify size
            if (match.size() != 15)
            {
                std::cout << "Linha X veio com informação diferente do esperado!";
            } else {
                //* ok 200
                verifyOk200(&match);
                //* <https://www.geeksforgeeks.org/program-to-find-all-match-of-a-regex-in-a-string/>
                //* find hour
                verifyHour(&match);
            }
            //* remove string from the list
            package->pop_back();
        }
        running = false;
    }
    //* verify if is running
    bool isRunning()
    {
        return this->running;
    }
    //* print all values
    void printValues()
    {
        //* print the results
        std::cout << this->id << " ended with, 200 status:" << ok_200 << ", hours:";
        for (size_t i = 0; i < 24; i++)
        {
            std::cout << " " << this->hours[i];
        }
        std::cout << std::endl;
    }
    //* join threads
    void join(ThreadClass* other)
    {
        this->ok_200 += other->ok_200;
        for (size_t i = 0; i < DAYHOURS; i++)
        {
            this->hours[i] += other->hours[i];
        }
    }
};

int main()
{
    int thread_ids = 0;
    int maxthreads = std::thread::hardware_concurrency();
    //* file
    std::fstream logf;
    logf.open("./access1.log");
    //* list of threads
    std::list<ThreadClass *> threads_list;
    std::list<ThreadClass *>::iterator it;
    ThreadClass* join_all = new ThreadClass(0);

    if (logf.is_open())
    {
        //* thread loop
        while (logf.is_open() || threads_list.size())
        {
            if (logf.is_open() && threads_list.size() < maxthreads)
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
                        //* join values
                        join_all->join((*it));
                        //* delete
                        threads_list.erase(it++);
                    }
                }
                if ((*it)->isRunning())
                {
                }else
                {
                    (*it)->printValues();
                    //* join values
                    join_all->join((*it));
                    //* delete
                    threads_list.erase(it);
                }
            }
        }
        join_all->printValues();
        std::cout << std::endl << std::endl;
    }
    else
    {
        std::cout << "Unable to open file";
    }

    return 0;
}