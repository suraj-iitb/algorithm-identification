#include<stdio.h>

int BubbleSort(int *A,int length) {

  int i, j, tmp, cnt=0;
  for(i = 0; i < length; i++) {
    for(j = length-1; j > i; j--) {
      if(A[j] < A[j-1]) {
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	cnt++;
      }
    }
  }
  return cnt;
}


main()
{
  int i;
  int n;
  int Arr[100];
  int cnt = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    scanf("%d", &Arr[i]);
  }

  cnt = BubbleSort(Arr,n);

  /* スペースをいれない方法！ */
  printf("%d", Arr[0]);

  for(i = 1; i < n; i++) {
    printf(" %d" ,Arr[i]);
  }

  printf("\n%d\n", cnt);

  return 0;
}
