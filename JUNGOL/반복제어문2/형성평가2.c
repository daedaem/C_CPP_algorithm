/* 아래(42ms)보다 위(4ms)가 실행시간이 더 빠른 것으로 보아(사용메모리는 같음), 조건, 반복문이 같이 돌아가게 되는 것보다 
나눠 작성하는 것이 효율적인듯.*/

#include <stdio.h>
int main(){
    int a, b, maxN, minN;
    scanf("%d %d", &a, &b);
    if(a<b){
        maxN = b;
        minN = a;
    }
    else{
        maxN = a;
        minN = b;
    }
    
    for (minN <= maxN; minN++){
        printf("%d ", minN);
    }
    return 0;
}

// #include <stdio.h>

// int main(){
//     int a, b;
//     scanf("%d %d", &a, &b);
//     if (a<b){
//         for (a; a <= b;a++){
//             printf("%d ", a);
//         }
//     }
//     else{
//         for (b; b <= a;b++){
//             printf("%d ", b);
//         }
//     }
//     return 0;
// }



// #include <stdio.h>

// int main(){
//     int a, b, smaller, bigger;
//     scanf("%d %d", &a, &b);
//     if(a<b){
//         smaller = a;
//         bigger = b;
//     }
//     else{
//         smaller = b;
//         bigger = a;
//     }
//     for (smaller; smaller <= bigger; smaller++)
//     {
//         printf("%d ", smaller);
//     }
//     return 0;
// }