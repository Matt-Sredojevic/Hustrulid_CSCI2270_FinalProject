#include <iostream>
#include "Mailman.h"
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    // declare input and instance of class
    string input = "0";
    Mailman city1;

    // run through while loop for menu
    while(input != "12"){
        cout << "======Main Menu======" << endl;
        cout << "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
        cout << "4. Transmit Message To Specific City" << endl;
        cout << "5. Check Cost to Transmit Message " << endl;
        cout << "6. Add City" << endl;
        cout << "7. Delete City" << endl;
        cout << "8. Clear Network" << endl;
        cout << "9. Display Personal Balance" << endl;
        cout << "10. Print City Balance" << endl; //how much the city made from
        cout << "11. Earn More Money" << endl;
        cout << "12. Quit" << endl;

        //cin.get();
        getline(cin,input);




        // build network
        if(input == "1"){
        if(!city1.listBuilt()){
                city1.buildNetwork();
            }
            else{
                cout << "Please clear the network before re-building." << endl;
            }
        }

        // Print netowrk
        else if(input == "2"){
            if(city1.listBuilt()){
                city1.printNetwork();
            }
            else{
                std::cout << "Empty list, " << "Current Balance: " << city1.checkPersonalBalance() << std::endl;
            }
        }

        else if(input == "3"){
            if(city1.listBuilt()){
                string message;
                cout << "Please enter message to transmit accross the coast: " << endl;
                getline(cin,message);
                city1.transmitMsgCoast(message);
            }
            else{
                std::cout << "Empty list, " << "Current Balance: " << city1.checkPersonalBalance() << std::endl;
            }
        }

        else if (input == "4"){
            if(city1.listBuilt()){
                string message;
                string city;
                cout << "Please select a city to send a message to: " << endl;
                getline(cin,city);
                cout << "Please enter message to transmit: " << endl;
                getline(cin,message);
                city1.transmitMessagetoCity(city, message);
            }
            else{
                std::cout << "Empty list, " << "Current Balance: " << city1.checkPersonalBalance() << std::endl;
            }
        }


        else if (input == "5"){
            if(city1.listBuilt()){
                string city;
                cout << "Enter city to send a message to: " << endl;
                getline(cin,city);
                int cost = city1.checkCost(city);

                if(cost != 0) cout << "Cost to send message: " << city1.checkCost(city) << " dollar(s)."<<endl;
            }
            else{
                std::cout << "Empty list, " << "Current Balance: " << city1.checkPersonalBalance() << std::endl;
            }
        }

                // add city in command window
        else if(input == "6"){
            if(city1.listBuilt()){
                string cityNew;
                string cityPrevious;
                cout << "Enter a city name: " << endl;
                getline(cin,cityNew);
                cout << "Enter a previous city name: " << endl;
                getline(cin,cityPrevious);
                city1.addCity(cityPrevious, cityNew);
            }
            else{
                cout << "Please Build Network before adding cities." << endl;
            }

        }

        // delete city
        else if(input == "7"){
            if(city1.listBuilt()){
                string cityDelete;
                cout << "Enter a city name: " << endl;
                getline(cin,cityDelete);
                //cin >> cityDelete;
                city1.deleteCity(cityDelete);
            }
            else{
                std::cout << "Empty list, " << "Current Balance: " << city1.checkPersonalBalance() << std::endl;
            }

        }

        // Clear out network
        else if(input == "8"){
            if(city1.listBuilt()){
            city1.clearNetwork();
            }
            else{
                std::cout << "Empty list, " << "Current Balance: " << city1.checkPersonalBalance() << std::endl;
            }
        }

        else if (input == "9"){
            cout << "Personal Balance: " << city1.checkPersonalBalance() <<" dollar(s)."<< endl;
        }


        else if(input == "10"){
            if(city1.listBuilt()){
                cout << "Please enter a city name: " << endl;
                string name;
                getline(cin,name);
                city1.printCityInfo(name);
            }
            else{
                std::cout << "Empty list, " << "Current Balance: " << city1.checkPersonalBalance() <<" dollar(s)."<< std::endl;
            }
        }

        else if (input== "11"){
            city1.chooseRandomGame();
            cin.ignore();
        }

    }

    // leave program
    cout << "Goodbye!" << endl;

    return 0;
}
