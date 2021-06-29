#include<stdio.h>

int binary(int r);
int n;

int S[100000];

int main(void)
{

  int i,n2,cou = 0;

   int S2[50000];
  scanf("%d",&n);

  for(i = 0; i < n; i++){
  scanf("%d", &S[i]);
  }

  scanf("%d",&n2);

  for(i = 0; i < n2; i++){
  scanf("%d", &S2[i]);
  }



 for(i = 0; i < n2; i++){
   if(binary(S2[i]) == 1){
	cou++;
      }

  }

  printf("%d\n",cou);
  return 0;
}


int binary(int key){
  int mid;

  int  L = 0,R = n;
  while (L < R){
    mid = (L + R)/2;
    if(S[mid] == key)  return 1;
    else if (key < S[mid])R = mid;
    else L = mid + 1;
  }
    return 0;

  }
