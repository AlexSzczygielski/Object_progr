#include <iostream>
using namespace std;

class MyString : string{
    public:
    MyString(const char* str = "default str") : string (str){
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

class Figure{
    float m_x;
    float m_y;
    MyString m_label;

    public:
    //b
    Figure(double x = 1, double y = 1, const char* str = "Default str") : m_x(x), m_y(y), m_label(str){
        cout << "Figure constructor called" << endl;
    }
};

int main(){
    Figure fig1(1,2,"test");
    Figure fig_def;
    return 0;
}