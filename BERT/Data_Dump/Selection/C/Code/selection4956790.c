#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

int main(void){
    int n,t,cnt;
    scanf("%d",&n);
    int a[n];
    int min;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(a[i]!=a[min]){
        t=a[i];
        a[i]=a[min];
        a[min]=t;
        cnt++;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=0)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    printf("%d\n",cnt);
return 0;
}
