#include<iostream>
#include<fstream>

void copy_text(const std::string& ori,const std::string& copied){
    std::ifstream input(ori);
    std::ofstream output(copied);
    
    char c;
    while(input.get(c)){
        output << c;
    }
    output.close();
}

int main(){
    std::ifstream obj;
    copy_text("text.txt","copied.txt");
    obj.exceptions(std::ifstream::failbit|std::ifstream::badbit);
    try{
        obj.open("copied.txt");
        char c;
        while(obj.get(c)){
            std::cout << c << std::endl;
        }
        obj.clear();
        obj.close();
    }
    catch(const std::ifstream::failure& e){
        std::cerr << "exception: " << e.what() << std::endl;
    }
    return 0;
}