/* 4.cpp (lotto)
int quantity_of_numbers - how many numbers to draw
int max_range - numbers generated from 0 to max_range
bool flag - TRUE if random generated number finds equal in array of numbers[], used in check condition
error prints the value that has already been drawn to demonstrate, that code works as intented
*/
#include<iostream>
using namespace std;

int main(){
    srand(time(0));
    int quantity_of_numbers = 5;
    int max_range = 100;
    int numbers[quantity_of_numbers];

    for(int i = 0; i<quantity_of_numbers; i++){
        //get rand
        bool flag = 0;
        int var;
        var = rand()%max_range+1;
        //check and set flag
        for(int j=0; j<quantity_of_numbers; j++){
            if(var == numbers[j]){
                cout << "error (" << var << ")\n";
                flag = 1;
            }
        }
        //save result or do it again
        if(flag == 0){
            numbers[i] = var;
            cout << '[' << i+1 << "] " << numbers[i] << endl;
        }
        else i--;
    }
}