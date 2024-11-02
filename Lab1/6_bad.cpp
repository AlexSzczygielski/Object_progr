#include <iostream>
using namespace std;

int main(){
    string s = "Cisbest";
    //cout << s[0] << endl;
    for(int i = 0; i < s.length(); i++){
        for(int j = s.length()-i; j>=0; j--){
            cout << "\t";
        }
        cout << s[i] << endl;
    }
        for(int i = 0; i < s.length(); i++){
        for(int j = i; j>0; j--){
            cout <<  "\t";
        }
        cout << s[i] << endl;
    }
}