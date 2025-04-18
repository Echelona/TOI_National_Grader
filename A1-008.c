#include <stdio.h>
#include <string.h>

int main(){
    int count = 0;
    char c = ' ';
    char r[4] = "no";
    while ((c = getchar()) != '\n' && c != EOF){ 
            ++count;
            if (count == 13){
                strcpy(r, "yes");  
            }else if (count > 13){
                strcpy(r, "no");  
                break;
            }
    }
    printf("%s\n", r);
    return 0;
}