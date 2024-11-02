#include <iostream>
using namespace std;

int main(){
    string input;
    cout << "word: ";
    getline(cin,input);
    //input = "Jedzmy, nikt nie wola";
    int length = input.length();
    for(int i = length; i>=0; i--){
        cout << input[i];
    }
    cout << '\n';
}