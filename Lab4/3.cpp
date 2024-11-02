#include <iostream>
using namespace std;

class Time{
    int m_hours;
    int m_mins;
    int m_secs;

    public:
        Time(int hours = 0, int mins = 0, int secs = 0){
            m_hours = hours;
            m_mins = mins;
            m_secs = secs;
        }

        int getHours() const {return m_hours;}
        int getMins() const {return m_mins;}
        int getSecs() const {return m_secs;}

        void setHours(int hours) {m_hours = hours;}
        void setMins(int mins) {m_mins = mins;}
        void setSecs(int secs) {m_secs = secs;}

        void print(){
            cout<< "Time: " << m_hours << ":" << m_mins << ":" << m_secs << endl;
        }
        operator std::string(){
            std::string o = std::to_string(m_hours) + ":"
                        + std::to_string(m_mins) + ":"
                        + std::to_string(m_secs);
            return o;
        }
};

Time operator+(const Time& lhs, const Time& rhs){
    int h, m, s;
    h = lhs.getHours() + rhs.getHours();
    h %= 24;

    m = lhs.getMins() + rhs.getMins();
    if(m >= 60){
        h += m/60;
        m = m%60;
    }
    s = lhs.getSecs() + rhs.getSecs();
    if(s >= 60){
        m += s/60;
        s = s%60;
    }
    
    return Time(h, m, s);
}

bool operator>(const Time& lhs, const Time& rhs){
    if(lhs.getHours() > rhs.getHours()) {return true;}
    if(lhs.getHours() == rhs.getHours()) {
        if(lhs.getMins() > rhs.getMins()) {return true;}
        if(lhs.getMins() == rhs.getMins()) {
            if(lhs.getSecs() > rhs.getSecs()) {return true;}
        }
    }
    return false;
}

int main(){
    Time t(10,10,10);
    Time t2(11,11,11);

    t.print();
    t2.print();

    //sum of two times
    Time t3 = t + t2;
    cout << "sum of two times: "; t3.print();
    cout <<"bool (t>t2): " << bool(t>t2) << endl;

    std::cout<<"converting 't' to string: " << std::string(t) << endl;
}