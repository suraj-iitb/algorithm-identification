#include <stdio.h>

#define N 100000
#define Q 50000

int BinarySearch();

int main() {
 
int n,q,S[N],T[Q];
int i,key,num,sum=0;

scanf("%d",&n);
for(i=0; i<n;i++)
  scanf("%d",&S[i]);

scanf("%d",&q); 
for(i=0; i<q;i++)
  scanf("%d",&T[i]);

for (i=0; i<q; i++){

num = BinarySearch(n,S,T[i]);
 if(num != 0)
   sum++;
}

printf("%d\n",sum);


return 0;
}

int BinarySearch(int n,int S[],int key){

  int left,mid,right;
  
  left = 0;
  right = n;

  while (left < right){
    
    mid = (left + right)/2;
    
    if( key == S[mid])
      return 1;

    if( key > S[mid] )
      left = mid +1;
    
    else if( key < S[mid] )
      right = mid;
  }

  return 0;

}
