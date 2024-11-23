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
        
        //exit condition
        if(name == "exit"){
            std::cout << "terminating" << std::endl;
            break; 
        }

        //a
        if(phonebook.count(name)){ //check if name exists in the map (true if yes, 0 if not)
            std::cout << phonebook[name] << std::endl;
        } else{
            //b
            std::cout << "record doesn't exist, provide the telephone number now:" << std::endl;
            std::cin >> tel_number;
            phonebook[name] = tel_number; //create new record
        }
    }
    return 0;
}