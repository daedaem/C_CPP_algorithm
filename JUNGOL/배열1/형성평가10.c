#include <stdio.h>

int main(){
    int a[20],idx,n;
    int r, c;
    int temp;
    scanf("%d", &n);
    for (idx = 0; idx < n;idx++){
        scanf("%d", &a[idx]);
    }
    for (r = 0; r < n;r++){
        for (c = r+1; c < n; c++){
            if (a[r]< a[c]){
                temp = a[r];
                a[r] = a[c];
                a[c] = temp;
            }
        }
    }
    for (idx = 0; idx < n;idx++){
        printf("%d\n", a[idx]);
    }
    return 0;
} 