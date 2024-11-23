#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

void print(std::vector<std::string>& a){
    for(int i = 0; i<a.size(); i++){
        std::cout << a.at(i) << std::endl;
    }
}
int main(){
    //a
    std::vector<std::string> shopping_list;
    //b
    shopping_list.push_back("wine");
    shopping_list.push_back("beetroot");
    shopping_list.push_back("bananas");
    shopping_list.push_back("sugar");
    shopping_list.push_back("chocolate");
    shopping_list.push_back("carrot");

    //c
    std::cout<<"last element on the list: " << shopping_list.back() << std::endl;
    shopping_list.pop_back();
    std::cout<<"last element after deletion: " << shopping_list.back() << std::endl;

    //d
    shopping_list.insert(shopping_list.begin() + 2,"coffee");
    std::cout << "3rd element: " << shopping_list.at(2) << std::endl;

    //e
    for (int i = 0; i<shopping_list.size();i++){
        if(shopping_list.at(i) == "sugar"){
            shopping_list.at(i) = "candy";
            std::cout << "sugar replaced with candy" << std::endl;
        }
        //std::cout << shopping_list.at(i) << std::endl;
    }

    //f
    for(int i =0; i<shopping_list.size(); i++){
        if(shopping_list.at(i) == "chocolate"){
            shopping_list.erase(shopping_list.begin() + i);
            std::cout << "chocolate erased" << std::endl;
            break;
        }
        //std::cout << shopping_list.at(i) << std::endl;
    }

    //g
    std::cout << "\n\n before sort: " << std::endl;
    print(shopping_list);
    std::sort(shopping_list.begin(),shopping_list.end());
    std::cout << "\n after sort: " << std::endl;
    print(shopping_list);

    //e
    std::cout << "shopping list after all tasks: " << std::endl;
    print(shopping_list);
    return 0;
}