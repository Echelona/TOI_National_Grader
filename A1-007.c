#include <stdio.h>
#include <ctype.h>

int main(){
    char chr;
    scanf("%c", &chr);
    char c = tolower(chr);
    if (c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}