#include <iostream>
#include <string>

int main(){
    std::string fname;
    std::string lname;
    std::cin >> fname;
    std::cin >> lname;
    std::string nickname;
    nickname.append(fname.substr(0,2));
    nickname.append(lname.substr(0,2));
    std::cout << "Hello " << fname << " " << lname << std::endl;
    std::cout << nickname << std::endl; 
    return 0;
}