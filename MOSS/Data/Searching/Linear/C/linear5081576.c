#include <stdio.h>

int S[10000];
int T[500];

int n, q; //elements

int Search(int key){  //xはさがす者    //bool --> True かfalse
  int i=0;//Iterator
  
  for(i=0;i<n;i++){  //数きまっているときはfor
    if(S[i]==key)
      return 1;    //０以外を返す
  }
  return 0;







}


int main(){
  int i;//Iterator
  int cnt=0;

  scanf("%d",&n); //input the number of integer
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    if(Search(T[i]) ){
      cnt++;
    }
  
  }
  printf("%d",cnt);
  printf("\n");

  return 0;
}
