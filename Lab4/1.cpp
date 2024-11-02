/*
1.cpp - Fraction class
Lab 4
Operator "++" overloaded in such a way that adds 1 (3/3)
*/
#include <iostream>
#include <exception>
using namespace std;

class Fraction{
    int m_numerator; //numerator
    int m_denominator; //denumerator

    public:
    Fraction(int num = 0, int denom = 1){ //a) constructor that takes value of num and denom
        check(denom);
        m_numerator = num;
        m_denominator = denom;
    }

    Fraction(const Fraction& f){ //b) copy constructor
        m_numerator = f.m_numerator;
        m_denominator = f.m_denominator;
        cout << "copy constructor called" << endl;
    }

    void check(const int& x){
        if(x == 0){
            cout << "invalid denominator, m_denominator = 0, terminating" << endl;
            terminate();
        }
    }

    int getNumerator() const {return m_numerator;}
    int getDenominator() const {return m_denominator;}

    //friend methods declarations
    friend Fraction operator+(const Fraction& first, const Fraction& second);
    friend std::ostream& operator<<(std::ostream& out, Fraction& f);
    friend std::istream& operator>>(std::istream& in, Fraction& f){
            in >> f.m_numerator;
            in >> f.m_denominator;
            return in;
    }
    Fraction& operator++(); //preincrement
    Fraction& operator++(int); //postincrement
    friend bool operator==(const Fraction& lhs, const Fraction& rhs){
            if(lhs.m_numerator * rhs.m_denominator == lhs.m_denominator * rhs.m_numerator){
                return true;
            }
            else return false;
    }
    operator double() const {return double(m_numerator)/double(m_denominator);}
        Fraction& operator=(const Fraction& f){
            Fraction* o = new Fraction(f.getNumerator(), f.getDenominator());
            return *o;
        }
};

//friend fucntions (methods):
Fraction operator+(const Fraction& first, const Fraction& second){
    return Fraction (first.m_numerator * second.m_denominator + first.m_denominator*second.m_numerator,first.m_denominator * second.m_denominator);
}

std::ostream& operator<<(std::ostream& out, Fraction& f){
        out << f.getNumerator() << '/' << f.getDenominator();
        return out;
    }

Fraction& Fraction::operator++(){
    m_numerator = m_numerator+m_denominator;
    return *this;
}

Fraction& Fraction::operator++(int){
    Fraction temp(m_numerator,m_denominator);
    ++(*this);
    return *this;
}



int main(){
    //constructor taking values
    Fraction f(1,3);
    cout << "Fraction f(1,3): " << f << endl;

    //copying:
    Fraction fcopy(f);
    cout << "Fraction fcopy(f): " << fcopy << endl;

    //preincrement
    cout << "++f(" << f <<"): " << ++f << endl;

    //postincrement
    cout << "f("<< f <<")" << ", f++ : " << f++ << endl;

     //testing cout and cin
    cout << "test cout << " << f << endl;
    cout << "test cin \n";
    Fraction r_cin;
    cin >> r_cin;
    cout << "provided r: " << r_cin << endl;

    cout << "bool(" << f << "==" << r_cin << ") : " << bool(f==r_cin) << endl;

    r_cin = f;
    cout << "r_cin = f : " << r_cin; 
    return 0;
}