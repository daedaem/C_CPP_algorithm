#include <stdio.h>

int main(){
    int i, j,numb;
    int a[100] = {0};
    while(1){
        scanf("%d", &numb);
        if (numb==0){
            for (i = 0; i < 10; i++){
                if (a[i]>=1){
                printf("%d : %d\n", i, a[i]);
                }
            }
            break;
        }
        else{
            if (numb>=10){
                a[numb / 10]++;
            }
            else{
                a[0]++;
            }
        }
    }
    return 0;
}
