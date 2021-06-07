#include <stdio.h>

int S[100000];
int T[50000];
int n,q;  //elements of S[] and T[]
int key;

int BiarySearch(int key){
  int mid;
  int right = n; //element of A[]  /*if the array is A[5],"right" becomes the 6th array */
  int left =0;     /*      |left |1 |2 |3 |4 |right(=n)|      */

  while(left < right){

    mid = (left + right)/2;

    if(key ==S[mid]){
      return 1;
    }
    else if(key > S[mid]){
      left = mid + 1;
    }
    else if(key < S[mid])
	right = mid;
       }

  return 0;
}


int main(){
  int i;   //iterator
  int cnt=0;  //count the number of same value between S[n]and T[q]

  scanf("%d",&n);      //read the number of elements of S[n]
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);            
  }

  scanf("%d",&q);      //read the number of elements of T[q]
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    if(BiarySearch(T[i])){    //if S[n] matches T[q]
      cnt++;
    }
  }

  

  printf("%d",cnt);
  printf("\n");

  return 0;
}








