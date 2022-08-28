// #include <stdio.h>
// #define PI 3.141592
// #define Square(r) (double)r*r*PI
// int main(){
//     double r;
//     double sq;
//     printf("radius : ");
//     scanf("%lf", &r);
//     sq = Square(r);
//     printf("area = %.3f", sq);
// }

#include <stdio.h>
#define PI 3.141592
#define Square(r) r*r*PI
int main(){
    double r;
    printf("radius : ");
    scanf("%lf", &r);
    printf("area = %.3f", Square(r));
}
