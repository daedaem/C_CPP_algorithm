#include <stdio.h>

int main(){
    int a, b, mins, maxs, cnt=0,sums=0;
    double avg;
    scanf("%d %d", &a, &b);
    if (a<b){
        maxs=b;
        mins=a;
    }
    else{
        maxs=a;
        mins=b;
    }
    for (mins; mins <= maxs; mins++){
        if(mins%3==0 || mins%5==0){
            sums+=mins;
            cnt++;
        }
    }
    printf("sum : %d\n", sums);
    printf("avg : %.1f", (double)sums/cnt);
    return 0;
}
