#include<iostream>
#include<exception>
//7
class averageException : public std::exception{
    const char* m_error_msg;
    public:
    averageException(const char* error) : m_error_msg(error){}
    const char* what() {return m_error_msg;}
};

bool out_range(int x){
    //std::cout << x << std::endl;
    if(x>100||x<0) {return true;}
    return false;
}

//6
float calculateAverage(int a,int b,int c,int d){
    if(out_range(a) || out_range(b) || out_range(c) || out_range(d)){
        throw averageException("provided value out of range");
    }
    return float(a+b+c+d)/4;
}

int main(){
    try{
        std::cout << calculateAverage(25,50,75,100) << std::endl;
    }
    catch(averageException& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        std::cout << calculateAverage(-25,50,75,100) << std::endl;
    }
    catch(averageException& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}