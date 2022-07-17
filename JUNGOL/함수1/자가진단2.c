#include <stdio.h>
int r;
void square(int);
int main(){
    scanf("%d", &r);
    square(r);
    return 0;
}

void square(int r){
    printf("%.2f", (double) r*r * 3.14);
};
