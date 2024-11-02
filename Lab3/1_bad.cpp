#include <iostream>
#include <exception>
using namespace std;

class rational_numb{
    int numerator; //numerator
    int denumerator; //denumerator

    public:
    //constructor, default values
    //rational_numb(int n = 1, int d = 1) : numerator(n), denumerator(d){;}
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
    
    //overloading operators
    rational_numb operator+ (const rational_numb& second){
        int result_num = numerator * second.getDenumerator() + denumerator*second.getNumerator();
        int result_denum = denumerator * second.getDenumerator();
        return rational_numb(result_num,result_denum);
    }

    rational_numb operator- (const rational_numb& second){
        int result_num = numerator * second.getDenumerator() - denumerator*second.getNumerator();
        int result_denum = denumerator * second.getDenumerator();
        return rational_numb(result_num,result_denum);
    }

    rational_numb operator* (const rational_numb& second){
        int result_num = numerator * second.getNumerator();
        int result_denum = denumerator * second.getDenumerator();
        return rational_numb(result_num,result_denum);
    }   
};
int main(){
    //rational_numb r;
    //rational_numb r_2(1,0); //if this uncommented, program will terminate
    rational_numb r(1,3);
    rational_numb r_2(1,2);

    //addition
    cout << r.getNumerator() << '/' << r.getDenumerator() <<" + ";
    cout << r_2.getNumerator() << '/' << r_2.getDenumerator() <<" = ";
    rational_numb result = r + r_2;
    cout << result.getNumerator() << '/' << result.getDenumerator() << endl;
    cout << 'r' << r.getNumerator() << '/' << r.getDenumerator() << endl;

    //substract
    cout << r.getNumerator() << '/' << r.getDenumerator() <<" - ";
    cout << r_2.getNumerator() << '/' << r_2.getDenumerator() <<" = ";
    result = r - r_2;
    cout << result.getNumerator() << '/' << result.getDenumerator() << endl;
    cout << 'r' << r.getNumerator() << '/' << r.getDenumerator() << endl;

    //multiplication
    cout << r.getNumerator() << '/' << r.getDenumerator() <<" * ";
    cout << r_2.getNumerator() << '/' << r_2.getDenumerator() <<" = ";
    result = r * r_2;
    cout << result.getNumerator() << '/' << result.getDenumerator() << endl;
    cout << 'r' <<  r.getNumerator() << '/' << r.getDenumerator() << endl;
    return 0;
}