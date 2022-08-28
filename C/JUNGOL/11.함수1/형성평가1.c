#include <stdio.h>

void pri(int n){
    switch(n){
        case 1:
            printf("first\n");
            break;
        case 2:
            printf("second\n");
            break;
        default:
            printf("third\n");
        }
    printf("@@@@@@@@@@\n");
}

int main(){
    int n;
    char c;
    for (n = 1; n <= 3;n++){
        pri(n);
    }
    return 0;
}
