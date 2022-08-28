#include <stdio.h>
#include <math.h>
#define micalc pow((a-b),2)
#define sumcalc pow((a+b),3)

int main(){
    int a, b;
    double mi, su;
    scanf("%d %d", &a, &b);
    mi = micalc;
    su = sumcalc;
    printf("(%d - %d) ^ 2 = %.0f\n", a, b, mi);
    printf("(%d + %d) ^ 3 = %.0f\n", a, b, su);
}
