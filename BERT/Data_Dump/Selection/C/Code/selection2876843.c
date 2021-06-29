#include <stdio.h>

int selection(int [],int );
int main(void){
    int n,A[100];
    int i,c;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&A[i]);
    c=selection(A,n);
    for(i=0;i<n;i++){
        printf("%d",A[i]);
        if(i!=n-1) printf(" ");
        else printf("\n");
    }
    printf("%d\n",c);
    
    return 0;
}

int selection(int A[],int n){
    int i,j,min,a,count=0;
    for(i=0;i<n;i++){
        min=i;
        for(j=i;j<n;j++){
            if(A[j]<A[min]) min=j;
        }
        if(i!=min){
            a=A[i];
            A[i]=A[min];
            A[min]=a;
            count++;
        }
    }
    return count;
}
