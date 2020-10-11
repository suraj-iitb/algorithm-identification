#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);

    int a[111];
    int i;
    for(i=0;i<n;i++) scanf("%d",a+i);
    
    int flg = 1, cnt = 0;
    while(flg){
        flg = 0;
        int j;
        for(j = n - 1; j > 0; j--){
        if(a[j] < a[j - 1]){
            int tmp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = tmp;
            flg = 1;
            cnt = cnt + 1;
        }
        }
       
    }
    for(i=0;i < n;i++) printf("%d%c",a[i]," \n"[i==n - 1]);
    printf("%d\n", cnt);
}

