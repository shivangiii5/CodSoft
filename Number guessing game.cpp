#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){

    srand(time(0));

    int num=rand()%100+1;
    int guess=0;
    int attempts=0;

    while(true){

        cout<<"\tGuess a number between 1 and 100: ";
        cin>>guess;
        attempts++;

        if(guess==num){
            cout<<"\tYou guessed the correct number i.e. "<<num<<" in "<<attempts<<" attempts."<<endl;
            break;
        }
        else if(guess<num){
            cout<<"\tYour guess is too low. Try again."<<endl<<endl;
        }
        else{
            cout<<"\tYour guess is too high. Try again."<<endl<<endl;
        }
    }

    return 0;
}

