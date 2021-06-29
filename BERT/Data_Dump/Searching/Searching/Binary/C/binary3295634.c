#include <stdio.h>
#define MAX1 100000
#define MAX2 50000

int main(void)
{
    int a[MAX1];
    int b[MAX2];
    int left;
    int right;
    int mid;
    int n,q,i;
    int count=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&b[i]);
    }
    for(i=0;i<q;i++){
    left=0;
    right=n;
    while(1){
        mid=(left+right)/2;
        if(left==right) break;
        if(a[mid]==b[i]){
            count++;
            break;
        } 
        else if(a[mid]<b[i]){
            left=mid+1;
        } 
        else{
            right=mid;
        } 
      }
    }
    
    printf("%d\n",count);
    return 0;
}

