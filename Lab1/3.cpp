#include<iostream>
using namespace std;

int main(){
    char equals = '=';
    char operation;
    double number_1 = 0;
    double number_2 = 0;
    double result = 0;
    bool error = 0;
    while(true){
        cout<< "give operation: ";
        cin >> operation;
        cout << "number 1: ";
        cin >> number_1;
        cout << "number 2: ";
        cin >> number_2;
        switch(operation){
            case '+':
            result = number_1 + number_2;
            break;
            case '-':
            result = number_1 - number_2;
            break;
            case '*':
            result = number_1*number_2;
            break;
            case '/':
            if(number_2==0){
                cout << "error, div 0 \n";
                error = 1;
                break;
            }
            result = number_1/number_2;
            break;
        }
        if(error == 0){
            cout << result << endl;
        }
        number_1 = 0;
        number_2 = 0;
        error = 0;
    }
}