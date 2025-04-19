#include <stdio.h>
#include <stdlib.h>

void process(char (*s1)[], char (*s2)[], int *N, int *count){
    for (int i=0;i<*N;++i){
            int n1 = *(*s1+i) != ('\0')?*(*s1+i) - '0':0;
            int n2 = *(*s2+i) != ('\0')?*(*s2+i) - '0':0;
            if (n1 + n2 != 9){
                ++(*count);
            }
    }
}

int main (){
    int N, count = 0;
    scanf("%d", &N);
    char s1[N+1], s2[N+1]; 
    scanf("%s %s[^\n]", s1, s2);
    process(&s1, &s2, &N, &count);
    count == 0 ? printf("YES\n") : printf("NO %d\n", count);
    return 0;
}