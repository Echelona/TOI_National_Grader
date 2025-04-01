#include <stdio.h> 
#include <math.h>

int main(){
    int number_of_coins = 0;
    int number_of_coins_by_type[2][4] = 
    {
        {10, 5, 2, 1},
        {0, 0, 0, 0}
    };
    scanf("%d", &number_of_coins);
    int index_type = 0;
    while (number_of_coins != 0)
    {
        number_of_coins_by_type[1][index_type] = floor(number_of_coins / number_of_coins_by_type[0][index_type]);
        number_of_coins -= (number_of_coins_by_type[0][index_type] * number_of_coins_by_type[1][index_type]);
        ++index_type;
    }
    for (int i=0;i<4;++i){
        printf("%d = %d\n", number_of_coins_by_type[0][i], number_of_coins_by_type[1][i]);
    }
    
    return 0;
}