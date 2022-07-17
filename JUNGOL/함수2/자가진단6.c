#include <stdio.h>
#define one 1
#define two 2
#define three 3

int main(){
    int r,c;
    for (r = one; r <= three;r++){
        for (c = one; c <= three;c++){
            printf("%d + %d = %d\n",r,c, r+c);
        }
    }
    return 0;
}
