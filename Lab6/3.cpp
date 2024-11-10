#include <iostream>
//3.
class InvalidIndex{
    const char* m_error_msg;
    public:
    InvalidIndex(const char* error = "Invalid index") : m_error_msg(error){}
    const char* what(){
        std::cout << "invalid index exception: ";
        return m_error_msg;
    }
};

class InvalidValue{
    const char* m_error_msg;
    public:
    InvalidValue(const char* error = "Invalid value") : m_error_msg(error){}
    const char* what(){
        std::cout << "invalid (negative) value exception: ";
        return m_error_msg;
    }
};

//4.
class StaticArray{
    unsigned int m_arr[16];
    public:
    StaticArray(){
        for(int i = 0; i<16; i++){
            std::cout << i << std::endl;
            m_arr[i] = i;
        }
    }
    //a
    int at(int index){
        if(index<0 || index>15) throw InvalidIndex();
        return m_arr[index];
    }
    //b
    void set_item(int index, int value){
        if(index<0 || index>15) throw InvalidIndex();
        if(value<0) throw InvalidValue();
        m_arr[index] = value;
    }
};

int main(){
    StaticArray arr;
    return 0;
}