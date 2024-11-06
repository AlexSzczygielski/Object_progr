#include<iostream>
using namespace std;

void quadratic(float& a, float &b, float &c, float& x1, float& x2){
    float delta = (b*b) - (4*a*c);
    try{
        cout << "delta = " << delta << endl;
        if(delta<0){
            throw runtime_error("Equation has no real solutions");
            cout << "This never prints" << endl;
        }
        cout << "does this print \n";
        x1 = (-b - sqrt(delta))/(2*a);
        cout << "x1 = " << x1 << endl;
        x2 = (-b + sqrt(delta))/(2*a);
        cout << "x2 = " << x2 << endl;
    }
    catch(const runtime_error& str){
    }
}

int main(){
    float a = 1;
    float b = 2;
    float c = 2;
    float x1,x2;
    quadratic(a,b,c,x1,x2);
    cout << "continue in main" << endl;
    a = 1, b = 2, c = 1;
    quadratic(a,b,c,x1,x2);
    a = 1, b = 2, c = -2;
    quadratic(a,b,c,x1,x2);
    return 0;
}