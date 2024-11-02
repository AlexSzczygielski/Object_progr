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
        return rational_numb (first.m_numerator * second.m_denominator + first.m_denominator*second.m_numerator,first.m_denominator * second.m_denominator);
        }

    friend rational_numb operator-(const rational_numb& first, rational_numb& second){
        return rational_numb (first.m_numerator * second.m_denominator - first.m_denominator*second.m_numerator, first.m_denominator * second.m_denominator);
    }
    friend rational_numb operator*(const rational_numb& first, const rational_numb& second){
        return rational_numb (first.m_numerator * second.m_numerator, first.m_denominator * second.m_denominator);
    }
    friend rational_numb operator/(const rational_numb& first, const rational_numb& second);

    friend std::ostream& operator<<(std::ostream& out, const rational_numb& numb){
            out << numb.getNumerator() << "/" << numb.getDenumerator();
            return out;
        }
    friend std::istream& operator>>(std::istream& in, rational_numb& numb){
            in >> numb.m_numerator;
            in >> numb.m_denominator;
            return in;
        }
    
    friend bool operator>(const rational_numb& lhs, const rational_numb& rhs){
            if(lhs.m_numerator * rhs.m_denominator > lhs.m_denominator * rhs.m_numerator){
                return true;
            }
            else return false;
        }

    friend bool operator<(const rational_numb& lhs, const rational_numb& rhs){
            if(lhs.m_numerator * rhs.m_denominator > lhs.m_denominator * rhs.m_numerator){
                return false;
            }
            else return true;
        }
    friend bool operator==(const rational_numb& lhs, const rational_numb& rhs){
            if(lhs.m_numerator * rhs.m_denominator == lhs.m_denominator * rhs.m_numerator){
                return true;
            }
            else return false;
        }

    friend bool operator!=(const rational_numb& lhs, const rational_numb& rhs){
            if(lhs.m_numerator * rhs.m_denominator == lhs.m_denominator * rhs.m_numerator){
                return false;
            }
            else return true;
        }
};

//friend functions
    //rational_numb operator*(const rational_numb& first, rational_numb& second);

    rational_numb operator/(const rational_numb& first, rational_numb& second) {
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
    result = r-r_2;
    result.print(); cout << endl;

    //multiplication
    r.print(); cout <<" * ";
    r_2.print(); cout << " = ";
    result = r*r_2;
    result.print(); cout << endl;

    //division
    r.print(); cout <<" / ";
    r_2.print(); cout << " = ";
    result = r/r_2;
    result.print(); cout << endl;

    //testing cout and cin
    cout << "test cout << " << r << endl;
    cout << "test cin \n";
    rational_numb r_cin;
    cin >> r_cin;
    cout << "provided r: " << r_cin << endl;

    cout << "test >, <, ==, != \n";
    cout << "bool(" << r << "<" << r_2 << ") : " << bool(r<r_2) << endl;

    cout << "bool(" << r << ">" << r_2 << ") : " << bool(r>r_2) << endl;

    cout << "bool(" << r << "==" << r_2 << ") : " << bool(r==r_2) << endl;

    cout << "bool(" << r << "!=" << r_2 << ") : " << bool(r!=r_2) << endl;

    return 0;
}