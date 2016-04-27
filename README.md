# Hustrulid_CSCI2270_FinalProject

PROJECT SUMMARY

  This project functions as an addition to the Communication Network (Assignment4 in CSCI 2270). The program acts as a menu style program, similar to the previous Assignments throughout the semester. Some of the changes/additions include...
    ->Instead of only being able to transmit messages across the coast, the user is able to transmit messages to specific cities of the users interest.
    -> The user has an initial personal balance of $20 to send messages with. Every city that must pass/send a message charges $1. However, the cities do not charge for recieved messages. These cities collect this money from the personal balance and record it in their city balance. If the user does not have enough money to send the message, the message will not be sent. If the user runs out of money, they are able to earn more money by playing random games.
    ->The user can see if he/she can send the message to a particular city by checking the cost to send a message to the particular city. That way, if the user does not want to earn more money and just spend it all, he can do so by first checking the cost of sending the message to a specific city.
  The menu options include...
    1. Build Network: This method imports a linked list containing cities. The linked list is represented as the following,
                NULL <- Los Angeles <-> Phoenix <-> Denver <-> Dallas <-> St.Louis <-> Chicago <-> Atlanta <-> Washington, D.C. <-> New York <-> Boston -> NULL
        The method is REQUIRED for any other operation. Calling the other methods except for exit and check personal balance will result in an error message.
    2. Print Network Path: This method prints the linked list after is has been created. This print looks very similar to the     build network example shown above. However, It will show changes in newly added or deleted cities.
    3. Transmit Message Coast-to-Coast: This method sends a message through the entire linked list, given that the user has     sufficient funds to do so.
    4. Transmit Message to Specific City: This method sends a message through the linked list to a specific city, given        that the user has sufficient funds to do so and the city exists. The message will not be passed any further than       the specified city.
    5. Check Cost to Transmit Message: This method checks the cost of sending a message to any city in the linked list.
    6. Add City: This method adds another node to the linked list. All that is required is the name of the new city and the     city that it will be placed in front of.
    7. Delete City: This method deletes a city from the linked list given a city name.
    8. Clear Network: This method deletes the entire linked list of cities.
    9. Display Personal Balance: This method simply prints the users current balance.
    10. Print City Balance: This method prints how much the city has earned by mailing messages to other cities.
    11. Earn More Money: This option allows for the user to make more money to send more messages. In other words, this        options allows for the program to continue running without closing it.

HOW TO RUN
  In order to run this program, download the individual files inside the Phase2.zip file named...
    Mailman.cpp
    Mailman.h
    main.cpp

  After downloading these three files, use any C++ application to build and run the main.cpp file. To ensure a the prgram is functioning properly, make sure the three files are all in the same directory so they are able to access eachother.The program does NOT require any command line arguments or additional read in files. This means the only requirements are the 2 cpp files, the header file, and a c++ application such as xcode or code blocks, in order to run the program. After the program is running, The user will be prompted with a menu that will look like the following.

   ======Main Menu======
  1. Build Network
  2. Print Network Path
  3. Transmit Message Coast-To-Coast-To-Coast
  4. Transmit Message To Specific City
  5. Check Cost to Transmit Message
  6. Add City
  7. Delete City
  8. Clear Network
  9. Display Personal Balance
  10. Print City Balance
  11. Earn More Money
  12. Quit

  The user will then type in a number corresponding to the desired action in the menu. For example, the User will want to build the network before preforming other operations. to do this, they will type in '1' , followed by pressing the return key on the keyboard. The menu will reprint after each method has finished and the user can choose the next option. The User can then send messages, add or delete cities, and check balance on cities or previous actions. Final messages from each method will be printed above the menu after they execute. For example, if the user wants to check how much Denver has made by their mailing system after transmiting a message coast-to-coast, by choosing 10, the following will display...

  Please enter a city name:
  Denver
  City:Denver
  Balance: 1 dollar(s).
  ======Main Menu======
  1. Build Network
  2. Print Network Path
  3. Transmit Message Coast-To-Coast-To-Coast
  4. Transmit Message To Specific City
  5. Check Cost to Transmit Message
  6. Add City
  7. Delete City
  8. Clear Network
  9. Display Personal Balance
  10. Print City Balance
  11. Earn More Money
  12. Quit

DEPENDENCIES
  No Third Party libraries are required for this program to run. Only the standard Library, and vector Library.

SYSTEM REQUIREMENTS:
  No other requirements are needed other than a C++ application for building and running the program.

GROUP MEMBERS:
  Tristan Hustrulid

CONTRIBUTORS:
  Jake Ursetta

OPEN BUGS/ISSUES:
  As of 4/27/16...When the user wants to earn more money, one of the options for earning more money has a bug. After the user plays the guessing game and earns more money, the user has to press enter and enter only to continue the program. If the user enters a character or anything else other than pressing enter, the system will print two menus. Other than that single bug, there are not any other bugs reported.

