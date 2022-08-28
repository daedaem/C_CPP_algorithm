// #include <stdio.h>

// void sorte(int arr[], int len){
//     int r, c, temp;
//     for (r = 0; r < len;r++){
//         for (c = 0; c<len-r-1; c++){
//             if (arr[c] < arr[c+1]){
//                 temp = arr[c];
//                 arr[c] = arr[c + 1];
//                 arr[c + 1] = temp;
//             }
//         }
//     }
// }

// int input(int arr[], int n){
//     int idx;
//     for (idx = 0; idx < n;idx++){
//         scanf("%d", &arr[idx]);
//     }
// }
// int output(int arr[], int a){
//     int idx;
//     for (idx = 0; idx < a;idx++){
//         printf("%d ", arr[idx]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int arr[10];
//     input(arr, n);
//     sorte(arr, n);
//     output(arr, n);
// }

#include <stdio.h>

void sort(int arr[], int len){
    int r, c,temp;
    for (r = 0; r < len-1;r++){
        for (c = r+1; c < len;c++){
            if(arr[r] < arr[c]){
                temp = arr[r];
                arr[r] = arr[c];
                arr[c] = temp;
            }
        }
    }
}
int main(){
    int n, idx;
    int arr[10];
    scanf("%d", &n);
    for (idx = 0; idx < n; idx++){
        scanf("%d", &arr[idx]);
    }
    sort(arr, n);
    for (idx = 0; idx < n;idx++){
        printf("%d ", arr[idx]);
    }
    return 0;
}

