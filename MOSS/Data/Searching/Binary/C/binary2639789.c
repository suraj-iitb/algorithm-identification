#include<stdio.h>
 
int count;
 
void binarysearch(int S[], int n, int key){
  int top = 0, tail = n, a;
  while(top != tail){
    a = (top + tail)/2;
    if (S[a] == key){
      count++;
      break;
    } else if(S[a] < key) top = a + 1;
    else tail = a;
  }
}
 
int main(void){
  int i, n, q, b, S[100000];
  scanf("%d", &n);
  for(i=0;i<n;i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  for(i=0;i<q;i++){
    scanf("%d", &b);
    binarysearch(S, n, b);
  }
  printf("%d\n", count);
  return 0;
}
