#include <stdio.h>

int main(){
    int n, topr,topc,botr,botc, botspace;
    scanf("%d", &n);
    for (topr = 1; topr <= n;topr++)
    {
        for (topc = 1; topc <= topr;topc++){
            printf("# ");
        }
        printf("\n");
    }
    for (botr = 1; botr <= n-1; botr++){
        for (botspace = 1; botspace <=botr ;botspace++){
            printf("  ");
        }
        for (botc = 1; botc <=n-botr; botc++){
            printf("# ");
        }
        printf("\n");
    }
        return 0;
}
