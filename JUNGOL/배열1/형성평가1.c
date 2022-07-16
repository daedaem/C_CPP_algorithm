#include <stdio.h>

int main(){
    char c[10];
    int i;
    for (i = 0; i < 10; i++){
        scanf(" %c", &c[i]);
    }
    for (i = 9; i >= 0; i--){
        printf("%c ", c[i]);
    }
    return 0;
}