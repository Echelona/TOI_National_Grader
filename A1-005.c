#include <stdio.h>

void process(int *month, int *day, int *index){
    if (*month >= 1 && *month <= 12){
        if (*month <= 3){
            *index = 0;
        }else if (*month <=6){
            *index = 1;
        }else if (*month <= 9){
            *index = 2;
        }else if (*month <= 12){
            *index = 3;
        }
        
        if ((*day >= 21) && (*month % 3 == 0)){
            *index = *index == 3?0:++(*index);
        }
    }
}

int main(int argc, const char * argv[]) {
    int month, day;
    int index = -1;
    char seasons[][7] = {"winter", "spring", "summer", "fall"};
    scanf("%d", &month);
    scanf("%d", &day);
    process(&month, &day, &index);
    printf("%s\n", seasons[index]);
    return 0;
}
