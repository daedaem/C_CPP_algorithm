#include <stdio.h>

void results(int, int);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    results(a, b);
    return 0;
}

void results(int a, int b){
    int sum = 1,num;
    for (num = 0; num < b;num++){
        sum *= a;
    }
    printf("%d", sum);
}
