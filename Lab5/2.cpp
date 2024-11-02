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
    //a
    float m_x;
    float m_y;
    MyString m_label;

    public:
    //b
    Figure(double x = 1, double y = 1, const char* str = "Default label") : m_x(x), m_y(y), m_label(str){
        cout << "Figure constructor called" << endl;
    }

    //c
    ~Figure(){
        cout << "Figure destructor called" << endl;
    }

    //d
    float getX() const {return m_x;}
    float getY() const {return m_y;}
    MyString getLabel() const {return m_label;}

    //e
    void print(){
        cout << "I'm a Figure: (" << m_x << ',' << m_y
        << "), my label is: " << m_label << endl;
    }
};

int main(){
    Figure fig1(1,2,"test");
    //Figure fig_def;
    fig1.print();
    return 0;
}