/*
2.cpp
Aleksander Szczygielski, 410110
Program takes A and C coordinates and calculates parameters of rectangle and rest of points.
Another possibility is to pass all 4 points ABCD, then the already calculated parameters are uploaded.
It is important to type in ABCD appropriately, as stated by mathematical rules of naming the 2D figures
(as provided on the printed picture, when running program).
*/
#include <iostream>
#include <cmath>
using namespace std;

void draw_rectangle(){
    cout << "      D  ----------  C\n";
    for(int i =0; i<2; i++){
        cout << "        |          | \n";
    }
    cout << "      A  ----------  B\n";
    cout << "\n\n\n";
}

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
    Point m_a;
    Point m_b;
    Point c;
    Point d;
    Point middle;
    double height;
    double width;
    double area;

    public:
    //constructors, overloaded for either giving 2 values or none 
    Rectangle(){
        m_a.setCoords(0,0);
        c.setCoords(3,3);
        calculate_rest();
    }
    
    Rectangle(Point A, Point C){
        //check if values provided dont lie parallel to axis
        if(check(A,C) == 1){
            m_a.setCoords(A.getX(), A.getY());
            c.setCoords(C.getX(),C.getY());
            calculate_rest();
        }else{
            m_a.setCoords(0,0);
            c.setCoords(3,3);
            calculate_rest();
        }
    }

    bool check(Point& A, Point& C){
        if(A.getX() == C.getX() || A.getY() == C.getY()){
            cout << "error, running default values \n";
            return 0;
        }
        else return 1;
    }

    //calculating B and D and also updating area
    void calculate_rest(){
        middle.setCoords(section_middle(m_a,c).getX(),section_middle(m_a,c).getY());
        calc_width(m_a,c);
        calc_height(m_a,c);
        d.setCoords(middle.getX() - (width/2), middle.getY() + (height/2));
        m_b.setCoords(middle.getX() + (width/2), middle.getY() - (height/2));
        calculateArea();
    }
    Point section_middle(Point& x, Point& y){
        Point middle;
        middle.setCoords((abs((x.getX() - y.getX())/2) + x.getX()),(abs((x.getY() - y.getY())/2)+ x.getY()));
        //cout << "Middle: " << middle.getX() << ", " << middle.getY() << endl;
        return middle;
    }
    
    void calc_width(Point& x, Point& y){
        width = abs((x.getX() - y.getX()));
    }

    void calc_height(Point& x, Point& y){
        height = abs((x.getY() - y.getY()));
    }

    //rectangle area
    void calculateArea() {
        area = width*height;
    }

    //setters, altough they dont make much sense in this automated design, taking only diagonal points
    void setPoints(const Point& A, const Point& B, const Point& C, const Point& D){
        m_a.setCoords(A.getX(),A.getY());
        m_b.setCoords(B.getX(),B.getY());
        c.setCoords(C.getX(),C.getY());
        d.setCoords(D.getX(),D.getY());
        middle.setCoords(section_middle(m_a,c).getX(),section_middle(m_a,c).getY());
        calc_width(m_a,c);
        calc_height(m_a,c);
        calculateArea();
    }
    void vector_shift(Point& shift){
        m_a.setCoords(m_a.getX() + shift.getX(), m_a.getY()+shift.getY());
        c.setCoords(c.getX() + shift.getX(), c.getY()+shift.getY());
        cout << "here \n";
        calculate_rest();
    }
    //getters
    Point getA() const {return m_a;}
    Point getB() const {return m_b;}
    Point getC() const {return c;}
    Point getD() const {return d;}
    Point getM() const {return middle;}
    double getHeight() const {return height;}
    double getWidth() const {return width;}
    double getArea() const {return area;}


    //display
    void display(Rectangle& rect){
        cout << "A: " << rect.getA().getX() << ", " << rect.getA().getY() << endl;
        cout << "B: " << rect.getB().getX() << ", " << rect.getB().getY() << endl;
        cout << "C: " << rect.getC().getX() << ", " << rect.getC().getY() << endl;
        cout << "D: " << rect.getD().getX() << ", " << rect.getD().getY() << endl;
        cout << "M: " << rect.getM().getX() << ", " << rect.getM().getY() << endl;
        cout << "height = " << height << endl;
        cout << "width = " << width << endl;
        cout << "area = " << area << endl;
    }

    void draw_rectangle(Rectangle& rect){
    cout << "Resulting rectangle: \n\n";
    cout << '(' << rect.getD().getX() << "," << rect.getD().getY() << ')' <<" D  ----------  C";
    cout << '(' << rect.getC().getX() << "," << rect.getC().getY() << ')' << endl;
    for(int i =0; i<2; i++){
        cout << "        |          | \n";
    }
    cout << '(' << rect.getA().getX() << "," << rect.getA().getY() << ')' << " A  ----------  B";
    cout << '(' << rect.getB().getX() << "," << rect.getB().getY() << ')' << endl << endl;
}
};
int main(){
    cout << "Test for default values: \n\n";
    Rectangle test;
    test.draw_rectangle(test);
    test.display(test);

    cout << "\n \nRectangle calculator, please provide A and C (diagonal points): \n";
    draw_rectangle();
    Point a(1,2);
    Point c(12,6);
    Rectangle rect(a,c);
    rect.draw_rectangle(rect);
    rect.display(rect);

    cout << "\n Manually provided four values: \n";
    Point a_2(0,0);
    Point b_2(4,0);
    Point c_2(4,4);
    Point d_2(0,4);
    rect.setPoints(a_2,b_2,c_2,d_2);
    rect.draw_rectangle(rect);
    rect.display(rect);
    
    Point shift(1,1);
    cout << "\n \n Shifting previous rectangle by vector: (" << shift.getX() << ',' << shift.getY() <<")\n";
    rect.vector_shift(shift);
    rect.draw_rectangle(rect);
    rect.display(rect);
    return 0;
}