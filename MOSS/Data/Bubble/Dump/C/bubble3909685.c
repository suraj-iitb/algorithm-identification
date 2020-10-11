#include <stdio.h>

int bubbleSort(int A[], int N)
{
  int flag = 1, j, tmp, count = 0;

  while(flag){
    flag = 0;
    for(j = N - 1; j > 0; j--){       //配列の末尾から順番に大きさを比較していく」
      if(A[j] < A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        count++;
      }
    }
  }
  return count;
}

int main(void)
{
  int n, i, a[100], count;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  count = bubbleSort(a, n);

	/*for(i=0; i<n; i++){
		if(0<i){
			printf(" ");
		}
		printf("%d\n%d\n", a[i], count);
	}*/
  for(i = 0; i < n - 1; i++){
      printf("%d", a[i]);
      printf(" ");
  }

  printf("%d\n%d\n", a[n-1], count);    //上のループで最後に空白が入るのでn-1までにしてループの外に最後の出力をする


  return 0;
}

