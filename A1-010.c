#include <stdio.h>
#include <ctype.h>

void process(int *value, char *occ){
    char oc = *occ;
    int age = *value;
    if ((age < 18) || (toupper(oc)) == 'S'){
        printf("%d\n", 20);
    }else {
        printf("%d\n", 50);
    }
}

int main(int argc, const char * argv[]) {
    int age;
    char occ;
    scanf("%d %c", &age, &occ);
    process(&age, &occ);
    return 0;
}
