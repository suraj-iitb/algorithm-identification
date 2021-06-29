#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int flag=1,a[101],n,i,j,z,sort=0;
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    while(flag != n-1){
        
        for(j=n;j>=2;j--){
            if(a[j]<a[j-1]){
                z = a[j];
                a[j] = a[j-1];
                a[j-1] = z;
              
                sort++; 
            }
        }
        flag = 0;
        for(i=1;i<=n-1;i++){
            if(a[i]<=a[i+1]) flag++;
        }
    }
    for(i=1;i<=n-1;i++) printf("%d ",a[i]);
    printf("%d\n",a[n]);
    printf("%d\n",sort);
    return 0;
}
