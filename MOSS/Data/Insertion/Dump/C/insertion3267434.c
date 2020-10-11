#include<stdio.h>
#include<stdlib.h>
#define N 100

int main(){
    int n,i,j,k,m,key,l;
    int a[N];
    
    scanf("%d",&n);
    for(k=0;k<n;k++){
        scanf("%d",&a[k]);
    }
    
    for(l=0;l<n;l++){
        if(l>0){
            printf(" ");
        }
        printf("%d",a[l]);
    }
    printf("\n");
    
    for(j=1;j<=n-1;j++){
        key = a[j];
        i = j-1;
        while(i>=0 && a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1] = key;
        
        for(m=0;m<n;m++){
            if(m>0) printf(" ");
            printf("%d",a[m]);
        }
        printf("\n");
    }
    return 0;
}



