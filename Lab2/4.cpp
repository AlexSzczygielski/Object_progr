/*
4.cpp
student class
I didnt make a setter for ID, as i set it as constant in my implementation to avoid errors.
using static to share inside all classes, average grade needs updating with change of grades!
(thus update_average method)
*/
#include <iostream>
using namespace std;

class student{
    string m_name;
    static unsigned int s_id_counter; //using static to generate ids, better than global variable
                                    // as it is linked to class student, shared by all student objs
    const unsigned int m_id;
    float m_grade;
    static float s_grade_sum; //this static, shared in class to calculate average
    static float s_average; //static, to share average in class, updated with each student and with change
                            //exam m_grade value
    
    public:
    //constructor
    student(string m_name = "-", float m_grade = 0) : m_name(m_name), m_id(++s_id_counter), m_grade(m_grade) {
        s_grade_sum += m_grade;
        s_average = s_grade_sum/s_id_counter;
    }

    //setters
    void setName(const string& n){
        m_name = n;
    }

    void setGrade(const float& g){
        update_average(g);
        m_grade = g;
    }

    void setStudent(const string& n, const float& g){
        update_average(g);
        m_name = n;
        m_grade = g;
    }

    //getters
    const unsigned int getId() const {return m_id;}

    string getName() const {return m_name;}

    float getGrade() const {return m_grade;}

    static float getAverage() {return s_average;}

    //print 
    void print(){
        cout << "ID: " << m_id << ", " << m_name << ", grade: " << m_grade << endl;
    }

    void update_average(const float& g){
        s_grade_sum -= m_grade; //updating static variable for new value
        s_grade_sum += g;
        s_average = s_grade_sum/s_id_counter;
    }
};

//declaring id_counter (static variable from student class)
unsigned int student :: s_id_counter = 0;
float student :: s_grade_sum = 0;
float student :: s_average = 0;

int main(){
    student s1("Aristotle", 95.5);
    student s2("Marie Sklodowska Curie", 70.4);
    student s3("Plato", 25.1);

    cout << "student s1: "; s1.print();
    cout << "student s2: "; s2.print();
    cout << "student s3: "; s3.print();

    //calculate average grade
    cout << "Average grade: " << student::getAverage() << endl;

    //check for average update
    s3.setGrade(50);
    cout << "check avg update, student s3 grade changed to: " << s3.getGrade() << endl;
    cout << "Average grade: " << student::getAverage() << endl;

    s3.setGrade(25.1);
    cout << "change s3 grade to original value: " << s3.getGrade() << " and check again" << endl;
    cout << "Average grade: " << student::getAverage() << endl;
    return 0;
}