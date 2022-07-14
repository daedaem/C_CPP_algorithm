#include <stdio.h>

int main(){
    int n, left, right, rows, stars;
    scanf("%d", &n);
    for (rows=0; rows<n; rows++){
        for(left=0; left<rows;left++){
            printf("%c", ' ');
        }

        for(stars=1; stars<=(n-rows)*2-1; stars++){
            printf("*");
        }

        for(right=0; right<rows;right++){
            printf("%c", ' ');
        }
        printf("\n");

    }
    return 0;
}
