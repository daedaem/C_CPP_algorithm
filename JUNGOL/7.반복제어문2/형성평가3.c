#include <stdio.h>

int main(){
    int n,idx, sum=0;
    scanf("%d", &n);
    for (idx=1; idx<=n; idx++){
        if(idx%5==0){
            sum+=idx;
        }
    }
    printf("%d", sum);
    return 0;
}
// #include <stdio.h>

// int main(){
//     int a, idx, sums=0;
//     scanf("%d", &a);
//     for (idx=1; idx <= a; idx++)
//     {
//         if(idx%5==0){
//             sums += idx;
//         }
//     }
//     printf("%d ", sums);
//     return 0;
// }