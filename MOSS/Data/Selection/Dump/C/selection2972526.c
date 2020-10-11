#include <stdio.h>
int main(){
    int i,j;
    int n;
    scanf("%d",&n);
    int a[n],v,cnt=0;
    int minj;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++)
            if(a[j]<a[minj])
              minj=j;
        v=a[i];
        a[i]=a[minj];
        a[minj]=v;
        if(minj!=i)
            cnt++;
    }
    for(i=0;i<n;i++)
    {
        if(i>0)
        printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",cnt);
}
