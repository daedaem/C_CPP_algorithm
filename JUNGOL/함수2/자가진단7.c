#include <stdio.h>
void bbsort(int a[], int len){
    int r, c, idx,temp;
    
    for (r = 0; r < len-1; r++){
        for (c = 0; c < len - r-1 ;c++){
            if (a[c]<a[c+1]){
                temp = a[c];
                a[c] = a[c + 1];
                a[c + 1] = temp;
            }
        }
        for (idx = 0; idx<10; idx++){
            printf("%d ", a[idx]);
        }printf("\n");

    }
};
int main(){
    int idx;
    int a[10];
    for (idx = 0; idx < 10;idx++){
        scanf("%d", &a[idx]);
    }
    bbsort(a, 10);
}
