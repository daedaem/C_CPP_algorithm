#include <stdio.h>

int main(){
    int a, b, nu[10];
    scanf("%d %d", &a, &b);
    nu[0] = a, nu[1]=b;
    for (a = 2; a < 10; a++){
        nu[a] = (nu[a - 2] + nu[a - 1])%10;
    }
    for (a = 0; a < 10;a++){
        printf("%d ", nu[a]);
    }
    return 0;
}