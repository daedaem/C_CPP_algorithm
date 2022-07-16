#include <stdio.h>

int main(){
    int scores[5][5], r, c, cnt = 0,sum = 0;;
    double avg;
    for (r = 0; r < 5;r++){
        sum = 0;
        for (c = 0; c < 4; c++){
            scanf("%d", &scores[r][c]);
            sum += scores[r][c];
        }
        avg = (double)sum / 4;
        if (avg >=80){
            printf("pass\n");
            cnt++;
        }
        else
            printf("fail\n");
    }
    printf("Successful : %d", cnt);
    return 0;
}