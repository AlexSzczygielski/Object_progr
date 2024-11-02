#include<iostream>
using namespace std;

void swap(char &a, char &b){
    //function to swap two chars
    char temp = a;
    a = b;
    b = temp;
}

void permute(string &word, int first_index, int last_index){
    //function performing permutation, recursive

    //case 0:
    if(first_index == last_index){
        cout << word << endl;
    }else{
        for(int i = first_index; i<=last_index; i++){
            //swap first index with index i
            swap(word[first_index],word[i]);

            //call recursive
            permute(word,first_index+1,last_index);

            //swap back
            swap(word[first_index],word[i]);
        }
    }
}

int main(){
    string word;
    //word = "Atena";
    cout << "type in word to show its permuations: ";
    cin >> word; 
    int length = word.length();
    permute(word,0,length - 1);
    return 0;
}