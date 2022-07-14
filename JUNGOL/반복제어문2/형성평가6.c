#include <stdio.h>

int main(){
    int a, b, mins, maxs, cnt=0,sums=0;
    double avg;
    scanf("%d %d", &a, &b);
    if (a<b){
        maxs=b;
        mins=a;
    }
    else{
        maxs=a;
        mins=b;
    }
    for (mins; mins <= maxs; mins++){
        if(mins%3==0 || mins%5==0){
            sums+=mins;
            cnt++;
        }
    }
    printf("sum : %d\n", sums);
    printf("avg : %.1f", (double)sums/cnt);
    return 0;
}


// #include <stdio.h>

// int main(){
//     int idx, a, b, sums=0, cnt=0;
//     scanf("%d %d", &a, &b);
//     if(a<b){
//         for (a; a <= b;a++){
//             if(a%3==0 || a%5==0){
//                 sums += a;
//                 cnt++;
//             }
//         }
//     }
//     else{
//         for (b; b <= a;b++){
//             if(b%3==0 || b%5==0){
//                 sums += b;
//                 cnt++;
//             }
//         }
//     }
//     printf("sum : %d\navg : %.1f", sums , (double)sums/cnt );
//     return 0;
// }
