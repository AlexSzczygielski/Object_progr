#include <iostream>
//3.
class InvalidIndex{
    const char* m_error_msg;
    public:
    InvalidIndex(const char* error = "Invalid index") : m_error_msg(error){}
    const char* what(){
        return m_error_msg;
    }
};

class InvalidValue{
    const char* m_error_msg;
    public:
    InvalidValue(const char* error = "Invalid value") : m_error_msg(error){}
    const char* what(){
        std::cout << "invalid value exception: ";
        return m_error_msg;
    }
};

//4.
class StaticArray{
    unsigned int m_arr[16];
    public:
    StaticArray(){
        for(int i = 0; i<16; i++){
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
        if(value<0) throw InvalidValue("Negative value");
        m_arr[index] = value;
        std::cout << "m_arr[" << index << "]: " << value << std::endl;
    }
};

int main(){
    StaticArray arr;
    //index above
    try{
        int n = arr.at(16);
    }
    catch(InvalidIndex& exception){
        std::cerr << exception.what() << std::endl;
    }
    catch(...){std::cout << "unknown exception" << std::endl;};
    //invalid value
    try{
        arr.set_item(15,-5);
    }
    catch(InvalidValue& exception){
        std::cerr << exception.what() << std::endl;
    }
    catch(InvalidIndex& exception){
        std::cerr << exception.what() << std::endl;
    }
    catch(...){std::cout << "unknown exception" << std::endl;}
    return 0;
}