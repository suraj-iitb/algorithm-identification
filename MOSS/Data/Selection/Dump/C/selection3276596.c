#include <stdio.h>
int main(void){
    int n,i,j,A[100],mini,bar=0,temp,c,min=100;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    c=0;
        for(j=0;j<n;j++){
            temp=A[j];
            min=100;
            for(i=j+1;i<n;i++){
                if(min>A[i]){
                    min=A[i];
                    mini=i;
                }
            }
            if(A[j]>min){
            A[j]=A[mini];
            A[mini]=temp;
            c++;
           
            }
        }
    for(i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n%d\n",A[i],c);
    return 0;
}
