#include <stdio.h>

void gogodan(int );
int main(){
    int a, b, minn, maxx;
    scanf("%d %d", &a, &b);
    if (a<b){
        minn = a;
        maxx = b;
    }
    else{
        minn = b;
        maxx = a;
    }
    for (a=minn; a <= maxx;a++){
        gogodan(a);
    }
}
void gogodan(int n){
    int r, c;
    printf("== %ddan ==\n",n);
    for (r = 1; r <= 9;r++){
        printf("%d * %d = %2d\n", n, r, n * r);
    }
    printf("\n\n");
};

