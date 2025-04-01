#include <iostream>
#include <algorithm>

int main(){
    int present_integer = 0;
    int max_integer = 0;
    for (int i=0;i<3;++i){
        std::cin >> present_integer;
        if (i != 0){
            max_integer = std::max(present_integer, max_integer);
        }else {
            max_integer = present_integer;
        }
    }
    std::cout << max_integer << std::endl;
    return 0;
}