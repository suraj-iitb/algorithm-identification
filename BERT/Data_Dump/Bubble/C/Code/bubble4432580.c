#include<stdio.h>
int main(){
    int i,j,n,a[101],t,p=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                p++;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i==n-1){printf("\n");}
        else{printf(" ");}
    }
    printf("%d\n",p);
}
