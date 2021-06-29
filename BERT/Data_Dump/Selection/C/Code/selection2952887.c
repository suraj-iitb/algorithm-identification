#include <stdio.h>

int main(){
    int A[100];
    int n,i,j,count=0,tmp,tmp1,flag;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    // SelectionSort
    for(i=0;i<n;i++){
        tmp = i;
        flag =0;
        for(j=i;j<n;j++){
            if(A[j]<A[tmp]){
                tmp = j;
                flag =1;
            }
            
        }
        if(flag==1){
        tmp1 = A[i];
        A[i] = A[tmp];
        A[tmp] = tmp1;
        count++;
        }
    }
    for(i=0;i<n;i++){
        printf("%d",A[i]);
        if(i==n-1){
            printf("\n");
            break;
        }
        else printf(" ");
    }
    printf("%d\n",count);
    return 0;
}
