#include "gameLib.h"
#include<typeinfo>

int main(int argc, char* argv[])
{

    gameWorld board;
    int player = 1;
    char choice, play;
    char playerSymbol = chrArry[NINE];
    bool blnContinue = true;
    int win = ONE;

  while(blnContinue)
  {
    do
    {
        system("clear");
        board.showWorld();
        player = (player%2)? 1: 2;
        playerSymbol = (player == 1)?chrArry[TEN]:
                                        chrArry[LEVEN];

        cout << "\n\n\t\t  **Q to Exit**" << endl;
        cout << "\n\t\tPlayer " << player << " choice: ";
        cin >> choice;
        if(choice == 'Q' ||  choice == 'q')
        {
            cout << "\n\tThank you for playing with us!!!" << endl << endl;
            return 0;
        }
        board.move(choice,playerSymbol,player,board);
        win = board.win();

        ///increament player
        player++;

    }while(win == ONE);
    
    if(win == 1)
    {
        system("clear");
        board.showWorld();
        cout << "\n\t\t Player " << player-1 << " has won" 
         << endl;

        cout << "\n\n Do you want to contine playing[Y/n]: " ;
    }

    if(win == 2)
    {

        cout << "\n\t\t ended in draw " 
         << endl;

        cout << "\n\n Do you want to re-match[Y/n]: " ;
    }

    cin.ignore(100,'\n');
    cin >> play;

    if(play == 'y' || play == 'Y')
    {

        board.reset();
        player =1;
       
    }
    else
    {
        blnContinue = !blnContinue;
        cout << "\n\n Thank you for Playing with us!!" <<
        endl;
    }
    
  }


    return 0;
}