#include <iostream>
//3.
class InvalidIndex{
    const char* m_error_msg;
    public:
    InvalidIndex(const char* error) : m_error_msg(error){}
    const char* what(){
        std::cout << "invalid index exception: ";
        return m_error_msg;
    }
};

class InvalidValue{
    const char* m_error_msg;
    public:
    InvalidValue(const char* error) : m_error_msg(error){}
    const char* what(){
        std::cout << "invalid value exception: ";
        return m_error_msg;
    }
};



int main(){
    return 0;
}