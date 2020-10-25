#include<iostream>

using namespace std;

enum gameEntity
{
    ONE, TWO, THREE, FOUR, FIVE,
    SIX, SEVEN, EIGHT, NINE,TEN,
    LEVEN, 
};

char chrArry2[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9',};
                    
char chrArry[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9',
                    'O', 'X'};

///checking if the choice in the array
bool isValidChoice(char &choice)
{

    if (choice == 'O' || choice == 'X')
    {
        return false;
    }
    
    for(int i = 0; i< 9; i++)//char c: chrArry2)
    {
        
        if(chrArry[i]==choice)
        {
            return true;
        }
    }
    return false;
}



struct gameWorld
{   
    //this funtion draw and display the game world
    void showWorld()
    {
        cout << "\n\n\t\t   Tic Tac Toe" << endl;
        cout << "\t\t     |     |      \t\t " << endl;
        cout << "\t\t  "<< chrArry[ONE]<< "  |"
             << "  "<< chrArry[TWO]<< "  |"
             << "  "<< chrArry[THREE]<< "  " << endl;
        cout << "\t\t_____|_____|_____ \t\t " << endl;
        cout << "\t\t     |     |      \t\t " << endl;
        cout << "\t\t  "<< chrArry[FOUR]<< "  |"
             << "  "<< chrArry[FIVE]<< "  |"
             << "  "<< chrArry[SIX]<< "  " << endl;
        
        cout << "\t\t_____|_____|_____ \t\t " << endl;
        cout << "\t\t     |     |      \t\t " << endl;
        cout << "\t\t  "<< chrArry[SEVEN]<< "  |"
             << "  "<< chrArry[EIGHT]<< "  |"
             << "  "<< chrArry[NINE]<< "  " << endl;
        
        cout << "\t\t     |     |      \t\t " << endl;

    };


    //this function will reset the game

    void reset()
    {
        for(int i = 0; i < 9; i ++ )
        {
            chrArry[i] = chrArry2[i];
        }
    }

    //this function will modify the game world
    //and check if the continues or not
    /* wim will return:
         1 - game over and there is a winner
         2 - game over and there is no winner
         0 - game still continues 

    */

   int win()
   {

       if(chrArry[ONE] == chrArry[TWO] && 
            chrArry[TWO] == chrArry[THREE])
            {return 1;};

       if((chrArry[FOUR] == chrArry[FIVE]) && 
            (chrArry[FIVE] == chrArry[SIX]))
            {return 1;};

       if(chrArry[SEVEN] == chrArry[EIGHT] && 
            chrArry[EIGHT] == chrArry[NINE])
            {return 1;};
            
       if(chrArry[ONE] == chrArry[FOUR] && 
            chrArry[FOUR] == chrArry[SEVEN])
            {return 1;};

       if(chrArry[TWO] == chrArry[FIVE] && 
            chrArry[FIVE] == chrArry[EIGHT])
            {return 1;};

       if(chrArry[THREE] == chrArry[SIX] && 
            chrArry[SIX] == chrArry[NINE])
            {return 1;};

       if(chrArry[ONE] == chrArry[FIVE] && 
            chrArry[FIVE] == chrArry[NINE])
            {return 1;};

       if(chrArry[THREE] == chrArry[FIVE] && 
            chrArry[FIVE] == chrArry[SEVEN])
            {return 1;};


    int counter = 0;

    for(int i = 0; i < 9;i++)
    {
        if(chrArry[i] == 'O' || chrArry[i] == 'X')
        {
            counter ++;
        }
    }
    
    if(counter == 9)
    {
        return 2;
    }
     else
     {
         return 0;
     }
   }

//this function will keep on checking the untill is valid
char enforceChoice(char choice, int & player, gameWorld &board)
{
    while(!isValidChoice(choice))
    {
        cin.ignore(100, '\n');
        system("clear");
        board.showWorld();
        cout << "\n\nPlayer " << player 
             << " Choose a valid choice: ";
        cin >> choice;

    }
    return choice;
}

    //this function will take in a choice and put the player 
    //symbol in to the game 
    void move(char &choice, char playerSymbol, int player,
            gameWorld board)
    {
        //ensuring that choice is not equal to player symbol
        if(enforceChoice(choice,player, board))
        {
            if(choice == chrArry[ONE])
            {
                chrArry[ONE] = playerSymbol;
            }
            if(choice == chrArry[TWO])
            {
                chrArry[TWO] = playerSymbol;
            }
            if(choice == chrArry[THREE])
            {
                chrArry[THREE] = playerSymbol;
            }
            if(choice == chrArry[FOUR])
            {
                chrArry[FOUR] = playerSymbol;
            }
            if(choice == chrArry[FIVE])
            {
                chrArry[FIVE] = playerSymbol;
            }
            if(choice == chrArry[SIX])
            {
                chrArry[SIX] = playerSymbol;
            }
            if(choice == chrArry[SEVEN])
            {
                chrArry[SEVEN] = playerSymbol;
            }
            if(choice == chrArry[EIGHT])
            {
                chrArry[EIGHT] = playerSymbol;
            }
            if(choice == chrArry[NINE])
            {
                chrArry[NINE] = playerSymbol;
            }
        }
    }

};


