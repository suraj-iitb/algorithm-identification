#include <stdio.h>

int cnt=0,n;

int main() {
  int q,t;
  int i,j;
  scanf("%d", &n);
  int s[n];
  for (i=0;i<n;i++) {
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for (i=0;i<q;i++) {
    scanf("%d",&t);
    int left=0,right=n;
    int mid=(left+right)/2;

    while(left<right){
      mid=(left+right)/2;
      if(s[mid]==t){
        cnt++;
      //  printf("t=%d\n",t);
        break;
      }
      else if(t<s[mid])right=mid;
      else left=mid+1;
    }

  }

  printf("%d\n", cnt);

  return 0;
}

