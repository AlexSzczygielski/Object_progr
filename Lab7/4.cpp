#include<iostream>
#include<string>
#include<algorithm>
#include<map>

void letter_frequency(std::string& s){
    char temp = s[0];
    int count;
    std::map<char,int> frequency_map; //map - keys strings and values integers
    
    for(int i = 0; i<=s.size();i++){
        if(s[i]==temp){
            count++;
        }else{
            frequency_map[temp] = count;
            std::cout << 
        }
    }
}

int main(){
    std::string word;
    std::cout << "provide word to count frequency of repeating letters:\n";
    //std::cin >> word;
    word = "abcdbcdcdd";
    letter_frequency(word);

    return 0;
}