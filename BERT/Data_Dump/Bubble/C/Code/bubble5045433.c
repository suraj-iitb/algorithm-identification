#include<stdio.h>
int main(){
    int *a;
    int n,i,j,k=0,c=0;
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    
    for(i=0;i<n;i++){
        for(j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                k=a[j];
                a[j]=a[j-1];
                a[j-1]=k;
                c++;
            }
        }
    }
    for(i=0;i<n-1;i++)printf("%d ",a[i]);
    printf("%d\n%d\n",a[n-1],c);
    free(a);
    return 0;
}
