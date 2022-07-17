#include <stdio.h>
#include <math.h>

void sort(double &a, double &b, double&c){
    double minn,center,maxx;
    if (a<b){
        if(c<b){
            maxx=b;
            if(c>a){
                center=c;
                minn=a;
            }
            else{
                center=a;
                minn=c;
            }
        }else{
            maxx=c;
            center=b;
            minn=a;
        }
    }
    else{
        if(c>a){
            maxx=c;
            center=a;
            minn=b;
        }
        else{
            if(c>b){
                maxx=a;
                center=c;
                minn=b;
            }else{
                maxx=a;
                center=b;
                minn=c;
            }
        }
    }
    a=maxx;
    b=center;
    c=minn;
}
int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a,&b,&c);
    sort(a,b,c);
    printf("%d ",(int)ceil(a));
    printf("%d ",(int)floor(c));
    printf("%d ",(int)round(b));
    return 0;
}
