#include<iostream>
#include<string>
#include<algorithm>

void letter_frequency(std::string& s){
    std::sort(s.begin(),s.end());
    //std::cout << s;
    for(int i = 0; i<s.size();i++){
        std::cout << s[i] << std::endl;
    }
}

int main(){
    std::string word;
    std::cout << "provide word to count frequency of repeating letters:\n";
    //std::cin >> word;
    word = "abcd";
    letter_frequency(word);

    return 0;
}