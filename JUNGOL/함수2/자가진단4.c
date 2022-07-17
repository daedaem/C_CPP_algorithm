#include <stdio.h>
#include <math.h>

double calcR(int sq){
    double const PI = 3.14;
    double r;
    r= sqrt(sq / 3.14 );
    return r;
}

int main(){
    int sq;
    scanf("%d", &sq);
    printf("%.2f", calcR(sq));
    return 0;
}
