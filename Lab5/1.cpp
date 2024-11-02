#include <iostream>
using namespace std;

class MyString : string{
    public:
    MyString(const char* str = "default argument") : string (str){
        cout << "MyString constructor called" << endl;
        //cout << *str << endl;
    }
    ~MyString(){

        cout << "MyString destructor called" << endl;
    }
    friend std::ostream& operator<<(std::ostream& out, MyString& str){
        out << static_cast <const string&> (str);
        return out;
    }
};

int main(){
    MyString str1("test");
    cout << str1 << endl;
    MyString def;
    cout << "default: " << def << endl;
    return 0;
}