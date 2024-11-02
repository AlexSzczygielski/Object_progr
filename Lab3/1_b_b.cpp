#include <iostream>
#include <exception>
using namespace std;

class rational_numb{
    int m_numerator; //numerator
    int m_denominator; //denumerator

    public:
    //constructor
    rational_numb(int num = 0, int denum = 1){
        check(denum);
        m_numerator = num;
        m_denominator = denum;
    }

    //ensure denumerator isnt equal zero
    void check(const int& x){
        if(x==0){
            cout << "error!\n";
            terminate();
        }
    }

    //getters
    int getNumerator() const {return m_numerator;}
    int getDenumerator() const {return m_denominator;}

    //setters
    void setNumerator(const int& x){
        m_numerator = x;
    }

    void setDenumerator(const int& x){
        check(x);
        m_denominator = x;
    }

    void setRational(const int& x, const int& y){
        check(y);
        m_numerator = x;
        m_denominator = y;
    }

    //print 
    void print(){
        cout << m_numerator << '/' << m_denominator;
    }
    //calculator methods
     friend rational_numb operator+(const rational_numb& first, const rational_numb& second){
        int result1 = first.getNumerator() * second.getDenumerator() + first.getDenumerator()*second.getNumerator();
        int result2 = first.getDenumerator() * second.getDenumerator();
        return (result1,result2);
     }
    void substract(const rational_numb& second){
        m_numerator = m_numerator * second.getDenumerator() - m_denominator*second.getNumerator();
        m_denominator = m_denominator * second.getDenumerator();
    }
    friend rational_numb multiply(const rational_numb& first, const rational_numb& second);
    friend rational_numb divide(const rational_numb& first, const rational_numb& second);
};

//friend functions
    rational_numb multiply(const rational_numb& first, rational_numb& second){
        return rational_numb (first.getNumerator() * second.getNumerator(), first.getDenumerator() * second.getDenumerator());
    }

    rational_numb divide(const rational_numb& first, rational_numb& second) {
        if (first.getDenumerator() == 0 || second.getNumerator() == 0) {
            cout << "div/0, terminate \n";
            terminate();
        }
        //multiply by inversion
        return rational_numb (first.getNumerator() * second.getDenumerator(), first.getDenumerator() * second.getNumerator());
    }


int main(){
    //rational_numb r;
    //rational_numb r_2(1,0); //if this uncommented, program will terminate
    rational_numb r(1,3);
    rational_numb r_2(1,2);

    //addition
    r.print(); cout <<" + ";
    r_2.print(); cout << " = ";
    rational_numb result = r + r_2;
    result.print(); cout << endl;

    //substract
    r.print(); cout <<" - ";
    r_2.print(); cout << " = ";
    r.substract(r_2);
    r.print(); cout << endl;

    //multiplication
    r.print(); cout <<" * ";
    r_2.print(); cout << " = ";
    result = multiply(r,r_2);
    result.print(); cout << endl;

    //division
    r.print(); cout <<" / ";
    r_2.print(); cout << " = ";
    result = divide(r,r_2);
    result.print(); cout << endl;
    return 0;
}