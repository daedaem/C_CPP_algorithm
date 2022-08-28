#include <stdio.h>

int main(){
    int n,idx, num,sum=0;
    double avg;
    scanf("%d",&n);
    for (idx=1; idx<=n; idx++){
        scanf("%d",&num);
        sum+=num;
    }
    avg = (double)sum / n;
    printf("%.2f", avg);
    //printf("%.2f", (double)sum/)
    return 0;
}

// #include <stdio.h>

// int main(){
//     int n, idx, a, sums=0, cnt=0;
//     scanf("%d", &n);
//     for (idx = 1; idx <= n; idx++){
//         scanf("%d", &a);
//         sums += a;
//         cnt++;
//     }
//     printf("%.2f", (double)sums / cnt);
//     return 0;
// }