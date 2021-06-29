#include <stdio.h>

void binary(int *,int *);
int n,q,count=0;

int main(){
  int i;
  scanf("%d",&n);
  //printf("n:%d\n",n);
  int s[n+1];

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  //printf("q:%d\n",q);
  int t[q];

  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  binary(s,t);
  printf("%d\n",count);

  return 0;
}
void binary(int *a,int *b){
  int i,key,left,right,mid;
  for(i=0;i<q;i++){
    key=b[i];
    right=n;
    left=0;
    //printf("%d\n",i);
    while(left<right){
      mid=(left+right)/2;
      if(a[mid]==key) {
        count++;
        break;
      }
      else if(key<a[mid])right=mid;
      else left=mid+1;
    }
  }
}

