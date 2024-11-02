#include <iostream>
using namespace std;

class Point{
    double m_x;
    double m_y;

    public:
    //constructor, default values
    Point(){
        m_x = 0;
        m_y = 0;
    }
    //getters for x and y
    double getX() const {return m_x;}
    double getY() const {return m_y;}

    //setter for coords
    void setCoords(const double& x,const double& y){
        m_x = x;
        m_y = y;
    }
};

int main(){
    //demonstrating default values
    Point p;
    cout << "p.m_x = " << p.getX() << ", p.m_y = " << p.getY() << endl;

    //setting specific values
    Point p_2;
    p_2.setCoords(1.3,2.5);
    cout << "p_2.m_x = " << p_2.getX() << ", p_2.m_y = " << p_2.getY() << endl;
    return 0;
}