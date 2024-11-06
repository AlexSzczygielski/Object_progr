#include<iostream>
using namespace std;

float quadratic(float a, float b, float c){
    float delta = (b*b) - (4*a*c);
    cout << "delta = " << delta << endl;

    if(delta >= 0){
        float x1 = (sqrt(delta) - b)/(2*a);
        float x2 = (sqrt(delta) + b)/(2*a);
    }
}

int main(){
    return 0;
}