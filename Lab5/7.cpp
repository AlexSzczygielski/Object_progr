#include <iostream>
using namespace std;

class NewString : public string{
    public:
    //a
    NewString(const char* str = "") : string(str){}
    NewString(const string& str = "") : string (str){}

    bool contains(const char* input){
        return this->find(input) != string::npos;
    }
};

int main(){
    NewString str("example_here_string");
    //a
    if(str.contains("here")){
        cout << "here found in str!" << endl;
    }else{
        cout << "here not found in str!" << endl;
    }
    return 0;
}