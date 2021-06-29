#include <stdio.h>


int main (){
  int len , arr[100] , i ,j ,v, o;

    scanf("%d", &len);
    for ( i = 0; i < len; i++){
      scanf("%d", &arr[i]);
    }

    /*  
    insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 1 から N-1 まで
3     v = A[i]
4     j = i - 1
5     while j >= 0 かつ A[j] > v
6       A[j+1] = A[j]
7       j--
8     A[j+1] = v

*/
    for (i = 0; i < len; i++){
      v = arr[i];
      j = i -1;
      while( j >= 0 && arr[j] > v){
	arr[j+1] =arr[j];
	j--;
      }
      arr[j+1] = v;
      for ( o =0 ; o < len; o++){
      printf("%d", arr[o]);
      if ( o < len -1) printf(" ");
      }
      printf("\n");
    }

    
    
return 0;
}

