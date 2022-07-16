#include <stdio.h>

int main(){
    int fir[2][4];
    int sec[2][4];
    int r, c;
    printf("first array\n");
    for (r = 0; r < 2;r++){
        for (c = 0; c < 4;c++){
            scanf("%d", &fir[r][c]);
        }
    }
    printf("second array\n");
    for (r = 0; r < 2;r++){
        for (c = 0; c < 4;c++){
            scanf("%d", &sec[r][c]);
        }
    };
    for (r = 0; r < 2;r++){
        for (c = 0; c < 4;c++){
            printf("%d ", fir[r][c]*sec[r][c]);
        }
        printf("\n");
    }
    return 0;
}
