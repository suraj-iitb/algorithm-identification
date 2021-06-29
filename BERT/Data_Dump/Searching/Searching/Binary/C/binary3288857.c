#include<stdio.h>
#define N 100000

int main(){
  int A[N],n,A2[N],i,q,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
        scanf("%d",&A2[i]);
    }
  //  binarySearch()
  for(i=0;i<q;i++){
  int  left = 0;
  int right = n;
  int key=A2[i];
  while(left < right){
  int mid = (left + right) / 2;
            if (A[mid] == key){
              cnt++;
              break;
            }
            else if (key < A[mid])
                right = mid;
            else
                left = mid + 1;
      }
    }
    printf("%d\n",cnt);
    return 0;
}

