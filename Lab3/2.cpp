#include <iostream>

class Complex{
    float m_real;
    float m_imag;

    public:
        Complex(float real = 0, float imag = 0){
            m_real = real; 
            m_imag = imag;
        }

        float getReal() const {return m_real;}
        float getImag() const {return m_imag;}

        void setReal(float real) {m_real = real;}
        void setImag(float imag) {m_imag = imag;}

};

Complex operator+(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.getReal() + rhs.getReal(), rhs.getImag() + lhs.getImag());
}

Complex operator-(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.getReal() - rhs.getReal(), lhs.getImag() - rhs.getImag());
}

Complex operator*(const Complex& lhs, const Complex& rhs){
    const float real = lhs.getReal() * rhs.getImag() - lhs.getImag() * rhs.getReal();
    const float imag = (lhs.getReal() + lhs.getImag())*(rhs.getReal() + rhs.getImag())
                    -(lhs.getReal() * rhs.getReal())-(lhs.getImag() * rhs.getImag());
    return Complex(real, imag);
}

Complex operator/(const Complex& lhs, const Complex& rhs){
    const float denom = (rhs.getReal() * rhs.getReal()) + (rhs.getImag() * rhs.getImag());
    const float real = ((lhs.getReal() * rhs.getReal()) + (lhs.getImag() * rhs.getImag())) / denom;
    const float imag = ((lhs.getImag() * rhs.getReal()) - (lhs.getReal() * rhs.getImag())) / denom;
    return Complex(real, imag);
}

std::ostream& operator<<(std::ostream& out, const Complex& z){
    if(z.getImag() >= 0)
        out << z.getReal() << " + i" << z.getImag();
    else 
        out << z.getReal() << " - i" << -z.getImag();
    return out;
}

std::istream& operator>>(std::istream& in, Complex& z){
    float temp;
    in >> temp;
    z.setReal(temp);
    in >> temp;
    z.setImag(temp);
    return in;
}

int main(){
    Complex complex_1, complex_2;
    std::cout << "Give first complex number: ";
    std::cin >> complex_1;

    std::cout << "Give second complex number: ";
    std::cin >> complex_2;

    std::cout << "z1 + z2 = " << complex_1 + complex_2 << std::endl;
    std::cout << "z1 - z2 = " << complex_1 - complex_2 << std::endl;
    std::cout << "z1 * z2 = " << complex_1 * complex_2 << std::endl;
    std::cout << "z1 / z2 = " << complex_1 / complex_2 << std::endl;
}