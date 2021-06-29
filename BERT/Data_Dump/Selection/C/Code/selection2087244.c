#include<stdio.h>

int main(){
    
    int N;
    int i,j,k,v;
    int min;
    int count=0;
    int check;
    
    scanf("%d",&N);
    
    int a[N];
    
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<N;i++){
        min=i;
        check=i;
        for(j=i;j<N;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        
        if(check!=min){
            count++;
        }
        v=a[i];
        a[i]=a[min];
        a[min]=v;
    }
    
       
    for(k=0;k<N-1;k++){
        printf("%d ",a[k]);
    }
    printf("%d\n",a[N-1]);
    
    printf("%d\n",count);
       
    return 0;
}
