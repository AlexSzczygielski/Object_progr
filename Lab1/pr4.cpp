#include <iostream>
using namespace std;

int main(){
    string input = "Cisbest";
    int length = input.length();

    int temp = length;
    
    for(int i = 0; i<=length;i++){
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

        //loop for distance from left
        for(int j = temp; j>=0; j--){
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
    return 0;
}