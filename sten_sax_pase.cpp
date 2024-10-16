#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>



using namespace std;



bool game()
{
    srand(time(0));

    string user_input; 
    string pc_answ;

    int pc_score = 0;
    int player_score = 0;

    while(pc_score < 3 && player_score < 3)
    {
        // PC RANDOM CHOICE
        int rand_num = rand() % 3;
        if(rand_num == 0)
        {
            pc_answ = "ROCK";
        }
        else if(rand_num == 1)
        {
            pc_answ = "SCISSOR";
        }
        else
        {
            pc_answ = "PAPER";
        }

        // CHECK WHO WON 
        cout << "\nROCK, SCISSOR OR PAPER? "; cin >> user_input;

        if(user_input == "ROCK" && pc_answ == "PAPER")
        {
            cout << "You lost!\n";
            pc_score++;
        }
        else if (user_input == "PAPER" && pc_answ == "SCISSOR")
        {
            cout << "You lost!\n";
            pc_score++;
        }
        else if (user_input == "SCISSOR" && pc_answ == "ROCK")
        {
            cout << "You lost!\n";
            pc_score++;
        }
        else if (user_input == pc_answ)
        {
            cout << "It's a tie!\n";
        }
        else
        {
            cout << "You won!\n";
            player_score++;
        }
        cout << "Player score: " << player_score << "\n";
        cout << "Computer score: " << pc_score << "\n";
        
    }

    cout << "\nFINAL SCORE:\n";
    cout << "Player score: " << player_score << "\n";
    cout << "Computer score: " << pc_score << "\n";

    // WHO WON
    return player_score == 3;
    
    

}


void statistics(int ptotal, int ctotal, int gplayed)
{
    cout << "\n---------STATISTICS----------\n";
    cout << "-----------------------------\n";
    cout << "Player wins: " << ptotal << "\n";
    cout << "Computer wins: " << ctotal << "\n";
    cout << "Games played: " << gplayed << "\n";
    cout << "-----------------------------\n";
       
}




int main(int argc, char const *argv[])
{
    
    int menu_answ;
    int player_total = 0;
    int pc_total = 0;
    int games_played = 0;

    while(true)
    {
        cout << "\n------------------------------";
        cout << "\nWELCOME TO ROCK PAPER SCISSOR!\n";
        cout << "------------------------------\n";
        cout << "NEW GAME (1)\n";
        cout << "SHOW STATISTICS (2)\n";
        cout << "QUIT (3)\n";
        cout << "------------------------------\n";
        
        cout << "What do you want to do?\n"; cin >> menu_answ;
        switch (menu_answ)
        {
        case 1:
            //game();
            if(game())
                player_total++;
            else
                pc_total++;
            games_played = player_total + pc_total;
            break;
        case 2:
            statistics(player_total, pc_total, games_played);
            break;
        case 3:
            cout << "Thank you for playing!\n";
            exit(0);
            
        default:
            cout << "Try again!\n";
        }
        
    }

    return 0;
}
