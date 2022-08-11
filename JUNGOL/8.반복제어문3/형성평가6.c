#include <stdio.h>

int main(){
    int n, r,c, numb;
    scanf("%d", &n);
    for (r = 1; r <= n; r++){
        for (c = 1; c <= n-r;c++){
            printf("  ");
        }
        for (numb = 1; numb <= r; numb++){
            printf("%d ", numb);
        }
        printf("\n");
    }
        return 0;
}
