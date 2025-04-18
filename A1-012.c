#include <stdio.h>
#include <math.h>

typedef int (*operation)(int*, int*);

void reverse(int *n, int *rn){
    int d = floor(*n / 10);
    int dd = *n % 10;
    *rn = (dd * 10) + d;
}

int adding(int *n1, int *n2){return *n1 + *n2;}

int multiply(int *n1, int *n2){return *n1 * *n2;}   

operation sign(char c){
    switch(c){
        case '+':
            return adding;
        case '*':
            return multiply;
        default:
            return NULL;
    }
} 

int process(int *n1, int *n2, char c){
    operation op = sign(c);
    if(op != NULL){
        return op(n1, n2);
    } else {
        return -1;
    }
}

int main(){
    int n, rn;
    char c;
    scanf("%d %c", &n, &c);
    reverse(&n, &rn);
    printf("%d %c %d = %d\n", n, c, rn, process(&n, &rn, c));
    return 0;
}