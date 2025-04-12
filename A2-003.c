#include <stdio.h>

int count;

int check(int v_1, int v_2){return v_1 > v_2?1:0;}

void process(int (*arr)[], int findex){
    int cvalue = *(*arr+findex);
    int lvalue = *(*arr+(findex-1));
    int rvalue = *(*arr+(findex+1));
    int lvalue_chk = check(cvalue, lvalue);
    int rvalue_chk = check(cvalue, rvalue);
    if (lvalue_chk && rvalue_chk){
        ++count;
    }
}

int main (){
int N;
scanf("%d", &N);
int arr[N+2];
arr[0] = 0;
arr[N+1] =0;
for (int i=1;i<N+1;++i){
    scanf("%d", &arr[i]);
    if ((N == 1) || (i == N)){
        process(&arr, i);
    }
    if (i > 1){
        process(&arr, i-1);
    }
}
printf("%d\n", count);
    return 0;
}
