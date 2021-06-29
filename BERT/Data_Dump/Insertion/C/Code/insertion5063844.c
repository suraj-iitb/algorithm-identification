#include <stdio.h>
int main()
{
    int a[100];
    int i,j,k;
    int p,q;
    scanf("%d",&p);
    for(i=0;i<p;i++){
        scanf("%d",&a[i]);
    }
        for(i=0;i<p;i++) {
            q=a[i];
            j=i-1;
        while(j>=0 && a[j]>=q) {
                a[j+1]=a[j];
                j--;
                a[j+1]=q;
            }
        for(k=0;k<p-1;k++){
                printf("%d ",a[k]);
                }
            printf("%d\n",a[k]);
        }
        return 0;
    }

