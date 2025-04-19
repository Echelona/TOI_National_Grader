#include <stdio.h>
#include <ctype.h>

void process (int *row, int *col, int *topping, int *n, int *price){
    int matrix1[3][2] = {
        {60, 80},
        {80, 100},
        {100, 120}
    };
    int matrix2[3] = {0, 15, 10};
    *price = matrix1[*row][*col] + (matrix2[*topping] * (*n));
}

int main (){
    char type, size, topping, c;
    int n = 0, row, col, top, price = 0;
    scanf("%c %c", &type, &size);
    scanf("\n");
        c = getchar();
        topping = toupper(c);
        if (topping != 'N'){
            scanf("%d", &n);
        }
    
    if (toupper(type) == 'S') {
        row = 0;
    }else if (toupper(type) == 'M') {
        row = 1;
    }else if (toupper(type) == 'L') {
        row = 2;
    }
    if (toupper(size) == 'R'){
        col = 0;
    }else if (toupper(size) == 'T'){
        col = 1;
    }
    if (topping == 'P'){
        top = 1;
    }else if(topping == 'E'){
        top = 2;
    }else {
        top = 0;
    } 
    process(&row, &col, &top, &n, &price);
    printf("%d\n", price);
    return 0;
}