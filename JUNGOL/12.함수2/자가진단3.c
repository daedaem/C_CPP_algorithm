#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fswap(double &a, double &b){
    double temp;
    temp = a;
    a = b;
    b = temp;
        // a가 작은수가 됨
}
void fcompa(double &a, double &b){
    if (fabs(a) > fabs(b)){
        fswap(a, b);
    }
    printf("%.2f\n", a);
}
void nswap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
        // a가 작은수가 됨
}
void ncompa(int &a, int &b){
    if (abs(a) < abs(b)){
        nswap(a, b);
    }
    printf("%d\n", a);
}
int main(){
    int z, x;
    scanf("%d %d", &z, &x);
    double a, b;
    scanf("%lf %lf", &a, &b);
    ncompa(z, x);
    fcompa(a, b);
}
