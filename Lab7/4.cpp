#include<iostream>
#include<string>
#include<algorithm>

void letter_frequency(std::string& s){
    std::sort(s.begin(),s.end());
    //std::cout << s;
    char temp = s[0];
    int count = 0;
    for(int i = 0; i<=s.size();i++){
        //std::cout << s[i] << std::endl;
        if(s[i] == temp){ //here always at the 1st iteration
            count++;
        } else{
            std::cout<< "frequency of '" << temp << "' : " << count << std::endl;
            temp = s[i];
            count = 1;
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