#include <stdio.h>

int main(){
    int n,r,botr,botc,idx;
    scanf("%d", &n);
    for (idx=1; idx<=n; idx++){
        for (r=1; r<=idx; r++){
            printf("*");
        }
        printf("\n");
    }
    for (botr=n-1; botr>=1; botr--){
        for(botc=1; botc<=botr; botc++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
