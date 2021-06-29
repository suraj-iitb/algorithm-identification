#include<stdio.h>

int main(){

  int hai[1000000];
  int hai2[500000];
  int a,i,c,e,right,left,mid,key,v;
  int cnt = 0;
  
    scanf("%d",&a);
  for( i = 0; i < a; i++){
    scanf("%d",&hai[i]);
  }

  scanf("%d",&c);

  for( e = 0; e < a; e++){
    scanf("%d",&hai2[e]);
  }

    for(v = 0; v < c; v++){
  
        key = hai2[v];
        hai[a] = key;
        left = 0;
        right = a;

  while(left < right){
    mid = (left + right)/2;
    if(hai[mid] == key){
      cnt++;
      break;
    }else if(key < hai[mid]){
      right = mid;
    }else{
      left = mid +1;
    }
  }
 }

 printf("%d\n",cnt); 
  
  return 0;
}


