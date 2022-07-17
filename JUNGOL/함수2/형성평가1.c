#include <stdio.h>

void input(int arr[], int N){
    int idx;
    for (idx = 0; idx < N; idx++){
        scanf("%d", &arr[idx]);
    }
};
void sort(int arr[], int N){
    int temp,r,c;
    for (r = 0; r < N - 1;r++){
        for (c = 0; c < N - 1 - r;c++){
            if (arr[c] < arr[c+1]){
                temp = arr[c];
                arr[c] = arr[c + 1];
                arr[c + 1] = temp;
            }
        }
    }
};

void output(int arr[], int N){
    int c;
    for (c = 0; c < N;c++){
        printf("%d ", arr[c]);
    }
}
int main(){
    int N;
    int arr[15];
    scanf("%d", &N);
    input(arr, N);
    sort(arr, N);
    output(arr,N);
}
