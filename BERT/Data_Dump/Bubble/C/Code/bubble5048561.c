#include <stdio.h>

int main(){
    int flg = 1;
    int n,A[100],temp;
    int cnt = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    while(flg){
        flg = 0;
        for(int j=n-1;j>=1;j--)
        if(A[j] < A[j-1]){
            temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;
            flg = 1;
            cnt++;
        }
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
