#include <stdio.h>

int main(){
    int r,c, n;
    scanf("%d", &n);
    for (r = n; r >= 1; r--){
        for(c=0; c<n-r; c++){
            printf("%c",' ');
        }
        for(c=0; c<r; c++){
            printf("%c",'*');
        }
        printf("\n");
    }
    return 0;
}
