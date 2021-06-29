#include<stdio.h>

int main(void){
    int i, j;
    int n, q;
    int key, cnt;
    scanf("%d",&n);
    int s[n];
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    cnt = q;
    for(i=0;i<q;i++){
        scanf("%d",&key);
        s[n] = key;
        j = 0;
        while(s[j]!=key){
            j++;
            if(j==n) cnt -= 1;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
