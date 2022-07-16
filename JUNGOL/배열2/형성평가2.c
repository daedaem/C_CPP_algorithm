#include <stdio.h>

int main(){
    int std[100]={0},idx,len, num;
    int scores[11] = {0};
    for (idx = 0; idx < 100;idx++){
        scanf("%d", &num);
        if (num==0){
            break;
        }
        else {
            std[idx] = num;
            scores[num/10]++;
        }
    }
    for (idx = 10; idx >= 0; idx--){
        if (scores[idx]!=0) {
            printf("%d : %d person\n", idx * 10, scores[idx]);
        }
    }
    return 0;
}


// #include <stdio.h>

// int main(){
//     int std[100],idx,len, num;
//     int scores[11] = {0};
//     for (idx = 0; idx < 100;idx++){
//         scanf("%d", &num);
//         if (num==0){
//             len = idx+1;
//             break;
//         }
//         else {std[idx] = num;}
//     }
//     for (idx = 0; idx < len;idx++){
//         prinf("%d ", std[idx]);
//     }
//         for (idx = 0; idx < len; idx++)
//         {
//             scores[std[idx] / 10]++;
//             // printf("%d : %d person\n", );
//         }

//     for (idx = 10; idx >= 0; idx--){
//         if (scores[idx]!=0) {
//             printf("%d : %d person\n", idx * 10, scores[idx]);
//         }
//     }
//     return 0;
// }