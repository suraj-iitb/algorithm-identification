#include <stdio.h>

int main(){
    int i,j,k,n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i <n ; ++i) {
        scanf("%d",&a[i]);
    }
    int count,temp,check;
    count=0;
    check=1;
    for (int j = 0; j < n; j++) {
        if(check==0) break;
        check=0;
        for (int k = (n-1); j < k;k--) {
            
            if (a[k]<a[k-1]){
                temp=a[k-1];
                a[k-1]=a[k];
                a[k]=temp;
                count++;
                check=1;

            }
        }
    }
    for(i=0;i<n;i++){

    if(i==(n-1))printf("%d",a[i]);
    else {printf("%d",a[i]);printf(" ");}
    }

    printf("\n");
    printf("%d",count);
    printf("\n");
    return 0;
    
}
