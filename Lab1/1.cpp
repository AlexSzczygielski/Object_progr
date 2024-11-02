#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int rand_number = 0;
    int guess;
    srand(time(0));
    rand_number = rand()%10+1;
    for(int i =0; i<8; i++){
        cout << "Your guess (" << i+1 << "): ";
        cin >> guess;
        if(guess > rand_number){
            cout << "higher, again \n";
        }
        else if(guess<rand_number){
            cout<< "lower, again \n";
        }
        else{
            cout << "congrats \n";
            break;
        }
    }
    cout << "rand_number = " << rand_number << "\n";
    return 0;
}