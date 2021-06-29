/* 7.1 マージソート ALDS1_5_B: Merge Sort
n個の整数を含む数列Sを上の疑似コードに従ったマージソートで昇順に整列するプログラムを作成してください。また、mergeにおける比較回数の総数を報告してください。
コンパイル g++ -o alds1_5_b.exe alds1_5_b.cpp -Wall

入力 1行目にn、2行目にSを表すn個の整数が与えられます
出力 1行目に整列済の数列Sを出力してください。数列の隣り合う要素は1つの空白で区切ってください。2行目に比較回数を出力してください。
制約 n<=500,000 , 0<=Sの要素<=10^9

実行 alds1_5_b.exe
入力例
  10
  8 5 9 2 6 3 7 1 10 4
出力例
  1 2 3 4 5 6 7 8 9 10
  34
*/

#include <iostream>
/* C++のstdio.hみたいなもの、cin (scanf), cout (printf) のためにincludeします。 */
using namespace std;
/* 名前空間にstdを指定する。毎回、std::cin , std::cout と記述するのはうっとおしいので省略するため。*/

#define MAX 500000
#define SENTINEL 2000000000 // 番兵

int L[MAX/2+2], R[MAX/2+2];
int cnt;

void merge(int A[],int left, int mid, int right) {
  int n1 = mid -left;
  int n2 = right - mid;
// C++forループ専用のint型を宣言できる
// ループの中のみ有効なので安全
  for(int i=0;i<n1;i++) L[i] = A[left + i];
  for(int i=0;i<n2;i++) R[i] = A[mid + i];
  L[n1] = R[n2] = SENTINEL;
  int i=0, j=0;
  for(int k=left; k<right; k++) {
    cnt++;
    if(L[i]<=R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(int A[],int left,int right) {
  if(left+1 < right) {
    int mid = (left+right) / 2;
    mergeSort(A,left,mid);
    mergeSort(A,mid, right);
    merge(A,left,mid,right);
  }
}

int main(void) {
  int A[MAX], n, i;
  cnt = 0;

	cin >> n; // scanf("%d",&n);
  for(i=0;i<n;i++) cin >> A[i];

  mergeSort(A, 0, n);
  for(i=0;i<n;i++) {
    if(i)cout << " ";
  	cout << A[i]; // printf("%d",A[i]);
  }
  cout << endl; // endlは改行

  cout << cnt << endl; // printf("\n");

  return 0;
}

