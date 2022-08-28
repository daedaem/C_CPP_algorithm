#include <stdio.h>

int main(){
    int n, r,c,numb=1;
    scanf("%d", &n);
    for (r = 1; r <= n; r++){
        for (c = 1; c <= n; c++){
            printf("%d ", numb);
            numb += 2;
            if(numb>10){
                numb = 1;
            }
        }
        printf("\n");
    }
        return 0;
}
