#include <stdio.h>
int selectionsort(int a[],int n)
{
    int i,j,t,sw=0,minj;
    for(i=0;i<n-1;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(a[j]<a[minj])minj=j;
        }
        t=a[i];
        a[i]=a[minj];
        a[minj]=t;
        if(i!=minj)sw++;
    }
    return sw;
}
int main(){
    int a[100],n,i,sw;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
        scanf("%d",&a[j]);
    sw=selectionsort(a, n);
    for(i=0;i<n;i++){
        if(i>0)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    printf("%d\n",sw);
    return 0;
}

