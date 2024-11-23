#include<iostream>
#include<string>
#include<map>

int main(){
    std::map<std::string,int> phonebook;
    while(true){
        std::string name;
        int tel_number;
        std::cout << "Enter the name: ";
        std::cin >> name;
        if(phonebook.count(name)){ //check if name exists in the map (true if yes, 0 if not)
            std::cout << "here";
        }
    }
    return 0;
}