#include <iostream>
using namespace std;

int main(){
    string input = "Cisbest";
    int length = input.length();
    cout << "length: " << length << "\n\n";

    int temp = length;
    //loop for indexing the string
    for(int i = 0; i<=length;i++){
        //loop for distance from left, temp - 1, so that letter in on last place, not +1
        for(int j = temp-1; j>0; j--){
            cout << j;
        }
        cout << input[i];
        //condition to have only 1 C
        if(i>0){
            //loop for distance from the middle, k=2 because " " is doubled while transistioning
            for(int k =2; k <= (length - temp) + i; k++){
                cout << " ";
            }
            cout << input[i];
        }
        //temp to have diagonal shape
        temp--;
        cout << endl;
    }
}