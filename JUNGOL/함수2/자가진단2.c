#include <stdio.h>

int main(){
    int m, d;
    scanf("%d %d", &m, &d);
    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            d<=31 ? printf("OK!") : printf("BAD!");
            break;
        case 2:
            d< 29 ? printf("OK!") : printf("BAD!");
            break;
        default:
            d<= 30 ? printf("OK!") : printf("BAD!");
            break;
    }
}