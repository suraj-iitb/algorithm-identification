#include<stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    int flag = 1, i, temp;
    int c = 0;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    while(flag){
        flag = 0;
        for(i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                flag = 1;
                c++;
            }
        }
    }
    for(i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n%d\n",a[n-1],c);
    return 0;
}
