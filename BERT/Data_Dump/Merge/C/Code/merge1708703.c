#include <stdio.h>
#define N 500001
#define SENTINEL 1000000005

int n,S[N]; // int ha 32bit system no tame 2*10no9jyou gurai
int cnt = 0;

// merge ha touchi. tumari ketugou.

void merge(int left, int mid, int right){

  int n1 = mid - left;
  int n2 = right - mid;

  // banpei you ni 1tu yobun ni kakuho
  int L[n1+1],R[n2+1];

  int i,j,k;

  // hairetsu wo 2tu ni wakeru
for (i = 0; i < n1; i++) L[i] = S[left + i];
  for ( i = 0; i < n2; i++) R[i] = S[mid + i];

  // hairetsu no saigo ni banpei wo setti
  L[n1] = R[n2] = SENTINEL;

  i = j = 0;

  for (k = left; k< right; k++)
    {
      cnt++;
      if(L[i] <= R[j]) S[k] = L[i++];// i++ ha i wo hyouka sitaato i wo 1 tuika suru.
      else S[k] = R[j++];  
    }
}



// mergeSort de bunkatsu
void mergeSort(int left,int right)
{
int mid;

  // hairetsu no nagasa ga 1 ika nara sort zumi
  if(right - left <=1) return;

  // hairetsu wo left~mid to mid~right no 2tu ni wakete sort
  mid = (left + right) /2;
  mergeSort(left, mid);
  mergeSort(mid,right);

  // hairetsu wo merge. tumari touchi
  merge(left, mid, right);

}

int main(void){
  int i;
  int left, right;
  scanf("%d", &n);
    for(i = 0; i<n; i++) scanf("%d",&S[i]);
  left = 0;
  right = n;
  mergeSort(left,right);// mergeSort de bunkatsu. merge de touchi.

  for (i = 0; i < n-1; i++)printf("%d ",S[i]);
  printf("%d\n",S[n-1]);
  printf("%d\n",cnt);
return 0;
}
