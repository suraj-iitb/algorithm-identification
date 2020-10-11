#include<stdio.h>
int main(void){
    int n,i,j,v,cnt,minj,temp,fmin;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    cnt=0;
    for(i=0;i<n;i++){
        minj=i;
        fmin=minj;
        for(j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        temp=a[i];
        a[i]=a[minj];
        a[minj]=temp;
        if(fmin!=minj){
            cnt++;
        }
    }
    for(i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[n-1]);
    printf("%d\n",cnt);
    return 0;
}
