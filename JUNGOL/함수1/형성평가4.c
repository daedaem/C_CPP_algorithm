#include <stdio.h>
int calc(int a, int b){
    int result;
    if (a>b){
        result = a * a - b * b;
    }
    else{
        result = b * b - a * a;
    }
    return result;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", calc(a, b));
}

