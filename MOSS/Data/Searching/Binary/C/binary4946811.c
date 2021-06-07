#include <stdio.h>
#include <stdlib.h>

void input(int a, int*b);
int binary(int* s, int n, int key);

int main(){

  int n,q,c=0;

  scanf("%d",&n);

  int *s=(int *)malloc(sizeof(int)*n);
  if (s==NULL) {
    return 0;
 }

  for(int i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);

  int *t=(int *)malloc(sizeof(int)*q);
  if (t==NULL) {
     return 0;
 }

  for(int i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(int i=0;i<q;i++){
    c+=binary(s,n,t[i]);
  }

  printf("%d\n",c);

  free(s);
  free(t);

  return 0;

}

int binary(int* s, int n, int key){

  int left=0,right=n,mid;

    while(left<right){

      mid=(left+right)/2;

      if(s[mid]==key){
        return 1;
      }
      else if(key<s[mid]){
        right=mid;
      }
      else{
        left=mid+1;
      }

    }

    return 0;

}

