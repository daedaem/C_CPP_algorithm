#include <stdio.h>

int main(){
    char arr[3][5], cc;
    int r, c;
    for (r = 0; r < 3; r++){
        for (c = 0; c < 5;c++){
            scanf(" %c", &cc);
            arr[r][c] = (char)cc + 32;
        }
    }
    for (r = 0; r < 3; r++){
        for (c = 0; c < 5;c++){
            printf("%c ",arr[r][c]);
        }
        printf("\n");
    }

    return 0;
}
