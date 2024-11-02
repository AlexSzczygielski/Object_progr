#include <iostream>
using namespace std;

class NewString : public string{
    public:
    //a
    NewString(const char* str = "") : string(str){}
    NewString(const string& str = "") : string (str){}
};

int main(){
    return 0;
}