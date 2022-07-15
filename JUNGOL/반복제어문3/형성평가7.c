#include <stdio.h>

int main(){
    int n,r,topC, botC, num=0;
    char cc = 'A';
    scanf("%d", &n);
    for (r = 1; r <= n; r++){
        for (topC = 1; topC <= n - r + 1;topC++){
            printf("%c ", cc);
            cc++;
        }
        for (botC = 1; botC <= r-1; botC++){
            printf("%d ", num);
            num++;
        }
        printf("\n");
    } return 0;
}
