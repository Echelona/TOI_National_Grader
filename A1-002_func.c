#include <stdio.h>
#include <math.h>

typedef struct COINS_TRAY
{
    int coin_type[4];
    int number_of_coins_by_type[4];
}T;

void pprint(T tray){
    size_t nindex = sizeof(tray.coin_type)/sizeof(int);
    for (size_t i=0;i<nindex;++i){
        printf("%d = %d\n", tray.coin_type[i], tray.number_of_coins_by_type[i]);
    }
}

T count(int *qautity){
    int index = 0;
    T myTray = {
        {10, 5, 2, 1},
        {0, 0, 0, 0}
    };
    while (*qautity != 0){
        myTray.number_of_coins_by_type[index] = floor(*qautity / myTray.coin_type[index]);
        *qautity -= myTray.number_of_coins_by_type[index] * myTray.coin_type[index];
        ++index;
    }
    return myTray;
}

int main(){
    int number_of_coins = 0;
    scanf("%d", &number_of_coins);
    T result = count(&number_of_coins);
    pprint(result);
    return 0;
}