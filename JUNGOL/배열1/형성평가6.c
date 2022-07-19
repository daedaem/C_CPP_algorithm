#include <stdio.h>

int main(){
    char c[6] = {'J','U','N','G','O','L'}, word;
    int i,idx;
    scanf(" %c", &word);
    for (i = 0; i < 6;i++){
        if (c[i] == word){
            idx = i;
            printf("%d", idx);
            break;
        }
        else{
            if(i == 5 && c[i]!=word){
            printf("none");        
            };
        }
    }
    return 0;
}
// #include <stdio.h>

// int main(){
//     char c[6] = {'J','U','N','G','O','L'}, word;
//     int i,idx=-1;
//     scanf(" %c", &word);
//     for (i = 0; i < 6;i++){
//         if (c[i] == word){
//             idx = i;
//             printf("%d", idx);
//             break;
//         }
//     }
//     if(idx==-1){
//         printf("none");
//         }
//     return 0;
// }

