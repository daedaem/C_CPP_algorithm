#include <stdio.h>

int main(){
    int n, idx, even=0, odd=0;
    for (idx=1; idx<=10; idx++){
        scanf("%d", &n);
        if(n%2==1){
            odd++;
        }
        else{
            even++;
        }
    }
    printf("even : %d\nodd : %d", even, odd);

    return 0;
}
