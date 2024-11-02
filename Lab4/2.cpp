#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class SmartArray{
    unsigned int m_size;
    int* m_beginning;
    int* m_end;
    
    public:
        SmartArray(unsigned int size){
            m_size = size;
            m_beginning = new int[size];
            m_end = m_beginning + m_size;
            for(int* i = m_beginning; i < m_end; i++){ *i = 0; }
        }
        ~SmartArray(){
            delete[] m_beginning;
            cout<<"array deleted" << endl;
        }
        SmartArray(SmartArray& array){
            m_size = array.getSize();
            int* table = new int[m_size];
            m_beginning = table;
            for(int* i = array.getBegin(); i < array.getEnd(); i++){
                *table = *i;
                table++;
            }
            m_end = table;
        }

        int getSize() const {return m_size;}
        int* getBegin() const { return m_beginning; }
        int* getEnd() const { return m_end; }

        int* find_max(int* begin, int* end){
            int* temp = begin;
            for(int* i = begin; i < end; i++){
                if(*i > *temp) { temp = i; }
            }
            return temp;
        }
        int* find_min(int* begin, int* end){
            int* temp = begin;
            for(int* i = begin; i < end; i++){
                if(*i < *temp) { temp = i; }
            }
            return temp;
        }
        bool is_sorted(){
            for(int* i = m_beginning + 1; i < m_end; i++){
                if(*i < *(i - 1)) return false;
            }
            return true;
        }
        void sort(bool direction){
            int sorted_elements = 0;
            int* new_max;
            while(sorted_elements != m_size){
                new_max = find_max(m_beginning, m_end - sorted_elements);
                for(int* i = new_max; i < m_end - 1; i++){
                    if(*i > *(i+1)) {swap(i, i+1);}
                }
                sorted_elements++;
            }
            if(direction){
                invert();    
            }
        }
        void invert(){
            int* temp = new int[m_size];
            for(int* i = m_beginning; i < m_end; i++){
                *temp = *i;
                temp++;
            }
            for(int* i = m_beginning; i < m_end; i++){
                temp--;
                *i = *temp;
            }
            delete temp;
        }
        void swap(int* ptr1, int* ptr2){
            int temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
        }

        void print(){
            for(int* i = m_beginning; i < m_end; i++){ std::cout << *i << " "; }
            cout<< "\n";
        }
        
        int& operator[] (const int index){
            return *(m_beginning + index);
        }
        void operator= (const SmartArray& array){
            m_size = array.getSize();
            m_beginning = array.getBegin();
            m_end = array.getEnd();
        }
};


std::ostream& operator<<(std::ostream& out, const SmartArray& array){
    for(int* i = array.getBegin(); i < array.getEnd(); i++){
        out<<*i<<" ";
    }
    return out;
}

int main(){
    srand(time(NULL));

    SmartArray array(5);

    for(int* i = array.getBegin(); i < array.getEnd(); i++){
        *i = rand() % 99 + 1;
    }
    array.print();

    SmartArray array_2(array);
    array_2.print();

    array_2[3] = 66;
    cout<<"3 element array 2: "<<array_2[3]<<endl;
    cout<< "array_2: " << array_2 << endl;
}