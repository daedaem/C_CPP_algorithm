#include <stdio.h>

int main(){
    int a[10], i, odd=0, even=0;
    for (i = 0; i<10; i++){
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 10; i++){
        if(i%2==0){
            odd += a[i];
        }
        else{
            even += a[i];
        }
    }
    printf("odd : %d\neven : %d", odd, even);
    return 0;
}