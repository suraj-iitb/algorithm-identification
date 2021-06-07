#include<stdio.h>

int n;
int A[1000000];

int binarySearch(int key){
  int left = 0;
  int right = n;
  int mid;
    while (left < right){
        mid = (left + right) / 2;
        if (key == A[mid])
            return 1;
        if (key > A[mid])
            left = mid + 1;
        else if (key < A[mid])
            right = mid;
    }
    return 0;
}

int main(){
   int i;
   int q;
   int k;
   int sum = 0;


    scanf("%d",&n);
    for(i = 0; i < n; i++){
      scanf("%d",&A[i]);/*nの個数分読み込みを繰り返す*/
    }

    scanf("%d",&q);
    for(i = 0; i < q; i++){
      scanf("%d",&k);/*qの個数分読み込みを繰り返す*/
      if(binarySearch(k))
        sum++;
    }
    printf("%d\n",sum);

    return 0;
}


