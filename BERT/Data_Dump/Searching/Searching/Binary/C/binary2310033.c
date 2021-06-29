#include<stdio.h>

#define N 100000

int binary(int *,int,int);

int main(){
  int pre,nex,i,cnt=0;
  int a[N],b[N];

  scanf("%d",&pre);
  for(i=0;i<pre;i++) scanf("%d",&a[i]);

  scanf("%d",&nex);
  for(i=0;i<nex;i++){
    scanf("%d",&b[i]);
    cnt += binary(a,b[i],pre);
  }

  printf("%d\n",cnt);

  return 0;
}

int binary(int *a,int b,int cut){
    int left = 0,p=0,right=cut,mid;

    while(left <= right) {
        mid = (left + right) / 2; /* calc of middle key */
        if (a[mid] == b) {
            p++;
            break;
        } else if (a[mid] < b) {
            left = mid + 1; /* adjustment of left(start) key */
        } else {
            right = mid - 1; /* adjustment of right(end) key */
        }
    }
    return p;
}
