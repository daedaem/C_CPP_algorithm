#include <stdio.h>

void square(int);
int r, c,num=1;
int main(){
    int n;
    scanf("%d", &n);
    square(n);
    return 0;
}
void square(int n)
{
    for (r = 0; r < n;r++){
        for (c = 0; c < n;c++){
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}
