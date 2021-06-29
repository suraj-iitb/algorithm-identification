#include<stdio.h>

int main(){
  int i;
  int n;  
  int t[500];
  int s[10000];
  int q;
  int cnt;
  int j;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&s[i]);  
}
  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&t[i]); 
}
 
    for(i = 0 ; i < q ; i++){
      for(j = 0 ; j < n ; j++){
	if(s[j] == t[i]){cnt++;
       break;
    }
}
  }
  
  

    printf("%d\n",cnt);
  return 0;
}
