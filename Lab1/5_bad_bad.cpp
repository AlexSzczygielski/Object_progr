/* 5.cpp
permutation -arrangement of all the elements of a set in a specific order
*/
#include <iostream>
using namespace std;

int counter = 0;

long int factorial(long int);
void swap(char &a,char &b){
    //swap both
    char temp = a;
    a = b;
    b = temp;
}
void permute(string &word, int first_index, int last_index){
    //counter++;
    //cout << "counter: " << counter << " " << word << endl;
    //case when string length is 1
    if(first_index == last_index){
        cout <<"R: " << word << endl;
    }else{
        //case when string length is greater than 1
        for(int i = first_index; i<= last_index; i++){
            counter++;
            //cout << "counter: " << counter << "\t";
            swap(word[first_index],word[i]);
            //cout << "swapped: " << word << "\t";

            permute(word,first_index + 1,last_index);

            swap(word[first_index],word[i]);
        }
    }
}

int main(){
    string word = "ABC";
    //cout << word << endl;
    //cout << "number of possibilites - " << factorial(word.length()) << endl;

    int length = word.length();
    //calling permute function, length - 1 to get index
    permute(word,0,length - 1);
    return 0;
}

long int factorial(long int x){
    long int var = 1;
    for(int i = 1; i<=x; i++){
        var = var*i;
        //cout << '(' << i << ") " << var << endl;
    }
    return var;
}