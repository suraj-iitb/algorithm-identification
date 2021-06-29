#include<stdio.h>
slectionSort(int a[],int n){ 
    int i,j,tmp,count=0,minj;
    for(i=0;i<n-1;i++){
        minj=i;
        for(j=i;j<n;j++){   
            if(a[j] < a[minj]){
                minj=j;
            }
        }
        tmp=a[i];
        a[i]=a[minj];
        a[minj]=tmp;
        if(i!=minj){
            count++;    
        }
    } 
    return count;
}
int main(void){
    int a[100],n,i,count;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    count=slectionSort(a,n);
    for(i=0;i<n;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",a[i]);
        
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}
