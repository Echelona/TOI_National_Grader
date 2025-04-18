#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", n+m);
    if ((n+m) > 50){
        printf("pass\n");
    }else {
        printf("fail\n");
    }
    return 0;
}