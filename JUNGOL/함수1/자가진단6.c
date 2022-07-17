#include <stdio.h>

void calc(int, char, int);
int main(){
    int a, b;
    char c;
    scanf("%d %c %d", &a, &c, &b);
    calc(a, c, b);
    return 0;
}

void calc(int a, char c, int b){
    if(c=='+'){
        printf("%d %c %d = %d", a, c, b, a + b);
    }
    else if(c=='-'){
        printf("%d %c %d = %d", a, c, b, a - b);
    }
    else if(c=='*'){
        printf("%d %c %d = %d", a, c, b, a * b);
    }
    else if(c=='/'){
        printf("%d %c %d = %d", a, c, b, a / b);
    }
    else{
        printf("%d %c %d = %d", a, c, b, 0);
    }
};
