#include <stdio.h>

int main(){
    char c[10], idx;
    for (idx=0; idx<10; idx++){
        scanf(" %c", &c[idx]);
    }
    printf("%c %c %c", c[0], c[3], c[6]);
    return 0;
}