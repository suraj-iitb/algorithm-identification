/* サーチプログラム */
#include<stdio.h>
//all 1

/* マクロの定義 */
#define N 10000
#define Q 500
//all 2

/* プロトタイプ宣言 */
int Linear_Search(int *, int);
//all 1

/* グローバル変数宣言 */
int n=0;
int q=0;
//all 2


main() 
{
  int i=0;
  int S[N];
  int T[Q];
  int val=0;

  /* n個を決定 */
  scanf("%d",&n);

  /* Sの要素 */
  for(i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  /* q個を決定 */
  scanf("%d", &q);

  /* Tの要素*/
  for(i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }

  /*  */
  for(i = 0; i < q; i++) {
  val +=  Linear_Search(S, T[i]);
  }

  printf("%d\n",val);

  return 0;
}


/* Linear_Search関数 */
int Linear_Search(int *A, int key) 
{

  /*
  static int cnt = 0;

  while(A[n] != key){
  //  for(i = 0; i < n; i++) {
    //if(A[i] == key) {
      cnt++;
      //   printf("%d",cnt);
  return cnt;
  //   }
  }*/
  int i;
  for(i=0;i<n;i++)
    {
      if(A[i]==key)
	return 1;
    }
  return 0;
}
