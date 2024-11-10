#include<iostream>
#include<string>
#include<sstream>
#include<exception>
using namespace std;

void tryStoi(const string& str){
    try{
        int n = std::stoi(str);
    }
    catch(std::out_of_range& exception){
        cerr << "You ran out of integer range: " << exception.what() << endl;
    }
    catch(std::invalid_argument& exception){
        cerr << "No integer here: " << exception.what() << endl;
    }
}

int main(){
    //a
    string str = "2147483647(MaxInt)Bakczysaraj";
    //cin >> str;
    //b
    int n = std::stoi(str);
    cout << n << endl;
    //c
    stringstream s;
    s << std::hex << n;
    //d
    cout << "n(hex): " << s.str() << endl;
    //e 
        str = "2147483648(MaxInt + 1)Bakczysaraj";
        tryStoi(str); //exception out of range
        string str2 = "noIntegerHere";
        tryStoi(str2); //exception invalid argument
    return 0;
}