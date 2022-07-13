#include <stdio.h>

int main(){
    int a, b,idx, temp;
    scanf("%d %d", &a, &b);
        for (idx=1; idx<=9; idx++){
            if (a<b){
                for (temp=a; temp<=b; temp++){
                    printf("%d * %d =%3d%3c", temp, idx, temp*idx, ' ');
                }
            }
            else{
                for (temp=a; temp>=b; temp--){
                    printf("%d * %d =%3d%3c", temp, idx, temp*idx, ' ');
                }
            }
            printf("\n");
        }
    return 0;
}
