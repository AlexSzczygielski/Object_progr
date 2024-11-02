#include <iostream>
using namespace std;

int main(){
    string input = "Cisbest";
    int length = input.length();
    for(int i = length; i>=0; i--){
        cout << input[i];
    }
    for(int i = 1; i<=length; i++){
        cout<<input[i];
    }
    cout << '\n';
}