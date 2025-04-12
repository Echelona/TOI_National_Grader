#include <stdio.h>

int count;

void process(int (*arr)[], int findex){
    int cvalue = *(*arr+findex);
    int lvalue = *(*arr+(findex-1));
    int rvalue = *(*arr+(findex+1));
    if ((cvalue > lvalue) && (cvalue > rvalue)){
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
