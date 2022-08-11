#include <stdio.h>

int main(){
    int i,j, a;
    scanf("%d", &a);
    for (i=1; i<=a; i++){
        for (j=1; j<=a; j++){
            printf("(%d, %d) ", i, j);
        }
        printf("\n");
    }
    return 0;
}

// #include <stdio.h>

// int main(){
//     int idxr,idxc, a;
//     scanf("%d", &a);
//     for (idxr = 1; idxr <= a; idxr++){
//         for (idxc = 1; idxc <= a; idxc++){
//             printf("(%d, %d) ",idxr, idxc);
//         }
//         printf("\n");
//     }

//         return 0;
// }