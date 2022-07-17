#include <stdio.h>
#define count 7
int main(){
    int idx,r,temp;
    int arr[count];
    for (idx = 0; idx < count;idx++){
        scanf("%d", &arr[idx]);
    }
    for (r = 0; r < 3; r++){
        for (idx = 0; idx < count-1; idx++){
            if(arr[idx] > arr[idx+1]){
                temp = arr[idx];
                arr[idx] = arr[idx + 1];
                arr[idx + 1] = temp;
            }
        }
    }
    for (idx = 0; idx < count; idx++){
        printf("%d ", arr[idx]);
    }
    return 0;
}
