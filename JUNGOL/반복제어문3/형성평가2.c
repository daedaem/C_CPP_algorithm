#include <stdio.h>

int main(){
    int n,idx;
    scanf("%d", &n);
    for (idx=1; ;idx++){
        if(n*idx%10==0){
        printf("%d ", n*idx);
        break;
        }
        else{
        printf("%d ", n*idx);
        }
    }
    return 0;
}   