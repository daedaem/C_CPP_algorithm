#include <stdio.h>

int main(){
    int a, b, cols,rows;
    scanf("%d %d", &a, &b);
    for(cols=1; cols<=a; cols++){
        for(rows=1; rows<=b; rows++){
            printf("%d ",rows*cols);
        }
        printf("\n");
    }
    return 0;
}

// #include <stdio.h>

// int main(){
//     int r, c, idxr, idxc;
//     scanf("%d %d", &r, &c);
//     for (idxr = 1; idxr <= r; idxr++){
//         for (idxc = 1; idxc <= c; idxc++){
//             printf("%d ", idxr*idxc);
//         }
//         printf("\n");
//     }
//         return 0;
// }