#include <iostream>
using namespace std;

int main(){
    string input = "Cisbest";
    int length = input.length();

    //temp required to run distance for right side
    int temp = length;
    //loop for indexing the string
    for(int i = 0; i<=length;i++){
        //condition for the last line
         if(i == length-1){
            for(int l = length; l>=0; l--){
                cout << input[l];
            }
            for(int l = 1; l<=length; l++){
                cout<<input[l];
            }
            cout << endl;
            break;
        }

        //loop for distance from left, temp - 1, so that letter in on last place, not +1
        for(int j = temp-1; j>0; j--){
            cout << " ";
        }
        cout << input[i];

        //condition to avoid double letter at the top
        if(i>0){
            //loop for distance from the middle, k=2 because " " is doubled while transistioning
            for(int k =2; k <= (length - temp) + i; k++){
                cout << " ";
            }
            cout << input[i];
        }
        temp--;
        cout << endl;
    }
}