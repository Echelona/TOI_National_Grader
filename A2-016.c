#include <stdio.h>
#include <string.h>

void dupChk(char (*n1)[], char (*n2)[], int *reward){
    char s1[8], s2[8], p1[2], p2[2], suf1[6], suf2[6], suf1_3[4], suf2_3[4], suf1_2[3], suf2_2[3];
    strncpy(s1, *n1, 7);
    s1[7] = '\0';   
    strncpy(s2, *n2, 7);
    s2[7] = '\0';
    strncpy(p1, *n1, 1);
    p1[1] = '\0';
    strncpy(p2, *n2, 1);  
    p2[1] = '\0';
    strncpy(suf1, *n1+2, 5);
    suf1[5] = '\0';
    strncpy(suf2, *n2+2, 5);
    suf2[5] = '\0';
    strncpy(suf1_3, *n1+4, 3);
    suf1_3[3] = '\0';
    strncpy(suf2_3, *n2+4, 3);
    suf2_3[3] = '\0';
    strncpy(suf1_2, *n1+5, 2);
    suf1_2[2] = '\0';
    strncpy(suf2_2, *n2+5, 2);
    suf2_2[2] = '\0';
    if (strcmp(s1, s2) == 0){
        *reward = 1000000;
        return;    
    }
    if (strcmp(suf1, suf2) == 0){
        *reward = 100000;
        return;    
    }
    if ((strcmp(p1, p2) == 0) && (strcmp(suf1_3, suf2_3) == 0)){
        *reward = 2000;
        return;    
    }
    if ((strcmp(p1, p2) == 0) && (strcmp(suf1_2, suf2_2) == 0)){
        *reward = 1000;
        return;    
    }
    if (strcmp(suf1_3, suf2_3) == 0){
        *reward = 200;
        return;    
    }
    if (strcmp(suf1_2, suf2_2) == 0){
        *reward = 100;
        return;    
    }
    if (strcmp(p1, p2) == 0){
        *reward = 20;
        return;    
    }
}

int main() {
    char n1[8];
    char n2[8];
    int reward = 0;
    scanf("%[^\n]", n1);
    scanf("\n");
    scanf("%[^\n]", n2);
    dupChk(&n1, &n2, &reward);
    printf("%d\n", reward);
    return 0;
}
