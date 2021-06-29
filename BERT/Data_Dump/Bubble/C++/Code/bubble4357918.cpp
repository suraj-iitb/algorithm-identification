#include <stdio.h>
void bubbleSort(int *A,int N,int *x){
    int flag = 1,t,i;
    while(flag){
        flag = 0;
        i = 0;
        for(int j = N-1;j>=i+1;j--){
            if(A[j]<A[j-1]){
                t = A[j]; A[j] = A[j-1]; A[j-1] = t;
                flag = 1;
                *x = *x + 1;
            }
        }
        i++;
    }
}
void show(int *a,int n) {
    for (int i = 0; i < n; i++)
    {
        /* code */
        if(i != n-1){
            printf("%d ",a[i]);
        }else{
            printf("%d\n",a[i]);
        }
    }
    
}
int main(){
    int A[100];
    int n;
    int c = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    bubbleSort(A,n,&c);
    show(A,n);
    printf("%d\n",c);


}
