#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int tmp;
    int a[111];
    int i;
    for(i=0;i<n;i++) scanf("%d",a+i);
    
    int flg = 1, cnt = 0;
    while(flg){
        flg=0;
        for(i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                cnt = cnt + 1;
                flg = 1;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d%c",a[i]," \n"[i==n-1]);
    }
    printf("%d\n",cnt);
    
}
