#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    //a
    string str = "123Bakczysaraj";
    //cin >> str;
    //b
    int n = std::stoi(str);
    cout << n << endl;
    //c
    stringstream s;
    s << std::hex << n;
    cout << "n(hex): " << s.str();
    return 0;
}