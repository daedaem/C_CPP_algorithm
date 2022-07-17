#include <stdio.h>
void findMax(int,int,int);

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    findMax(a, b, c);
    return 0;
}

void findMax(int a,int b,int c){
    if(a>b){
        if(b>c){
            printf("%d", a);
        }
        else{
            if(c>a){
                printf("%d", c);
            }
            else{
                printf("%d", a);
            }
        }
    }
    else{
        if(a>c){
            printf("%d", b);
        }
        else{
            if(b>c){
                printf("%d", b);
            }
            else{
                printf("%d", c);
            }
        }
    }
}

