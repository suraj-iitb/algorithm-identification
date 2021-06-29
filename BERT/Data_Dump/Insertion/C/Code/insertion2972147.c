#include <stdio.h>
void copy(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        if(i>0)
            printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

int main(){
    int n;scanf("%d",&n);
    int i,j,v,a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    copy(a,n);
    for(i=1;i<n;i++){
        v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=v;
        copy(a,n);
    }
}

