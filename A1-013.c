#include <stdio.h>
#include <string.h>

void process(char *p, char s[5]){
    char code[] = "H 4567";
    char pref, suff[5];
    pref = code[0];
    strncpy(suff, code + 2, 4);
    suff[4] = '\0';
    if ((pref == *p) && (strcmp(suff, s) == 0)){
        printf("safe unlocked\n");
        return;
    }
    if (pref == *p){
        printf("safe locked - change digit\n");
        return;
    }
    if (strcmp(suff, s) == 0){
        printf("safe locked - change char\n");
        return;
    }
    if ((pref != *p) && (strcmp(suff, s) != 0)){
        printf("safe locked\n");
        return;
    }
}

int main() {
    char pref, suff[5];
    scanf("%c", &pref);
    scanf("%4s", suff);
    process(&pref, suff);
    return 0;
}