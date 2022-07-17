#include <stdio.h>
void printWord();

int main(){
    int idx,rep;
    scanf("%d", &rep);
    for (idx = 0; idx < rep; idx++){
        printWord();
    }
    return 0;
}

void printWord(){
    printf("~!@#$^&*()_+|\n");
};