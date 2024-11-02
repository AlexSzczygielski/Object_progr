#include <iostream>
#include <ctime>
using namespace std;

class SmartArray{
    unsigned int m_size;
    int* m_beginning; //point to address
    int* m_end;

    public:
        SmartArray(unsigned int size){
            m_size = size;
            m_beginning = new int[size];
            m_end = m_beginning + m_size;
            for(int* i = m_beginning; i < m_end; i++){ 
                *i = 0; 
            }
        }
        
        ~SmartArray(){
            cout<<"array deleted";
        }

        int* getBegin() const { return m_beginning; }
        int* getEnd() const { return m_end; }

        int* find_max(int* first, int* last){
            int* temp = first;
            for(int* i = first; i < last; i++){
                if(*i > *temp) { temp = i; }
            }
            return temp;
        }
        int* find_min(int* first, int* last){
            int* temp = first;
            for(int* i = first; i < last; i++){
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
            for(int* i = m_beginning; i < m_end; i++){ cout << *i << " "; }
            cout<< "\n";
        }
};

int main(){
    srand(time(NULL));

    SmartArray array(5);
    cout << "empty: " << endl;
    array.print();

    for(int* i = array.getBegin(); i < array.getEnd(); i++){
        *i = rand() % 9 + 1;
    }

    cout << "array filled with random numbers: \n"; array.print();

    if(array.is_sorted()) { cout<<"sorted\n"; }
    else { cout<<"not sorted\n"; }

    cout<<"Max: "<<*array.find_max(array.getBegin(), array.getEnd())
    <<"\nMin: "<<*array.find_min(array.getBegin(), array.getEnd())<<"\n";

    array.sort(0);
    if(array.is_sorted()) { cout<<"sorted\n"; }
    else { cout<<"not sorted\n"; }
    array.print();

    cout << "inverted \n";
    array.sort(1);
    array.print();
}