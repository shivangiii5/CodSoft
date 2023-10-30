#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

///Initialize the board

void initialize(char board[3][3]) {
    char k='1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = k;
            k++;
        }
    }
}

///Display current status of the board

void display(char board[3][3]){

    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" "<<endl;
    cout<<"\t\t     |     |     "<<endl;

}

///Get player input

bool play_turn(char board[3][3], char turn){

    int row,column,choice;

    if(turn == 'X'){
        cout<<endl<<"\tPlayer 1's turn : ";
    }
    else if(turn == 'O'){
        cout<<endl<<"\tPlayer 2's turn : ";
    }

    cin>>choice;
    cout<<endl<<endl;

    switch(choice){

    case 1:
        row=0;
        column=0;
        break;

    case 2:
        row=0;
        column=1;
        break;

    case 3:
        row=0;
        column=2;
        break;

    case 4:
        row=1;
        column=0;
        break;

    case 5:
        row=1;
        column=1;
        break;

    case 6:
        row=1;
        column=2;
        break;

    case 7:
        row=2;
        column=0;
        break;

    case 8:
        row=2;
        column=1;
        break;

    case 9:
        row=2;
        column=2;
        break;
    }


    if(choice<1 || choice>9 || board[row][column]=='X' || board[row][column]=='O'){
        cout<<"Invalid Move, enter again"<<endl<<endl;
        return false;
    }

    board[row][column]=turn;
    return true;

}

///Check for win

bool win(char board[3][3]){

    //Horizontal or Vertical win
    for(int i=0;i<3;i++){
        if( (board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i] == board[1][i] && board[0][i] == board[2][i]) ){
            return true;
        }
    }

    //Diagonal Win
    if( (board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]) ){
        return true;
    }


    return false;

}

/// Check for Draw

bool draw(char board[3][3]){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!='X' && board[i][j]!='O'){
                return false;
            }
        }
    }

    return true;

}
int main(){

    char ch;
    cout<<"\t\t\tT I C - T A C - T O E  G A M E\t\t\t"<<endl;
    cout<<"\t\t\t\tFor 2 Players\t\t\t"<<endl<<endl;
    cout<<"\tPlayer 1 = X\t Player 2 = O"<<endl<<endl<<endl;


    do{

        char board[3][3];
        initialize(board);
        char turn='X';
        bool gameover=false;


        while(!gameover){
            display(board);

            if(play_turn(board, turn)){
                if(win(board)){
                    display(board);
                    if(turn=='X'){
                        cout<<endl<<"\tCongratulations! Player 1 has won the game"<<endl<<endl;
                    }
                    else{
                        cout<<endl<<"\tCongratulations! Player 2 has won the game"<<endl<<endl;
                    }
                    gameover = true;
                }
                else if(draw(board)){
                    display(board);
                    cout<<endl<<"\tGame draw!"<<endl<<endl;
                    gameover = true;
                }
                else{
                    turn = (turn == 'X') ? 'O' : 'X';
                }
            }
        }


        cout<<"\tDo you want to play again? (y/n): ";
        cin>>ch;
        cout<<endl<<endl<<endl;

    }while(ch=='y' || ch=='Y');


}
