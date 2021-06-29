#include<stdio.h>
#define N 100000
int S[N];
int T[N];

int binary_search(int [N],int,int,int);
int main(){
  int n,q,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  int count=0;
  for(i=0;i<q;i++){
    if(binary_search(S,T[i],0,n)==1){
      //printf("%d\n",T[i]);
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}


int binary_search(int ary[N], int key, int imin, int imax) {
    if (imax < imin) {
        return 0;
    }
    else {
        int imid = (imin + imax) / 2;
        if (S[imid] > key) {
            return binary_search(S, key, imin, imid-1);
        }
        else if (S[imid] < key) {
            return binary_search(S, key, imid + 1, imax);
        }
        else {
            return 1;
        }
    }
}

