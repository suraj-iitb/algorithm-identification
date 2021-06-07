#include<stdio.h>
#include<stdlib.h>

int search(int *S, int num, int key){
  int l = 0, m = num/2, r = num;
// printf("Enter function search\n");
  while(num > 0){
    // printf("l:S[%d]=%d, m:S[%d]=%d, r:S[%d]=%d\n",l,S[l],m,S[m],r,S[r]);
    if(S[m] > key){
      r = m;
      m = l + (r-l)/2;
    }
    else if(S[m] <key){
      l = m + 1;
      m = l + (r-l)/2;
    }
    else if(S[m] == key){
      return 1;
    }
    if(l > m){
      break;
    }
    num /= 2;
  }

  return 0;
}

int main(){
  int n, *S, q;
  int i, j, in, count=0;
  int num=0;

  // input data
  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++){
    scanf("%d",&S[num++]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&in);
    // search
    count += search(S, num, in);
    // printf("q_input:%d (search fin)\n",in);
  }

  printf("%d\n",count);

  return 0;
}

