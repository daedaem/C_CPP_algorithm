#include <stdio.h>

int main(){
    int arr1[2][3],arr2[2][3], r,c;
    printf("first array\n");
    for(r=0; r<2;r++){
        for(c=0; c<3;c++){
            scanf("%d", &arr1[r][c]);
        }
    }
    printf("second array\n");
    for(r=0; r<2;r++){
        for(c=0; c<3;c++){
            scanf("%d", &arr2[r][c]);
        }
    }
    for(r=0; r<2;r++){
        for(c=0; c<3;c++){
            printf("%d ", arr1[r][c]*arr2[r][c]);
        }
        printf("\n");
    }
}
