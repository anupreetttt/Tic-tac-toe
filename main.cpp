#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>

using namespace std;

char board[9] = {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '};
void showBoard();
void player1();
void player2();
void computerChoice();
int countBoard(char symbol);
char checkWinner();
void vsComputer();
void vsPlayer();

int main(){
    int mode;
    cout << "1) Computer VS Player. " << endl;
    cout << "2) Player VS Player. " << endl;
    cout << "Select game mode: " << endl;
    cin >> mode;
    
    switch (mode) {
        case 1:
            vsComputer();
            break;
        case 2:
            vsPlayer();
            
        default:
            cout << "Please select 1 or 2." << endl;
            break;
    }

    return 0;
}

void computerChoice(){
    
    srand(time(0));
    int choice;
    
    do{
        choice = rand()%9;
        
    }while(board[choice] != ' ');
    board[choice] = 'O';

}

void vsComputer(){
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    while(true){
        showBoard();
        if(countBoard('X') == countBoard('O')){
            cout << playerName << " 's turn. " << endl;
            player1();
        } else{
            computerChoice();
        }
        char winner = checkWinner();
        if(winner == 'X'){
            showBoard();
            cout << playerName << " Won the game." << endl;
            break;
        }
        else if (winner == 'O'){
            showBoard();
            cout << "Computer won the game." << endl;
            break;
        }
        else if(winner == 'D') {
            cout << " The game is draw." << endl;
            break;
        }
    }
}
    
void player1(){
    while (true) {
        cout << "Select a number from (1-9): " << endl;
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8) {
            cout << "Invalid! Please select a number from (0-8)" << endl;
        }
        else if(board[choice] != ' ') {
                cout << "Please select an empty position" << endl;
            }
        else {
            board[choice] = 'X';
            break;
        }
        
    }
    
}


void player2(){
    while (true) {
        cout << "Select a number from (0-8): " << endl;
        int choice;
        cin >> choice;
        choice--;
        if (choice <0 || choice > 8) {
            cout << "Invalid! Please select a number from (0-8)" << endl;
        }
        else if(board[choice] != ' ') {
                cout << "Please select an empty position" << endl;
            }
        else {
            board[choice] = 'O';
            break;
        }
        
    }
    
}

void vsPlayer(){
    string getPlayer1, getPlayer2;
    cout << "Enter first player name: ";
    cin >> getPlayer1;
    
    cout << "Enter second player name: ";
    cin >> getPlayer2;
    
    while(true){
        showBoard();
        if(countBoard('X') == countBoard('O')){
            cout << getPlayer1 << " 's turn.'" << endl;
            player1();
        }
        else{
            cout << getPlayer2 << " 's turn.'" << endl;
            player2();
        }
        char winner =  checkWinner();
        if (winner == 'X') {
            system("clear");
            showBoard();
            cout << getPlayer1 << " Won the game." << endl;
            break;
        }
        else if(winner == 'O'){
            showBoard();
            cout << getPlayer2 << " Won the game." << endl;
            break;
        }
        else if(winner == 'D'){
            showBoard();
            cout << "Game is Draw " << endl;
            break;
        }
    }
}

int countBoard(char symbol){
   
    int total = 0;
    for(int i = 0;  i < 9; i++){
        if (board[i] ==  symbol) {
            total += 1;
        }
    }
    return total;
}

char checkWinner(){
    // win conditon horizontally
    if(board[0] == board[1] && board[1] ==  board[2] && board[0] != ' ')
        return board[0];
    if(board[3] == board[4] && board[4] ==  board[5] && board[3] != ' ')
        return board[3];
    if(board[6] == board[7] && board[7] ==  board[8] && board[6] != ' ')
        return board[6];
    // win conditon vertically
    
    if(board[0] == board[3] && board[3] ==  board[6] && board[0] != ' ')
        return board[0];
    if(board[1] == board[4] && board[4] ==  board[7] && board[1] != ' ')
        return board[1];
    if(board[2] == board[5] && board[5] ==  board[8] && board[2] != ' ')
        return board[2];

    // win conditon diagonally
    if(board[0] == board[4] && board[4] ==  board[8] && board[0] != ' ')
        return board[0];
    if(board[2] == board[4] && board[4] ==  board[6] && board[2] != ' ')
            return board[2]; //doubt
    
    if(countBoard('X') + countBoard('O') < 9)
        return 'C';
    else{
        return 'D';
        }
}

void showBoard(){
    
    cout << "   "  << "   |   " << "    |   " << endl;
    cout << "   "  << board[0] << "  |   " << board[1] << "   |   "<<  board[2] << endl;
    cout << "   "  << "   |   " << "    |   " << endl;
    cout << "-----------------------" << endl;
    cout << "   "  << "   |   " << "    |   " << endl;
    cout << "   "  << board[3] << "  |   " << board[4] << "   |   "<<  board[5] << endl;
    cout << "   "  << "   |   " << "    |   " << endl;
    cout << "-----------------------" << endl;
    cout << "   "  << "   |   " << "    |   " << endl;
    cout << "   "  << board[6] << "  |   " << board[7] << "   |   "<<  board[8] << endl;
    cout << "   "  << "   |   " << "    |   " << endl;

    
}
