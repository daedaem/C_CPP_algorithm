#include <stdio.h>

int main(){
    int idx, a;
    scanf("%d", &a);
    for (idx=1; idx<=10; idx++){
        printf("%d ", a*idx);
    }
    return 0;
}

// #include <stdio.h>

// int main(){
//     int a, idx;
//     scanf("%d", &a);
//     for (idx = 1; idx <= 10; idx++){
//         printf("%d ", idx * a);
//     }
//         return 0;
// }