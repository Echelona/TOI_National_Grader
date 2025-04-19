#include <stdio.h>

int subDigit2 (int *n) {return *n % 100;}

int subdigit3 (int *n) {return *n % 1000;}

void process (char *c1, int *n1, char *c2, int *n2, int *reward){
    if ((*c1 == *c2) && (*n1 == *n2)){
        *reward = 1000000;
        return;
    }
    if (*n1 == *n2){
        *reward = 100000;
        return;
    }
    if ((*c1 == *c2) && (subdigit3(n1) == subdigit3(n2))){
        *reward = 2000;
        return;
    }
    if ((*c1 == *c2) && (subDigit2(n1) == subDigit2(n2))){
        *reward = 1000;
        return;
    }
    if (subdigit3(n1) == subdigit3(n2)){
        *reward = 200;
        return;
    }
    if (subDigit2(n1) == subDigit2(n2)){
        *reward = 100;
        return;
    }
    if (*c1 == *c2){
        *reward = 20;
        return;
    }
}

int main (){
    char c1, c2;
    int n1, n2;
    int reward = 0;
    scanf("%c %d %c %d[^\n]", &c1, &n1, &c2, &n2);
    process(&c1, &n1, &c2, &n2, &reward);
    printf("%d\n", reward);
    return 0;
}