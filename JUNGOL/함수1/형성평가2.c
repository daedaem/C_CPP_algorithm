#include <stdio.h>

void sum(int n){
    int start, sums=0;
    for (start = 1; start <= n;start++){
        sums += start;
    }
    printf("%d", sums);
}
int main(){
    int n;
    scanf("%d", &n);
    sum(n);
    return 0;
}

