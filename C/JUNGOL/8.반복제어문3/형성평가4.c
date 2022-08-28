#include <stdio.h>

int main(){
    int n, topR, topC, topLe, topRi;
    int botR,botC, botLe, botRi;
    scanf("%d", &n);
    for (topR = 1; topR <= n; topR++){
        for (topLe = 0; topLe < topR - 1; topLe++){
            printf(" ");
        }
        for (topC = 1; topC <= 2 * (n + 1 - topR) - 1; topC++)
        {
            printf("*");
        }
        for (topRi = 0; topRi < topR - 1; topRi++){
            printf(" ");
        }
        printf("\n");
    }
    for (botR = 1; botR <= n-1; botR++){
        for (botLe = 1; botLe <= n-1 - botR; botLe++){
            printf(" ");
        }
        for (botC = 1; botC <= 2 * botR + 1; botC++){
            printf("*");
        }
        for (botRi = 1; botRi <= n-1 - botR; botRi++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}