#include<stdio.h>

int SelectionSort(int *A,int length) {

  int i, j, tmp, cnt=0, mini;

  for(i = 0; i < length; i++) {
    mini = i;
    for(j = i; j < length; j++) {
      if(A[j] < A[mini]) {
	mini = j;
      }
    }
    if(i != mini) {
    tmp = A[i];
    A[i]  = A[mini];
    A[mini] = tmp;
    cnt++;
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

  cnt = SelectionSort(Arr,n);

  /* スペースをいれない方法！ */
  printf("%d", Arr[0]);

  for(i = 1; i < n; i++) {
    printf(" %d" ,Arr[i]);
  }

  printf("\n%d\n", cnt);

  return 0;
}
