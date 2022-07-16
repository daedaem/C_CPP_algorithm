// #include <stdio.h>
// int main(){
//     int a[15] = {5, 8, 10, 6, 4, 11, 20, 1, 13, 2, 7, 9, 14, 22, 3}, idx, cnt=1;
//     for (idx = 0; idx < 15;idx++){
//         printf("%2d   ", a[idx]);
//         if (cnt % 5 == 0)
//         {
//             printf("\n");
//         }
//         cnt++;
//     }
//     return 0;
//     }

#include <stdio.h>

int main(){
    int a[3][5] = {{5, 8, 10, 6, 4}, {11, 20, 1, 13, 2}, {7, 9, 14, 22, 3}};
    int r, c;
    for (r = 0; r < 3; r++){
        for (c = 0; c < 5; c++){
            printf("%2d%3c", a[r][c],' ');
        }
        printf("\n");
    }
    return 0;
}
