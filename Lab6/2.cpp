#include<iostream>
#include<string>
#include<sstream>
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
    cout << "n(hex): " << s.str();
    //e (uncomment)
    //str = "2147483648(MaxInt + 1)Bakczysaraj";
    //n = std::stoi(str); //exception out of range
    return 0;
}