#include<iostream>
#include<string>
#include<algorithm>
#include<map>

void print_map(const std::map<char,int>& m){
    for(auto& pair : m){
        std::cout << "frequency of '" << pair.first << "' : " << pair.second << std::endl;
    }
}

void letter_frequency(const std::string& s){
    std::map<char,int> frequency_map; //map - keys strings and values integers
    
    for(int i = 0; i<s.size();i++){
        frequency_map[s[i]]++;
    }
    print_map(frequency_map);
}

int main(){
    std::string word;
    std::cout << "provide word to count frequency of repeating letters:\n";
    //std::cin >> word;
    word = "abcdbcdcdd";
    letter_frequency(word);

    return 0;
}