#include <iostream>
using namespace std;

int main(){
    int var = 0;
    string s = "Cisbest";
    //cout << s[0] << endl;
    for(int i = 0; i < s.length(); i++){
        for(int j = s.length()-i; j>=0; j--){
            cout <<"\t";
        }
        cout << s[i];
        if(i>0){
            for(int k = 0; k<i+2; k++){
            //cout << k << "\t";
            cout << "\t";
            var++;
            }
            cout << s[i];
        }
        //            cout << "v = " << var;
        cout << endl;
        cout << "i = " << i << endl;
    }




        for(int k = 1; k < s.length(); k++){ //starts from 1 to remove C
        for(int l = k; l>0; l--){
            cout << "\t";
        }
        cout << s[k] << endl;
    }
    
}