#include<stdio.h>
int main(){
    int i,j,n,a[101],t,minj,p=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(a[minj]>a[j]){
                minj=j;
            }
        }
        if(i!=minj){
                t=a[i];
                a[i]=a[minj];
                a[minj]=t;
                p++;
        }
    }
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i==n-1){printf("\n");}
        else{printf(" ");}
    }
    printf("%d\n",p);
}
