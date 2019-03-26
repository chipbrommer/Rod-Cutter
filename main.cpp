/***************************************************************************************************
 *
 * Author: Chip Brommer
 * Date: March 25, 2019
 * Contact: Fredrick.Brommer@usm.edu
 * Class: CSC 413 - Algorithms
 * Professor: Dr. Zhou
 *
 * Description: Using textbook page 360, implement a greedy search algorithm to solve rod cutting.
                Use the price list in your textbook.
                Test 1-10 and see if you can get the same results as in your book.
                Implement either a top-down or bottom-up version.
 
 ***************************************************************************************************/

#include <iomanip>
#include <iostream>

using namespace std;

void welcomeMessage();
void mainWorker();
int rodCutter(int[], int);
void runAgain();
void programEnd();



int main()
{
    welcomeMessage();   //Calling the welcome message
    
    mainWorker();       //Handing off to the worker function.
}

//-------------------------------------------------------------------------------------------------
//welcomeMessage - This function holds the welcome message for the program and prints it to the
//                 console for the user.
//-------------------------------------------------------------------------------------------------
void welcomeMessage()
{
    cout << "\t\t\t\t\tChips Rod Cutting Project\n"
    << "\t\t------------------------------------------\n\n";
    cout << "\tThis program will well you the max price available from a rod.\n";
    cout << "\tThe rod must be between the length of 0-10.\n\n";

}

//-------------------------------------------------------------------------------------------------
//mainWorker - This function reieves the rod length from the user and calls the rodCutter.
//             It is seperated from main so we can use the runAgain function effectively.
//-------------------------------------------------------------------------------------------------
void mainWorker()
{
    //Using the price from the textbook, creating array with the information
    int price[] = {0,1,5,8,9,10,17,17,20,24,30};   //This will be P sub i
    
    //Variable to hold the length of our rod that will be cut.
    int rod = -1;
    
    //Variable to hold our max profit from the rod length
    int maxPrice = -1;
    
    //Allowing the user to input the length of the rod, making sure its between length of 0-10
    while (rod < 0 || rod > 10)
    {
        cout << "Enter the length of the rod to be cut: ";
        cin >> rod;
    }
    
    //Calling the rod cutter algorithm and sending it the price list with the length of the rod.
    maxPrice = rodCutter(price, rod);
    
    //Displaying the information to the user.
    printf("\n\nMaximum Price for %dft rod is %d\n", rod, maxPrice);
    
    runAgain();
}

//-------------------------------------------------------------------------------------------------
//rodCutter - This function recieves the length of a rod and will find the most valuable way to
//            cut the rod for the max profit.
//-------------------------------------------------------------------------------------------------
int rodCutter(int price[], int rod)
{
    //Default case
    if (rod == 0)
    {
        return price[0];
    }
    
    //Creating a variable to hold the max price.
    int maxPrice = -1;
    
    //for loop to find the max price we can get from the rod.
    for (int x = 1; x <= rod; x++)
    {
        //Creating a variable to hold the temp price for how much money we could make.
        //Setting it equal to the price of the current size of the rod plus a recursive call
        //to the rod cutter again. to see if the length needs to be cut again for max price
        int tempPrice = price[x] + rodCutter(price, rod-x);
        
        //If the temp price is more than the maxPrice, over write the max price.
        if (tempPrice > maxPrice)
        {
            maxPrice = tempPrice;
        }
    }
    
    //returning the max price.
    return maxPrice;
}

//---------------------------------------------------------------------------------------
//runAgain - Asks the user if they'd like to run again. If yes, send to mainWorker function
//---------------------------------------------------------------------------------------
void runAgain()
{
    char userSelection;     //Holds the user selection
    
    cout << "\nWould you like to try another rod size?\n";
    cout << "Enter Y for Yes, Else ends program.\n";
    cout << "\tUser Input: ";
    cin >> userSelection;
    
    //converts to char input to an upper character and compares it,
    //if the input was a 'Y' then sends back to the worker function
    if(toupper(userSelection) == 'Y')
    {
        cout << endl;
        mainWorker();
    }
    else //input was not a 'Y' , defaults to program end function
    {
        programEnd();
    }
}

//-------------------------------------------------------------------------------------------------
//programEnd - Prompts the user to enter any key to close the program, then ends the program.
//-------------------------------------------------------------------------------------------------
void programEnd()
{
    cout << "\nPress any key to end...\n";
    cin.get();
    exit(0);
}
