#include <stdio.h>

int main(void){
    int len,score=0,i,j,k,buf=0;
    scanf("%d", &len);
    int ary[len];
    for(i=0;i<len;i++) scanf("%d", &ary[i]);
    for(j=len-1;j>=0;j--){
        for(k=0;k<j;k++){
            if (ary[k] > ary[k+1]){
                buf=ary[k], ary[k]=ary[k+1], ary[k+1]=buf;
                score++;
            }
        }
    }
    for(i=0;i<len;i++){(i<len-1)? printf("%d ",ary[i]) : printf("%d", ary[i]);}
    printf("\n%d\n", score);
    return 0;
}
