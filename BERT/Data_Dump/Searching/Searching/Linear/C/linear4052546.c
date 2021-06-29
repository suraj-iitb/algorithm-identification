#include <stdio.h>
//#define MAX 1000;

//int liner(int,int);

int main(){
  int i=0,j=0;
  int s,t;
  int count=0,key;

  scanf("%d",&s);
  int S[s];
  for(i=0;i<s;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&t);
  int T[t];
  for(i=0;i<t;i++){
    scanf("%d",&T[i]);
  }

    for(i=0;i<t;i++){
      /*if(S[i] == S[i+1]) i++;*/
      key = T[i];
      for(j=0;j<s;j++){
	if(key == S[j]){
	  count++;
	  break;
	}
      }
    }
  
  /*else if( t > s){
    for(i=0;i<s;i++){
      if(T[i] == T[i+1]) i++;
      key = T[i];
      for(j=0;j<s;j++){
	if(S[j] == S[j+1]) j++;
	if(key == S[j]) {
	  count++;
	  break;
	}
      }
    }
  }*/
      printf("%d\n",count);
      return 0;
}


  
		 
  

