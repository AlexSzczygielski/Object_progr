#include<iostream>
#include<vector>
#include<ctime>

void print(std::vector<float>& a){
    for(int i = 0; i<a.size(); i++){
        std::cout << a.at(i) << std::endl;
    }
}

std::vector<float> sum(std::vector<float>& a, std::vector<float>& b){
    std::vector<float> result;
    for(int i=0; i<a.size(); i++){
        result.push_back(a.at(i) + b.at(i));
        //std::cout << result.at(i) << std::endl;
    }
    return result;
}

int main(){
    std::vector<float> a;
    std::vector<float> b;
    int vector_size = 3;

    std::srand(time(NULL));
    for (int i = 0; i<vector_size; i++){
        a.push_back(rand()%10+1);
        b.push_back(rand()%10+1);
    }
    std::cout << "vector a:\n"; print(a); std::cout << "vector b:\n"; print(b);
    std::vector<float> summation = sum(a,b);
    std::cout << "summation vector:\n"; print(summation);

    return 0;
}