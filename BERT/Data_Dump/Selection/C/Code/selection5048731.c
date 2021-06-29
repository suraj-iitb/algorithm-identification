#include <stdio.h>

int main(){
    int n,A[100],temp,minj;
    int cnt = 0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    for(int i=0;i<n;i++){
        minj = i;
        for(int j=i;j<n;j++){
            if(A[j]<A[minj]){
                minj = j;
            }
        }
        if(A[i]!=A[minj]){
            cnt++;
        }
        temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
    }

    for(int i=0;i<n;i++){
        printf("%d",A[i]);
        if(i==n-1){
            printf("\n");
        }else{
            printf(" ");
        }
    }
    printf("%d\n",cnt);
    
    return 0;
}
