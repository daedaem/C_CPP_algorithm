#include <stdio.h>

int main(){
    int a, b, cols,rows;
    scanf("%d %d", &a, &b);
    for(cols=1; cols<=a; cols++){
        for(rows=1; rows<=b; rows++){
            printf("%d ",rows*cols);
        }
        printf("\n");
    }
    return 0;
}