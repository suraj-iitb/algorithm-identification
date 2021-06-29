#include<stdio.h>
#include<stdlib.h>
int main(){
    int *a;
    int n,i,j,k=0,c=0,minj;
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(a[j]<a[minj])minj=j;
        }
        if(i!=minj){
            k=a[i];
            a[i]=a[minj];
            a[minj]=k;
            c++;
        }
    }
    for(i=0;i<n-1;i++)printf("%d ",a[i]);
    printf("%d\n%d\n",a[n-1],c);
    free(a);
    return 0;
}
