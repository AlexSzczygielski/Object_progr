#include<iostream>
#include<string>
#include<algorithm>
#include<map>

void print_map(std::map<char,int>& m){
    for(auto& pair : m){
        std::cout << "frequency of '" << pair.first << "' : " << pair.second << std::endl;
    }
}

void letter_frequency(std::string& s){
    char temp = s[0];
    int count;
    std::map<char,int> frequency_map; //map - keys strings and values integers
    
    for(int i = 0; i<s.size();i++){
        if(frequency_map.count(s[i])==1){
            //record exists
            frequency_map[s[i]] = frequency_map.at(s[i])+1;
        }else{
            //record doesn't exist
            frequency_map[s[i]] = 1;
        }
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