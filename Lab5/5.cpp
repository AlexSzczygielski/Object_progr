#include <iostream>
#include <string>
#include <algorithm> // For std::transform
using namespace std;

//classes from before
class MyString : string{
    public:
    MyString(const char* str = "default str") : string (str){
        cout << "MyString constructor called" << endl;
        //cout << *str << endl;
        //print();
    }
    ~MyString(){

        cout << "MyString destructor called" << endl;
    }
    friend std::ostream& operator<<(std::ostream& out, MyString& str){
        out << static_cast <const string&> (str);
        return out;
    }

    MyString& toUpper() {
        for (char& c : *this) {  // Accessing the string directly using *this
            c = toupper(c);
        }
        return *this;
    }

    void print() const {
        cout << "The string is: " << *this << endl; // Using *this to convert to std::string
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
    MyString&  getLabel()  {return m_label;}

    //e
    void print(){
        cout << "I'm a Figure: (" << m_x << ',' << m_y
        << "), my label is: " << getLabel().toUpper() << endl;
    }
};

class Rectangle : public Figure{
    //a
    float m_w;
    float m_h;

    public:
    //b
    Rectangle(float x = 1, float y = 1, const char* label = "Default label", float w = 3, float h = 3 
    ) : Figure(x, y, label), m_w(w), m_h(h){
        cout << "Rectangle constructor called" << endl;
    }

    //c
    ~Rectangle(){
        cout << "Rectangle destructor called" << endl;
    }

    //d
    float getW() const {return m_w;}
    float getH() const {return m_h;}

    //f
    void print(){
        cout << "I'm a Rectangle: (" << getX() << ',' << getY()
        << "), my label is: " << getLabel().toUpper() << endl;
    }
};

class Square : public Rectangle{
    public:
    //a
    Square(float x = 1, float y = 1, const char* label = "Default label", float w = 5) :
    Rectangle(x,y,label,w){
        cout << "Square constructor called" << endl;
    }

    //d
    ~Square(){
        cout << "Square destructor called" << endl;
    }

    //g
    void print(){
        cout << "i'm a Square: (" << getX() << ',' << getY()
        << "), my label is: " << getLabel().toUpper() << endl;
    }
};


int main(){
    //a
    //Figure fig1;
    //b
    //Rectangle rec1;
    //c
    //Square sq1;

    //d
    Square sq(1.0,2.0,"square 1",10.0);
    //e,f and g
    sq.print();
    return 0;
}