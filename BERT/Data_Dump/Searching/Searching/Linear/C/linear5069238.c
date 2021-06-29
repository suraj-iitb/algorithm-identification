#include<stdio.h>


int main(){

  int a, c, b, r, v, key, y, o;
  int cnt = 0;
  int hai[1000000];
  int hai2[50000];

    scanf("%d",&a);

  for(y = 0; y < a; y++){

    scanf("%d",&hai[y]);

  }

  scanf("%d",&c);

  for(o = 0; o < c; o++){
    scanf("%d",&hai2[o]);
  }

  for(v = 0; v < c; v++){
    r = 0;
    key = hai2[v];
    hai[a] = key;
    while(hai[r] != key){
        r++;
        if(r == a){
            break;
        }
    if(key == hai[r]){
      cnt++;
    }
    }
   if(r == 0){
    cnt++;
    }
  }
  printf("%d\n",cnt);

  return 0;
    }


