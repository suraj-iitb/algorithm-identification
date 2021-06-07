#include<stdio.h>
#define N 100000
int binary(int );
int A[N+1],n;

int main ()  {
  int q,key,sum = 0,i;

  scanf("%d",&n);
for(i=0;i<n;i++)  scanf("%d", &A[i]);
  scanf("%d", &q);

for(i=0;i<q;i++) {
    scanf("%d", &key);
    if(binary(key)) sum++;
}
  printf("%d\n",sum);

  return 0;
}

int  binary(int key) {
   int left=0,right=n,mid;
   while(left < right) {
     mid = (left + right)/2;
      if(A[mid] == key)
         return 1;
         else if(key < A[mid])
         right = mid;
         else left = mid +1;
   }
   return 0;
}
