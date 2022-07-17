#include <stdio.h>

void square(int n){
    int r, c, num = 1;
    for (r = 1; r <= n; r++){
        num = r;
        for (c = 0; c < n; c++){
            printf("%d ", num);
            num+=r;
        }
        printf("\n");
    }
}
    

int main(){
    int n;
    scanf("%d", &n);
    square(n);
    return 0;
}

