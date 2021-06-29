#include <stdio.h>


int main(){
  int i,n,q;
  
 /** S[]
   * the number of S[]
   */
  scanf("%d", &n);
  int S[n+1]; //+1 is for the sentinel.
  //input data
  for(i=0;i<n;i++){
    scanf(" %d", &S[i]);
  }

 /** T[]
   * the number of T[]
   */
  scanf("%d", &q);
  int T[q];
  //input data
  for(i=0;i<q;i++){
    scanf(" %d", &T[i]);
  }

  /* Linear Search
  */
  int cnt=0;
  for(i=0;i<q;i++){
    int key = T[i]; //??????????????¢?´¢
    S[n] = key; //put the sentinel
    int j = 0;
    while(S[j]!=key){
        j++;
    }
    if(j==n){
      continue;
    }else{
      cnt++;
    }
  }
  
  printf("%d\n",cnt);
  
  return 0;
}
