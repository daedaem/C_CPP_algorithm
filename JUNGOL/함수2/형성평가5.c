#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    double a, b, c;
    double sum = 0;
    scanf("%lf %lf %lf", &a, &b, &c);
    sum += a + b + c;
    printf("%d\n", (int)round(sum/3));
    a = round(a);
    b = round(b);
    c = round(c);
    sum = a + b + c;
    double avg;
    avg = round(sum / 3);
    printf("%.0f", avg);
}
