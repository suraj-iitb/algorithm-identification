#include<stdio.h>
#include<stdlib.h>

#define scan(n) scanf("%d",&n);

int main(void){
    int n,t;
    scan(n);
    int a[n];
    int cnt=0;
    for(int i=0;i<n;i++)scan(a[i]);

    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
                cnt++;
            }
        }
    }

    for(int j=0;j<n;j++){
        if(j!=0)printf(" ");
        printf("%d",a[j]);
}
printf("\n");
printf("%d\n",cnt);
return 0;
}
