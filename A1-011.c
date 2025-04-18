#include <stdio.h>
#include <ctype.h>

int main(){
    char str[6];
    char str_2[11];
    char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};    
    scanf("%s", str);
    int ini_index = 0;
    int encode_index = 0;
    int count = 0;
    for (int i=0;i<5;++i){
        if (toupper(str[i]) == toupper(str[ini_index])) {
            str_2[encode_index+1] = toupper(str[ini_index]);
            ++count;
            str_2[encode_index] = numbers[count];
        }else {
            ini_index = i;
            count = 0;
            encode_index += 2;
            --i;
        }
    } 
    str_2[encode_index+2] = '\0';
    printf("%s\n", str_2);
    return 0;
}