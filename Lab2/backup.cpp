#include <iostream>
#include <exception>
using namespace std;

class rational_numb{
    int numerator; //numerator
    int denumerator; //denumerator

    public:
    //constructor, default values
    rational_numb(){
        numerator = 1;
        denumerator = 1;
    }

    //constructor
    rational_numb(int x, int y){
        check(y);
        numerator = x;
        denumerator = y;
    }
    //ensure denumerator isnt equal zero
    void check(const int& x){
        if(x==0){
            cout << "error!\n";
            terminate();
        }
    }

    //getters
    int getNumerator() const {return numerator;}
    int getDenumerator() const {return denumerator;}

    //setters
    void setNumerator(const int& x){
        numerator = x;
    }

    void setDenumerator(const int& x){
        check(x);
        denumerator = x;
    }

    void setRational(const int& x, const int& y){
        check(y);
        numerator = x;
        denumerator = y;
    }

    //print 
    void print(){
        cout << numerator << '/' << denumerator;
    }
    //calculator methods
    void add(const rational_numb& second){
        numerator = numerator * second.getDenumerator() + denumerator*second.getNumerator();
        denumerator = denumerator * second.getDenumerator();
    }

    void substract(const rational_numb& second){
        numerator = numerator * second.getDenumerator() - denumerator*second.getNumerator();
        denumerator = denumerator * second.getDenumerator();
    }

    void multiply(const rational_numb& second){
        numerator = numerator * second.getNumerator();
        denumerator = denumerator * second.getDenumerator();
    }

    void divide(const rational_numb& second) {
        if (second.getNumerator() == 0) {
            cout << "div/0, terminate \n";
            terminate();
        }
        //multiply by inversion
        numerator = numerator * second.getDenumerator();
        denumerator = denumerator * second.getNumerator();
    }
};
int main(){
    //rational_numb r;
    //rational_numb r_2(1,0); //if this uncommented, program will terminate
    rational_numb r(1,3);
    rational_numb r_2(1,2);

    //addition
    r.print(); cout <<" + ";
    r_2.print(); cout << " = ";
    r.add(r_2);
    r.print(); cout << endl;

    //substract
    r.print(); cout <<" - ";
    r_2.print(); cout << " = ";
    r.substract(r_2);
    r.print(); cout << endl;

    //multiplication
    r.print(); cout <<" * ";
    r_2.print(); cout << " = ";
    r.multiply(r_2);
    r.print(); cout << endl;

    //division
    r.print(); cout <<" / ";
    r_2.print(); cout << " = ";
    r.divide(r_2);
    r.print(); cout << endl;
    return 0;
}