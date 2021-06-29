#include <stdio.h>
int a[10001],count=0;
int s(int b,int n){
    int j;
    for(j=0;j<n;j++){
        if(a[j]==b){
            count++;
            break;
        }
    }
    return count;
}
int main(void){
    int n,m,i,b,count;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&b);
        count = s(b,n);
    }
    printf("%d\n",count);
    return 0;
}
