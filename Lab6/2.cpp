#include<iostream>
#include<string>
#include<sstream>
#include<exception>
using namespace std;

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
    try{
        str = "2147483648(MaxInt + 1)Bakczysaraj";
        n = std::stoi(str); //exception out of range
    }
    catch(std::out_of_range& exception){
        cerr << "You ran out of integer range: " << exception.what() << endl;
    }
    return 0;
}