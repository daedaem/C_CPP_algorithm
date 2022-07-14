#include <stdio.h>

int main(){
    int n, col;
    char cc='A';
    scanf("%d", &n);
    for (n; n >= 1; n--){
        for (col = 0; col < n; col++){
            printf("%c", cc);
            cc ++;
        }
        printf("\n");
    }
        return 0;
}
