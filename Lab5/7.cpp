#include <iostream>
#include <algorithm> // For std::transform
using namespace std;

class NewString : public string{
    public:
    //a
    NewString(const char* str = "") : string(str){}
    NewString(const string& str = "") : string (str){}

    //b
    bool contains(const char* input){
        return this->find(input) != string::npos;
    }

    //c
    int compare(const string& str) const{
        //necessary to copy, as change in string is necessary
        string temp_thisLower = *this;
        string temp_str = str;

        //transform temp this to low
        transform(temp_thisLower.begin(), temp_thisLower.end(),
        temp_thisLower.begin(), ::tolower);

        //transform temp_str (check) to low
        transform(temp_str.begin(),temp_str.end(),temp_str.begin(), ::tolower);

        //and now return value from string method
        return temp_thisLower.compare(temp_str);
    }
};

int main(){
    NewString str("example_here_string");
    NewString str2("HERE");
    string str3 = "here";

    cout << "str: " << str << endl;
    cout << "str2: " << str2 << endl;
    //b
    cout << "own contains() method: " << endl;
    if(str.contains(str3.c_str())){
        cout << "here found in str!" << endl;
    }else{
        cout << "here not found in str!" << endl;
    }

    //c
    cout << "overloaded compare() method:" << endl;
    str = "here";
    cout << "str = " << str << ", compare with: " << str2 << endl;

    int result = str.compare(str2);
    if (result == 0) {
        cout << "str equal str2" << endl;
    } else if (result < 0) {
        cout << "str is less than str2" << endl;
    } else {
        cout << "str is greater than str2" << endl;
    }

    return 0;
}