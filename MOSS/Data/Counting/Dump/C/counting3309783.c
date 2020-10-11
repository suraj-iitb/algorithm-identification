#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int b[MAX],c[MAX];

void countingsort(int a[],int b[],int k,int n){
    int i,j;
    for(i=0;i<=k;i++){
        c[i]=0;
    }
    for(j=1;j<=n;j++){
        c[a[j]]++;
    }
    for(i=1;i<=k;i++){
        c[i]=c[i]+c[i-1];
    }
    for(j=n;j>=1;j--){
        b[c[a[j]]]=a[j];
        c[a[j]]--;
    }
    for(i=1;i<=n;i++){
        if(i>1)printf(" ");
        printf("%d",b[i]);
    }
    printf("\n");
}

int main(){
    int a[MAX];
    int n,i,j,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i+1]);
        if(k<a[i])k=a[i];
    }
    countingsort(a,b,k,n);
    
    return 0;
}


