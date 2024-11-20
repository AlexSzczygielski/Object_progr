#include<iostream>
#include<vector>

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
    return 0;
}