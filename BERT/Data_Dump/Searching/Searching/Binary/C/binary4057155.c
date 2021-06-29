#include<stdio.h>

int A[1000000],n;

int binarySearch(int);


int main(){
      int i,q,key,s=0;

      scanf("%d",&n);
      for(i=0;i<n;i++){
        scanf("%d",&A[i]);
      }
      scanf("%d",&q);
      for(i=0;i<q;i++){
        scanf("%d",&key);
        if(binarySearch(key)){
          s++;
        }
      }printf("%d\n",s);

      return 0;
    }

int binarySearch(int key){
        int left = 0,right,mid;
        right = n;
        while (left < right){
            mid = (left + right) / 2;
            if (A[mid] == key){
                return 1;
            }else if( key < A[mid]){
                right = mid;
            }else{
                left = mid + 1;
              }
        }return 0;
    }

