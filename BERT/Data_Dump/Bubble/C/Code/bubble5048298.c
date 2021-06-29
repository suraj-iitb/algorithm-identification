#include<stdio.h>
void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void Sort(int A[],int n){
int flag = 1;
int i,j,k,count=0;
for(i = 0; i <= n-1;i++){
flag = 0;
for(j = n-1; j >= i+1; j--){
if(A[j] < A[j-1]){
swap(&A[j],&A[j-1]);
flag=1;
count++;
}
}
}
for(k = 0; k < n; k++){
if(k >= 1) printf(" ");
printf("%d",A[k]);
}
printf("\n%d\n",count);
}
int main(){
int i,n,A[100];
scanf("%d",&n);
for(i = 0; i < n ;i++){
 
scanf("%d",&A[i]);
}
Sort(A,n);
return 0;
}

