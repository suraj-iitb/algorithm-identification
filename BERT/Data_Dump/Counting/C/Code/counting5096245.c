#include <stdio.h>
int A[2000000];
int B[2000000];
int C[2000000];
void CountingSort(int k,int MAX){      //function for counting kは数列の要素
int i=0; //iterator
/* C[i] に i の出現数を記録する store the count of A[] element*/
for (i = 0; i <= MAX; i++)
{
    C[i]=0;
}
for(i=0;i<k;i++){     //最初のインデックスは１
     C[A[i]]++;
}
 /* C[i] に i 以下の数の出現数を記録する //カウントを順に足していくところ*/
 for(i=1;i<=MAX;i++){
     C[i] = C[i] + C[i-1];

 }
 
 for(i=k-1;i>=0;i--){
     B[C[A[i]]-1] = A[i];
     C[A[i]]--;            //decrement the count C[]
 }
}
 

int main(){
int MAX=0;
int n;//same role as 'k'
int i; //iterator
scanf("%d",&n); //input the number of elements
for(i=0;i<n;i++){
  scanf("%d",&A[i]);
  if(A[i]>MAX){
    MAX = A[i];
  }
}
CountingSort(n,MAX);
 for (i = 0; i < n-1; i++) {
    printf("%d ", B[i]);
  }
  printf("%d",B[n-1]);
  printf("\n");
return 0;
}
 

