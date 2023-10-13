#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
    
    //to get each from the 5x5 matrix vending machine
    double price[5][5];
    string name[5][5];
    int quantity[5][5];
    int i,j;
    char letter;
    string uInput;
    int row = 0;
    int column = 0;
    double dollars = 20;
    double quarters = 40;
    double dimes = 100;
    double nickels = 200;
    double userDollars;
    double userQuarters;
    double userDimes;
    double userNickels;
    double userTotal;
    double userChange;
    string restart;
    string choice;
    ifstream inFile;
    //inFile.open("vending.dat");

void printMenu()
{
   
//headings 
    //restart = "Y";
   // while((restart=="y")||(restart =="Y"))
    //{
        //how it looks
       // cout<<fixed<<setw(40)<<"Item"<<setw(35)<<"Quanity"<<setw(27)<<"Price"<<endl;
       // cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
    //controls the number per row
    char rows[5] = {'A','B','C','D','E'};
        for(i =0;i<5;i++)
        {
            //cout<<endl;

            for(j=0;j<5;j++)//number per column
            {
                //read the info from the file to computer
               
                cout<< setw(41)<<name[i][j]<<" ";
                
                cout<< setw(27)<<quantity[i][j]<<" ";
                
                cout<<"(" << rows[i] << "," << j << ") " << setw(25)<<price[i][j]<<" "<< endl;
            }
        }
        cout<< endl;
   // }
   
    //std::cout<< endl;

}
int menu()
    {
    //ifstream inFile;
    //inFile.open("vending.dat");
//headings 
//restart
    restart = "Y";
    while((restart=="y")||(restart =="Y"))
    {
        //what it looks like
    cout<<fixed<<setw(40)<<"Item"<<setw(35)<<"Quanity"<<setw(27)<<"Price"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
   //controls the number per row
   //call menu
    printMenu();

    cout<< endl;

    cout<< "Please enter a row: ";
    getline(cin, uInput);
//change numbers to letters for vending input
    if((uInput=="A")||(uInput =="a"))
        {
            row= 0;
        }
        else if((uInput =="B")||(uInput =="b"))
        {
            row = 1;
        }
        else if((uInput =="C")||(uInput =="c"))
        {
            row =2;
        }
        else if((uInput=="D")||(uInput =="d"))
        {
            row = 3;
        }
        else
        {
            row =4;
        }
    //row = stoi(uInput);
    cout<<endl;

    cout<< "Please enter a column: ";
    getline(cin, uInput);
    //converts a string to an integer value
    column = stoi(uInput);
    cout<<endl;
//if they want to quit or enter anther choice
    while((row>4) || (column>4))
    {
        cout<<"You can't do that. Press Q to quit. Press C to continue. ";
        getline(cin, uInput);
        choice = uInput;

        if((choice == "Q")||(choice == "q"))
        {
            return 0;
        }
        else
        {
        cout<< "Please enter a row: ";
        getline(cin, uInput);

        if((uInput=="A")||(uInput =="a"))
        {
            row= 0;
        }
        else if((uInput =="B")||(uInput =="b"))
        {
            row = 1;
        }
        else if((uInput =="C")||(uInput =="c"))
        {
            row =2;
        }
        else if((uInput=="D")||(uInput =="d"))
        {
            row = 3;
        }
        else
        {
            row =4;
        }

        //row = stoi(uInput);
        //std::cin>>row;
        cout<<endl;

        cout<< "Please enter a column: ";
        getline(cin, uInput);
        //converts a string to an integer value
        column = stoi(uInput);
        //std::cin>> column;
        cout<<endl;
        }
    }
    //enter money for vending
    cout<< "You chose "<< name[row][column]<<", which is $"<<price[row][column]<<endl;

    cout<<"Please enter the amount of dollars(if any or enter q to cancel): "<<endl;
    getline(cin, uInput);
    if(uInput=="q")
    {
        cout<<"Money returned: $0.00"<<endl;
        return 0;
    }
    else
    {
        //converts a string into a floating point value
        userDollars = stod(uInput);
        //std::cin>>userDollars;
        dollars+=userDollars;
    }
    
    cout<< "Please enter the amount of quarters(if any or enter q to cancel): "<<endl;
    getline(cin, uInput);
    if(uInput=="q")
    {
        cout<<"Money returned: $"<<(userDollars*1)<<endl;
        dollars-=userDollars;
        return 0;
    }
    else
    {
        //converts a string into a floating point value, then returned as a value of type double
        userQuarters = stod(uInput);
        //std::cin>>userQuarters;
        quarters+=userQuarters;
    }

    cout<< "Please enter the amount of dimes(if any or enter q to cancel): "<<endl;
    getline(cin, uInput);
    if(uInput=="q")
    {
        cout<<"Money returned: $"<<(userDollars*1)+(userQuarters*.25)<<endl;
        dollars-=userDollars;
        quarters-=userQuarters;
        return 0;
    }
    else
    {
        //converts a string into a floating point value, then returned as a value of type double
        userDimes = stod(uInput);
        //std::cin>>userDimes;
        dimes+=userDimes;
    }

    cout<< "Please enter the amount of nickels(if any or enter q to cancel): "<<endl;
    getline(cin, uInput);
    if(uInput=="q")
    {
        cout<<"Money returned: $"<<(userDollars*1)+(userQuarters*.25)+(userDimes*.10)<<endl;
        dollars-=userDollars;
        quarters-=userQuarters;
        dimes-=userDimes;
        return 0;
    }
    else
    {
        //converts a string into a floating point value, then returned as a value of type double
        userNickels= stod(uInput);
        //std::cin>>userNickels;
        nickels+=userNickels;
    }

    userTotal  = (userDollars*1)+ (userQuarters*.25)+(userDimes*.10)+(userNickels*.05);

    cout<<"You entered $"<< userTotal<<endl;
    //if there isnt enough funds it will keep going until enough money is given
    while(userTotal<price[row][column])
    {
        cout<<"error not enough funds to buy item, please put in the rest of the money needed.\n";

        cout<<"Please enter the amount of dollars(if any): "<<endl;
        getline(cin, uInput);
        //converts a string into a floating point value, then returned as a value of type double
        userDollars = stod(uInput);
        //std::cin>>userDollars;
        dollars+=userDollars;

        cout<< "Please enter the amount of quarters(if any): "<<endl;
        getline(cin, uInput);
        //converts a string into a floating point value, then returned as a value of type double
        userQuarters = stod(uInput);
        //std::cin>>userQuarters;
        quarters+=userQuarters;

        cout<< "Please enter the amount of dimes(if any): "<<endl;
        getline(cin, uInput);
        //converts a string into a floating point value, then returned as a value of type double
        userDimes = stod(uInput);
        //std::cin>>userDimes;
        dimes+=userDimes;

        cout<< "Please enter the amount of nickels(if any): "<<endl;
        getline(cin, uInput);
        //converts a string into a floating point value, then returned as a value of type double
        userNickels= stod(uInput);
        //std::cin>>userNickels;
        nickels+=userNickels;

        userTotal  = userTotal + (userDollars*1)+ (userQuarters*.25)+(userDimes*.10)+(userNickels*.05);

        cout<<"You entered $"<< userTotal<<endl;
        

    }
    

    
//change
    userChange = userTotal-price[row][column];

    cout<<"Your change is: $"<<userChange<<endl;

    while(userChange > 0)
    {
        userChange = floor(userChange * 100.0) / 100.0;
        //cout<<fixed<<setprecision(30);
        if(userChange >= 1.00)
        {
            userChange -= 1;
            dollars -= 1;
            //std::cout<<"userchange is : $"<<userChange;
        }
        else if(userChange >= .25)
        {
            userChange -= .25;
            quarters -= 1;
            //std::cout<<"userchange is : $"<<userChange;
        }
        else if(userChange >= .10)
        {
            userChange -=.10;
            dimes -=1;
            //std::cout<<"userchange is : $"<<userChange;
        }
        else
        {
            userChange -=.05;
            nickels -=1;
            //std::cout<<"userchange is : $"<<userChange;
        }
        
    }
    

    quantity[row][column]-=1;
    cout<<"Do you want to select again? (Press Y to select another item or press Q to quit.): \n";
    getline(cin, restart);
    }
    
    

    
    //dollars = dollars + uservalue
/*
    for (int i =0; i<5;i++)
    {
        for (j = 0;j<5;j++)
        {
            inFile>>name[i][j];

            switch(i)
            {

                case 0:
                cout<<"A"<<j<<setw(40)<<name[i][j]<<" ";
                break;
                case 1:
                cout<< "B"<<j<<setw(40)<<name[i][j]<<" ";
                break;
                case 2:
                cout<< "C"<<j<<setw(40)<<name[i][j]<<" ";
                break;
                case 3:
                cout<< "D"<<j<<setw(40)<<name[i][j]<<" ";
                break;
                case 4:
                cout<< "E"<<j<<setw(40)<<name[i][j]<<" ";
                break;
                case 5:
                cout<< "F"<<j<<setw(40)<<name[i][j]<<" ";
                break;
                case 6:
                default:
                cout<<"not an option";
                break;

            }


        }
    } 

    cout<< endl;
    cout<< "Please select an item: ";
    cin>> letter >> column;
    cout<<endl;
    if (letter == 'A'|| letter =='a' )
    {
        row = 0;
    }
    else if(letter =='B' || letter=='b')
    {
        row = 1;
    }
    else if(letter =='C' || letter=='c')
    {
        row = 2;
    }
    else if(letter =='D' || letter=='d')
    {
        row = 3;
    }
    else if(letter =='E' || letter=='e')
    {
        row = 4;
    }
    else
    {
        cout<< "You cant choose what you have selection.";
        return 0;
    }
    cout<< " item: "<<name[row][column]<<endl;
    cout<< "Price: $"<<price[row][column]<<endl;
    
    */
    
    
    
    
    return 0;
    }


void maintenance()
{
    string userInput;
    int userChoice;
    int userQuantity;
//which maintence they want to check, change
    cout<<"Select 1 for inventory"<<endl;
    cout<< "Select 2 for currency"<<endl;
    getline(cin,userInput);
    userChoice = stoi(userInput);

    //refill inventory
    switch(userChoice)
    {
        case 1:
        printMenu();
        cout<<"Which item do you want to refill?: "<<endl;
        cout<< "Enter a row: "<<endl;
        getline(cin,userInput);

        if(userInput=="A")
        {
            row= 0;
        }
        else if(userInput =="B")
        {
            row = 1;
        }
        else if(userInput =="C")
        {
            row =2;
        }
        else if(userInput=="D")
        {
            row = 3;
        }
        else
        {
            row =4;
        }
        //row=stoi(userInput);

        cout<<"Enter a column: "<<endl;
        getline(cin,userInput);
        column=stoi(userInput);

        cout<<"How many?: "<<endl;
        getline(cin,userInput);
        userQuantity= stoi(userInput);

        quantity[row][column]+=userQuantity;
        printMenu();
        cout<<"Item has been refilled."<<endl;
        cout<<endl;
        break;
//refill cash inventory
        case 2:
        double total = (dollars*1)+ (quarters*.25)+(dimes * .10)+(nickels * .05);
        cout<<"before currency replenishment"<<endl;
        cout<<"dollars: "<<dollars<<endl;
        cout<<"quarters:  "<<quarters<<endl;
        cout<<"dimes: "<<dimes<<endl;
        cout<<"nickels: "<<nickels<<endl;
        cout<<"Total: "<<total<<endl;

        dollars = 20;
        quarters = 40;
        dimes = 100;
        nickels = 200;

        total = (dollars*1)+ (quarters*.25)+(dimes * .10)+(nickels * .05);
        cout<<"after currenecy replenishment"<<endl;
        cout<<"dollars: "<<dollars<<endl;
        cout<<"quarters:  "<<quarters<<endl;
        cout<<"dimes: "<<dimes<<endl;
        cout<<"nickels: "<<nickels<<endl;
        cout<<"Total: "<<total<<endl;
        cout<<endl;

        break;
    }
}

int main()
{
    inFile.open("vending.dat");
    //string rows[5]= "ABCDE";

    for(i =0;i<5;i++)
    {
        //cout<<endl;

        for(j=0;j<5;j++)//number per column
        {
            //read the info from the file to computer
            inFile>>name[i][j];
            //std::cout<< "(" << i << "," << j << ") " << setw(37)<<name[i][j]<<" ";
            inFile>>quantity[i][j];
            //std::cout<<"(" << i << "," << j << ") " << setw(20)<<quantity[i][j]<<" ";
            inFile>>price[i][j];
            //std::cout<<"(" << i << "," << j << ") " << setw(25)<<price[i][j]<<" "<< endl;
        }
    }

    //get variable for name of food
    //get variable for quantity of food
    //get variable for price of food
//open data file
    
    int userChoice;
    string userInput;
    bool quitProgram = false;
//select what you want to do
    while(quitProgram==false)
    {
        cout<< "Select one of the following:"<<endl;
        cout<<"1: Menu of Items"<<endl;
        cout<<"2: Maintenance"<<endl;
        cout<<"3: Quit Program"<<endl;

        getline(cin,userInput);
        userChoice = stoi(userInput);
        cout<< fixed<<setprecision(2);
        
        switch(userChoice)
        {
            case 1:
            menu();
            break;
            case 2:
            maintenance();
            break;
            case 3:
            quitProgram = true;
            break;
        }
    }

    inFile.close();

    return 0;
}