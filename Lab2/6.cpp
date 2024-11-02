#include <iostream>
using namespace std;

class Int{
    int m_int_num;

    public:
        void setInt(int int_num) {m_int_num = int_num;}
        int getInt_num() const {return m_int_num;}
        void clear() {m_int_num = 0;}

        int add(Int& second){
            return m_int_num + second.getInt_num();
        }

        void print(bool hex){
            if(hex){
                cout << std::hex << m_int_num << endl;
            }
            else{
                cout << m_int_num << endl;
            }
        }
};

int main(){
    Int numb_1;
    numb_1.setInt(6);

    Int numb_2;
    numb_2.setInt(8);

    Int result;
    result.setInt(numb_1.add(numb_2));
    cout << "result: ";
    result.print(0);
    result.print(1);
}