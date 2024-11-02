#include<iostream>
using namespace std;

void swap(char &a, char &b){
    //function to swap two chars
    cout << "\n swap: " << a << ", with " << b << "\t";
    char temp = a;
    a = b;
    b = temp;
    cout << "now: a: " << a << " b: " << b << endl;
}

void permute(string &word, int first_index, int last_index){
    //function performing permutation, recursive

    //case 0:
    if(first_index == last_index){
        cout << word << endl;
    }else{
        for(int i = first_index; i<=last_index; i++){
            swap(word[first_index],word[i]);

            permute(word,first_index+1,last_index);

            swap(word[first_index],word[i]);
            cout << "swapping word: " << word << endl;
        }
    }
}

int main(){
    string word = "ABC";
    int length = word.length();
    permute(word,0,length - 1);
    return 0;
}