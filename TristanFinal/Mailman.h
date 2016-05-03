#ifndef Mailman_h
#define Mailman_h

#include <stdio.h>
#include <iostream>
#include <vector>


// creation of strcture City
struct City{
    std::string cityName;
    std::string message;
    std::vector<std::string> previousMessagesPassed;
    std::vector<std::string> previousMessagesRecieved;
    int balance;
    City *next;
    City *previous;

    City(){}; // default constructor

    // creation of string names
    City(std::string initName, City *initNext, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        message = initMessage;
    }

};

// Class header creation
class Mailman{
public:
    // public functions
    Mailman();
    ~Mailman();
    void addCity(std::string, std::string);
    void buildNetwork();
    void transmitMsgCoast(std::string);
    // void transmitMsg(std::string,std::string);
    // void printCityInfo(std::string)
    // void CheckPersonalBalance()
    // void printPreviousSent()
    // void checkCost(std::string,std::string)
    void printNetwork();
    void deleteCity(std::string cityNameDelete);
    void clearNetwork();
    int projectCost(std::string); //project how much it would cost to send a message from city A to city B
    void currentBalance();//tells how much money you currently have
    void chooseRandomGame(); //randomizes game to choose
    void earnMoney1();//if you run out of money, option 1
    void earnMoney2();//if you run out of money, option 2
    void earnMoney3();//if you run out of money, option 3
    void transmitMessagetoCity(std::string cityRecieved, std::string message);
    int checkCost(std::string cityRecieved);
    bool listBuilt();
    int checkPersonalBalance();
    void printCityInfo(std::string name);



protected:
private:
    // private variables for the address of head and tail.
    City *head;
    City *tail;
    int personalBalance;
    std::vector<std::string> previousMessagesSent;
};



#endif /* Mailman_hpp */
