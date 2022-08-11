#include <stdio.h>

int main(){
    int a[100],i,cnt=0,sum=0;
    for (i = 0; i < 100;i++){
        scanf("%d", &a[i]);
        if (a[i]==0){
            printf("Multiples of 5 : %d\nsum : %d\navg : %.1f",cnt, sum, (double)sum/cnt);
            break;
        }
        else{
            if(a[i]%5==0){
                cnt++;
                sum += a[i];
            }
        }
    }
    return 0;
}

// #include <stdio.h>

// int main(void){
//     int a[100],idx;
//     int cnt = 0, sum = 0;
//     for (idx = 0; idx < 100; idx++){
//         scanf("%d", &a[idx]);
//         if (a[idx]==0){
//             printf("Multiples of 5 : %d\n", cnt);
//             printf("sum : %d\n", sum);
//             printf("avg : %.1f", (double)sum/cnt);
//             break;
//         }
//         else if (a[idx]%5==0){
//             cnt++;
//             sum += a[idx];
//         }
//     }
// }