#include <iostream>
#include <cmath>
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
    Point(double x_coord, double y_coord){
        m_x = x_coord;
        m_y = y_coord;
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

class Rectangle{
    // a and b are points on the opposite ends of one of diagnoals
    Point a;
    Point b;
    Point c;
    Point d;
    Point middle;

    public:
    //constructor, overloaded for either giving 2 values or none 
    Rectangle(){
        a.setCoords(0,0);
        b.setCoords(3,3);
        middle.setCoords(section_middle(a,b).getX(),section_middle(a,b).getY());
        section_length(a,b);
    }
    Rectangle(Point A, Point B){
        a.setCoords(A.getX(), A.getY());
        b.setCoords(B.getX(),B.getY());
        middle.setCoords(section_middle(a,b).getX(),section_middle(a,b).getY());
        section_length(a,b);
        c.setCoords(middle.getX() - half_width(a,b), middle.getY() + half_height(a,b));
        d.setCoords(middle.getX() + half_width(a,b), middle.getY() - half_height(a,b));
    }
    Point section_middle(Point& x, Point& y){
        Point middle;
        middle.setCoords((abs((x.getX() - y.getX())/2) + x.getX()),(abs((x.getY() - y.getY())/2)+ x.getY()));
        cout << "Middle: " << middle.getX() << ", " << middle.getY() << endl;
        return middle;
    }
    double half_width(Point& x, Point& y){
        return abs((x.getX() - y.getX()))/2;
    }
    double half_height(Point& x, Point& y){
        return abs((x.getY() - y.getY()))/2;
    }

    //dodac zaleznosc od zmiennej, nieskonczone
    double section_length(Point& x, Point& y){
        double length = ((x.getX() - y.getX())*(x.getX() - y.getX())) + ((x.getY() - y.getY())*(x.getY() - y.getY()));
        length = sqrt(length);
        //cout << length;
        return length;
    }

    //rectangle area
    double calculateArea() {

    }

    //getters for x and y
    Point getA() const {return a;}
    Point getB() const {return b;}
    Point getC() const {return c;}
    Point getD() const {return d;}
};
int main(){
    Point a(1,2);
    Point b(12,6);
    Rectangle rect(a,b);
    cout << "A: " << rect.getA().getX() << ", " << rect.getA().getY() << endl;
    cout << "B: " << rect.getB().getX() << ", " << rect.getB().getY() << endl;
    cout << "C: " << rect.getC().getX() << ", " << rect.getC().getY() << endl;
    cout << "D: " << rect.getD().getX() << ", " << rect.getD().getY();
    return 0;
}