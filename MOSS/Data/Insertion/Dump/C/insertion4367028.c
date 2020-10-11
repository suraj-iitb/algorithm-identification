#include<stdio.h>
void insertionSort(int *a,int n){
    int i,v,j,k;
for(i=1;i<=n-1;i++){
v=*(a+i);
j=i-1;
while(j>=0 && *(a+j)>v){
*(a+j+1)=*(a+j);
j--;
*(a+j+1)=v;
}
for(k=0;k<n-1;k++){
        printf("%d ",*(a+k));
    }
    if(k==n-1) printf("%d\n",*(a+k));
}
}
int main(void){
    int N,i=0,a[100]={},v,j;
    scanf("%d",&N);
    while(scanf("%d",&a[i])==1){
        i++;
        if(i==N) break;
            }
        for(i=0;i<N-1;i++){
        printf("%d ",a[i]);
    }   
    if(i==N-1) printf("%d\n",a[i]);

    insertionSort(a,N);   
    return 0;
}
