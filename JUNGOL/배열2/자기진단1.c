# include <stdio.h>

int main(){
    int n,idx;
    char in,cc[26]={0};
    for (n=1; n<=100; n++){
        scanf(" %c",&in);
        if(in - 'A'<0 || in-'A' > 25){
            for(idx=0; idx<26; idx++){
                if(cc[idx]>0){
                    printf("%c : %d\n",idx+'A', cc[idx]);
                }
            }
            break;
        }
        else{
            cc[in - 'A']++;
        }
    }
    return 0;
}
