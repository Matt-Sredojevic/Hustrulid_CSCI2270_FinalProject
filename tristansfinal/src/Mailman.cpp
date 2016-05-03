#include "Mailman.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

// Creation of communicationNetwork
Mailman::Mailman(){
    personalBalance = 20;
    head=NULL;
    tail=NULL;
}

Mailman::~Mailman(){

}


// add city function
void Mailman::addCity(std::string previousCity, std::string newCity){

    // set current to head of list
    City *current = head;
    City *addedCity = new City;
    addedCity -> balance = 0;

    // check if adding node to replace head
    if(previousCity == "First"){
        addedCity -> cityName = newCity;
        addedCity -> message = "";
        addedCity -> next = head;
        addedCity -> previous = NULL;
        head -> previous = addedCity;
        head = addedCity;
        return;

    }

    // search for previous city otherwise
    while(current != NULL){
        if(current -> cityName == previousCity){
            break;
        }
        // set current equal to the next city
        current = current -> next;
    }

    if(current != NULL){
        // check if the node goes on the tail
        if(current == tail){
            addedCity -> cityName = newCity;
            addedCity -> message = "";
            addedCity -> next = NULL;
            addedCity -> previous = tail;
            tail -> next = addedCity;
            tail = addedCity;

        }
        // check if the node goes in the middle
        else{
            addedCity -> cityName = newCity;
            addedCity -> message = "";
            addedCity -> next = current -> next;
            addedCity -> previous = current;
            addedCity -> next -> previous = addedCity;
            current -> next = addedCity;
        }
    }
}


// build net work
void Mailman::buildNetwork(){

    std::string cities[10] = {"Los Angeles","Phoenix","Denver","Dallas","St.Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};

    // create head node
    head = new City;
    head -> cityName = cities[0];
    head -> message = "";
    head -> next = NULL;
    head -> previous = NULL;
    head -> balance = 0;

    std::cout << "NULL <- " << head -> cityName;

    // create current node
    City *current = head;


    // build network based on string array and set next addresses accordingly
    int i = 1;
    while(i<10){
        City *temp = new City;
        temp -> cityName = cities[i];
        temp -> message = "";
        temp -> next = NULL;
        temp -> previous = current;

        std::cout << " <-> " << temp -> cityName;

        current -> next = temp;
        current = temp;

        i++;
    }

    tail = current;

    std::cout << " -> NULL" << std::endl;

}


// transmit message
void Mailman::transmitMsgCoast(std::string message){
    int cost = checkCost(tail->cityName);
    if(cost > personalBalance){
        std::cout << "Insufficient Funds" << std::endl;
        std::cout << "Cost to Transmit: " << cost << std::endl;
        std::cout << "Personal Balance: " << personalBalance << std::endl;
        return;
    }
    City *sender = head;
    sender -> message = message;
    previousMessagesSent.push_back(message);
    while(sender != NULL){
        // print message, save message, and finally delete from sender
        // check to make sure not on tail node
        if(sender -> next != NULL){
            std::cout<< sender->cityName<<" sent "<<sender->message << " to " << sender -> next -> cityName<< std::endl;
            sender -> next -> message = sender -> message;
            sender -> previousMessagesPassed.push_back(sender -> message);
            sender -> message = "";
            sender -> balance ++;
            sender = sender -> next;
            personalBalance --;
        }
        else{
            std::cout<< sender->cityName<<" received "<<sender->message<< " from " << sender -> previous -> cityName <<std::endl;
            sender -> previousMessagesRecieved.push_back(sender -> message);
            sender -> message = "";
            sender = sender -> next;
        }
    }

}

void Mailman::transmitMessagetoCity(std::string cityRecieved, std::string message){
    City *sender = head;
    City * recieved = sender;
    int cost = checkCost(cityRecieved);
    if (cost == 0){
        return;
    }
    if(cost > personalBalance){
        std::cout << "Insufficent Funds" << std::endl;
        std::cout << "Cost to Transmit: " << cost << std::endl;
        std::cout << "Peronal Balance: " << personalBalance << std::endl;
        return;
    }

    while(recieved -> cityName != cityRecieved){
        recieved = recieved -> next;
    }

    // check to make sure the list has been build
    sender -> message = message;
    previousMessagesSent.push_back(message);
    while(sender != recieved -> next){
        // print message, save message, and finally delete from sender
        // check to make sure not on tail node
        if(sender != recieved){
            std::cout<< sender->cityName<<" sent "<<sender->message << " to " << sender -> next -> cityName<< std::endl;
            sender -> next -> message = sender -> message;
            sender -> previousMessagesPassed.push_back(sender -> message);
            sender -> message = "";
            sender -> balance ++;
            sender = sender -> next;
            personalBalance --;
        }
        else{
            std::cout<< sender->cityName<<" received "<<sender->message<< " from " << sender -> previous -> cityName <<std::endl;
            sender -> previousMessagesRecieved.push_back(sender -> message);
            sender -> message = "";
            sender = sender -> next;
        }
    }
    // print if list has not been built.
}

// print the network
void Mailman::printNetwork(){
    City *current = head;
    if (current == NULL) return;
    // access each node
    std::cout << "NULL <- " << current -> cityName;
    current = current -> next;
    while(current != NULL){
        std::cout << " <-> " << current -> cityName;
        current = current -> next;
    }
    std::cout << " -> NULL" << std::endl;

}

// delete city from list

void Mailman::deleteCity(std::string cityDelete){

    City * current = head;
    City * temp = head;

    // Find city to delete
    while(current != NULL){
        if(cityDelete == current->cityName){
            break;
        }
        current = current->next;
        temp = current;
    }
    if(current!=NULL){
        // if city is the head
        if(current == head){
            head = current->next;
            head -> previous = NULL;
            delete temp;
        }
        // if city is the tail
        else if(current == tail){
            tail = current ->previous;
            tail -> next = NULL;
            delete temp;
        }

        // if city is in the middle
        else{
            current->previous->next = current -> next;
            current -> next -> previous = current -> previous;
            delete temp;
        }
    }
}

void Mailman::printCityInfo(std::string name){
    City *temp = head;
    while(temp != NULL){
        if(temp -> cityName == name){
            break;
        }
        temp = temp -> next;
    }
    if(temp == NULL){
        std::cout << "City Not Found" << std::endl;
    }
    else{
        std::cout << "City: " << temp -> cityName << std::endl;
        std::cout << "Balance: " << temp -> balance <<" dollar(s)."<< std::endl;

    }
}


// Clearing entire Network
void Mailman::clearNetwork(){
    City * current = head;
    City * temp = head;

    //run through each item and delete it
    while(current != NULL){
        current = current->next;
        std::cout << "deleting " << temp -> cityName << std::endl;
        delete temp;
        temp = current;
    }

    head = current;

}

bool Mailman::listBuilt(){
    if(head == NULL) return false;
    else return true;
}

int Mailman::checkPersonalBalance(){
    return personalBalance;
}


int Mailman::checkCost(std::string cityRecieved){
    City * temp = head;
    int cost = 0;

    if(head -> cityName == cityRecieved){
        std::cout << "Cannot send message from sender city to sender city" << std::endl;
        return cost;
    }

    while(temp != NULL){
        if(temp -> cityName == cityRecieved){
            return cost;
        }
        cost ++;
        temp = temp -> next;
    }

    if (temp == NULL){
        std::cout << "City Not found" << std::endl;
        return 0;
    }
    else{
        return cost;
    }
}

void Mailman::earnMoney1(){
    int num = 0;
    int money=10; //amount of money you will earn

    int guess;      ///Matt changed guess from a string to an int

	srand(time(0)); //random number generator

	num = rand() % 10 + 1; // random number between 1 and 10

    /*string randomnum;  //converting the number into a string
    ostringstream convert;
    convert<<num;
    randomnum=convert.str();*/ ///Matt Removed this and is comparing int's as opposed to strings


	cout << "\nGuessing Game\n";
	while (guess != num){
		cout << "Enter a guess between 1 and 10 : ";
		cin >> guess;
		if (guess > num){
            cout << "Too high!\n\n";
		}
		else if (guess < num){
            cout << "Too low!\n\n";
		}
		else{
            cout << "\nCorrect! You earned " << money << " dollars!\n";
            cout << "\n Click Enter to continue..."<<endl;
		}
        cin.ignore();
	}

	//cin.ignore();
	//cin.get();

    personalBalance=personalBalance+10;
}

void Mailman::earnMoney2(){
    cout<<"\n RIDDLE RIDDLE!!\n"<<endl;

    string riddleAnswer1;
    string riddleAnswer2;

    bool getout=false;
    while(getout != true){
        int guesses=0;
        int tries=5;
        //first riddle
        while(riddleAnswer1 != "3" and guesses < 5 ){
            cout<<"If you have 3 hens, 2 hens, and 5 hens, how many hens?"<<endl;
            cin>>riddleAnswer1;
            if(riddleAnswer1=="3"){
                cout<<"Correct! There are "<<riddleAnswer1<<" of the word 'hens'." <<endl;
                cout<<"You have earned 10 dollars!\n"<<endl;
                personalBalance=personalBalance+10;
                getout=true;
            }
            if(tries==2){
                cout<<"Incorrect, I'll give you one more try."<<endl;
            }
            if(tries > 2 and getout != true){
                cout<<"Try again..."<<endl;
            }
            guesses++;
            tries--;
        }


        if(getout==false){
            cout<< "\n Since that riddle was too difficult, maybe you can get this one."<<endl;
            cout<<"Look for the differences in the question. \n"<<endl;
            while(riddleAnswer2 != "10"){

                cout<< "If you have 3 hens, 2 hens, and 5 hens, how many hens do you have?"<<endl;
                cin>>riddleAnswer2;

                if(riddleAnswer2=="10"){
                    cout<<"Correct! There are "<<riddleAnswer2<<" hens." <<endl;
                    cout<<"You have earned 10 dollars!\n"<<endl;
                    personalBalance=personalBalance+10;
                    getout=true;
                }
                else{
                    cout<<"\n Incorrect, try again.."<<endl;
                }
            }
        }
    getout=true;
    }
}

void Mailman::earnMoney3(){
    cout<<"\n Math Wizards Get Money!!"<<endl;

    bool getout=false;
    int earnedmoney=0;

    while (getout != true){

        string answer1;
        while(answer1 != "4"){
            cout<<"How many factors of 10 are there?"<<endl;
            cin>>answer1;
            if(answer1=="4"){
                cout<<"\n Correct! You earned 2 dollars!"<<endl;
                earnedmoney=earnedmoney+2;
            }
            else{
                cout<<"Incorrect. Try again... \n"<<endl;
            }
        }

        cout<<"Here's the next one.."<<endl;
        string answer2;
        string correct="0.25";
        string correct2="1/4";
        string correct3=".25";
        bool correctanswer=false;

        while(correctanswer != true){
            cout<<"What is the integral from 0 to 1 of x^3"<<endl;
            cin>>answer2;
            if(answer2 == correct or answer2==correct2 or answer2==correct3){
                cout<<"\n Correct! You earned 2 more dollars!\n"<<endl;
                earnedmoney=earnedmoney+2;
                correctanswer=true;

            }
            else{
                cout<<"Incorrect. Try again... \n"<<endl;
            }
        }

        string answer3;
        cout<<"For the jackpot of 10 dollars...\n"<<endl;
        cout<<"What is 10! (the factorial of 10)"<<endl;
        cin>>answer3;

        if(answer3 == "3628800"){
            earnedmoney=earnedmoney+20;
            cout<<"Correct! You have earned a grand total of "<<earnedmoney<<" dollars!\n"<<endl;
        }
        else if(answer3 != "3628800"){
            cout<<"Incorrect, yet you still earned "<<earnedmoney<< " dollars! \n"<<endl;
        }

        personalBalance=personalBalance+earnedmoney;
        getout=true;
    }
}

void Mailman::chooseRandomGame(){
    int randomint=rand()%4;
    if (randomint==1){
        earnMoney1();
    }
    else if(randomint==2){
        earnMoney2();
    }
    else{
        earnMoney3();
    }
}
