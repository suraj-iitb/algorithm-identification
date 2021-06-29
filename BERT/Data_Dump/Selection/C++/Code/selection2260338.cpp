#include <stdio.h>
#define N 100


int main(){

    int i,j,n,a[N],b,min,count=0,flag=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        min = i;
        for(j=i;j<n;j++){
            if(a[min]>a[j]){
                min = j;
                flag=1;
            }
        }
        if(flag==1){
            count++;
            flag=0;
        }
        b = a[i];
        a[i] = a[min];
        a[min] = b;
    }
    for(i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
      printf("%d\n%d",a[n-1],count);
      printf("\n");
    
      return 0;
}
