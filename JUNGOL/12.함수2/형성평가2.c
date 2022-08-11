#include <stdio.h>
#include <math.h>

int main(){
    double a, b,temp;
    scanf("%lf %lf", &a, &b);
    a = sqrt(a);
    b = sqrt(b);

    int fi, se;
    if (a>b){
        temp = a;
        a = b;
        b = temp;
    }

    int idx, cnt=0;

    if (a == (int)a){
        for (idx = (int)a; idx <= b; idx++){
            cnt++;
        }
    }
    else{
        for (idx = (int)a+1; idx <= b; idx++){
            cnt++;
        }
    }
    printf("%d", cnt);
}
