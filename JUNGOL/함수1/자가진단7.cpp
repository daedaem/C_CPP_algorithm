// call-by-reference의 경우 c++파일이어야지 가능함
#include <stdio.h>

int find(int &, int&);
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    find(a, b);
    printf("%d %d", a,b);
    return 0;
}

int find(int &a, int &b){
    if(a<b){
        a *= 2;
        b /= 2;

    }else{
        b *=2 ;
        a /= 2;
    }
    return a, b;
}
