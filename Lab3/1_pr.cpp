#include <iostream>

#include <assert.h>

class Rational{
    int m_num;
    int m_denum;

    public:
        Rational(int num = 0, int denum = 1){
            assert(denum != 0);
            m_num = num;
            m_denum = denum;
        }

        int get_num() const {return m_num;}
        int get_denum() const {return m_denum;}
        void set_num(int num) {m_num = num;}
        void set_denum(int denum) {m_denum = denum;}

        friend Rational operator+(const Rational& lhs, const Rational& rhs){
            return Rational(lhs.m_num * rhs.m_denum + rhs.m_num * lhs.m_denum, lhs.m_denum * rhs.m_denum);
        }

        friend Rational operator-(const Rational& lhs, const Rational& rhs){
            return Rational(lhs.m_num * rhs.m_denum - rhs.m_num * lhs.m_denum, lhs.m_denum * rhs.m_denum);
        }

        friend Rational operator*(const Rational& lhs, const Rational& rhs){
            return Rational(lhs.m_num * rhs.m_num, lhs.m_denum * rhs.m_denum);
        }

        friend Rational operator/(const Rational& lhs, const Rational& rhs){
            return Rational(lhs.m_num * rhs.m_denum, lhs.m_denum * rhs.m_num);
        }

        friend std::ostream& operator<<(std::ostream& out, const Rational& rat){
            out << rat.get_num() << "/" << rat.get_denum();
            return out;
        }

        friend std::istream& operator>>(std::istream& in, Rational& rat){
            in >> rat.m_num;
            in >> rat.m_denum;
            return in;
        }

        friend bool operator>(const Rational& lhs, const Rational& rhs){
            if(lhs.m_num * rhs.m_denum > lhs.m_denum * rhs.m_num){
                return true;
            }
            else return false;
        }

        friend bool operator<(const Rational& lhs, const Rational& rhs){
            if(lhs.m_num * rhs.m_denum > lhs.m_denum * rhs.m_num){
                return false;
            }
            else return true;
        }

        friend bool operator==(const Rational& lhs, const Rational& rhs){
            if(lhs.m_num * rhs.m_denum == lhs.m_denum * rhs.m_num){
                return true;
            }
            else return false;
        }

        friend bool operator!=(const Rational& lhs, const Rational& rhs){
            if(lhs.m_num * rhs.m_denum == lhs.m_denum * rhs.m_num){
                return false;
            }
            else return true;
        }
};

int main(){
    Rational r1;
    Rational r2;
    std::cout << "1st fractions: ";
    std::cin >> r1;
    // std::cout << r1 << "\n";
    std::cout << "2st fractions: ";
    std::cin >> r2;
    // std::cout << r2 << "\n";

    Rational r3 = r1 + r2;
    std::cout << "r1 + r2 = " << r3 << "\n";

    Rational r4 = r1 - r2;
    std::cout << "r1 - r2 = " << r4 << "\n";

    Rational r5 = r1 * r2;
    std::cout << "r1 * r2 = "<< r5 << "\n";

    Rational r6 = r1 / r2; 
    std::cout << "r1 / r2 = "<< r6 << "\n";

    std::cout << (r1 == r2 ? "r1 and r2 are equal\n" : "r1 and r2 are not equal\n");
    std::cout << (r1 != r2 ? "r1 and r2 are not equal\n" : "r1 and r2 are equal\n");
    std::cout << (r1 > r2 ? "r1 is greater than r2\n" : "r1 is less than r2\n");
    std::cout << (r1 < r2 ? "r1 is less than r2\n" : "r1 is greater than r2\n");
    
}