#include <iostream>

int main(){
    int passed_score[3] = {5, 20, 25};
    int score = 0;
    std::string result = "pass";
    for (int i=0;i<3;++i){
        std::cin >> score;
        score < passed_score[i]?result = "fail":result;
    }
    std::cout << result << std::endl;
    return 0;
}