#include <stdio.h>
int  masum =0, ensum =0, kosum = 0;
int a[3][3];
void totl(int ma, int en, int ko){
    printf("%d %d %d %d\n", ma, en, ko, ma + en + ko);
}

int main(){
    int sumOfStd=0;
    int ma, en, ko,r,c;
    for (r = 0; r < 3; r++){
        for (c=0; c<3; c++){
            scanf("%d", &a[r][c]);
        }
    }
    for (r=0; r<3; r++){
        totl(a[r][0], a[r][1], a[r][2]);
        masum += a[r][0];
        ensum += a[r][1];
        kosum += a[r][2];
    }
    totl(masum, ensum, kosum);
    return 0;
}

