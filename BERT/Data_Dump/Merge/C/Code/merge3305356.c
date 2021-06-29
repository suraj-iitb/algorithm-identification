#include <stdio.h>

int temp[5000000], a=0;   

void MergeSort(int x[ ], int left, int right);

  /* 配列 x[ ] の left から right の要素のマージソートを行う */
void MergeSort(int x[ ], int left, int right)
{
    int mid, i, j, k;
	
    if (left >= right)              /* 配列の要素がひとつなら */
        return;                     /* 何もしないで戻る */

                                    /* ここでは分割しているだけ */
    mid = (left + right) / 2;       /* 中央の値より */
    MergeSort(x, left, mid);        /* 左を再帰呼び出し */
    MergeSort(x, mid + 1, right);   /* 右を再帰呼び出し */

      /* x[left] から x[mid] を作業領域にコピー */
    for (i = left; i <= mid; i++)
        temp[i] = x[i];

      /* x[mid + 1] から x[right] は逆順にコピー */
    for (i = mid + 1, j = right; i <= right; i++, j--)
        temp[i] = x[j];

    i = left;         /* i とj は作業領域のデーターを */
    j = right;        /* k は配列の要素を指している */

    for (k = left; k <= right; k++)    /* 小さい方から配列に戻す */
      if (temp[i] <= temp[j]) {       /* ここでソートされる */
	x[k] = temp[i++];
	a++;
      }
      else{
	x[k] = temp[j--];
	a++;
      }
}

int main()
{
  int i, n;
  /* ソートされるデータ */
  int x[500000];

  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &x[i]);
  }

  MergeSort(x, 0, n - 1);

  /* ソート後のデータを表示 */
  for (i = 0; i < n; i++){
    if(i !=0 ) printf(" ");
    printf("%d", x[i]);
  }
  printf("\n%d\n", a);
  
  return 0;   
}

