#include <stdio.h>

int main(void){
    int n,i,j,count=0,k,min,num;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        min = a[i];
        num = i;
        for(j=i+1;j<n;j++){
            if(min>a[j]){
                min = a[j];
                num = j;
                
            }
        }
        if(num!=i){
            count++;
            k=a[i];
            a[i]=a[num];
            a[num]=k;
        }
    }
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf("\n%d\n",count);
    return 0;
}

