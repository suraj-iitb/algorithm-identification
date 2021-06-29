#include <stdio.h>

int binarySearch(int *,int, int);

int main(){
int i,n,q,s[100000+10],t,sum=0;

scanf("%d",&n);
for(i = 0; i < n ; i++){
scanf("%d",&s[i]);
}
scanf("%d",&q);
for(i = 0 ; i < q; i++){
  scanf("%d",&t);
if(s[binarySearch(s,t,n)] == t)sum++;
}
printf("%d\n",sum);

return 0;
}

int binarySearch(int *a,int key,int n){
int left = 0;
int right = n;
int mid;

while(left < right){
  mid = (left + right)/2;
  if(a[mid] == key) return mid;
  else if (key < a[mid]) {
    right = mid;
  }
  else {
    left = mid + 1;
  }
}
return 0;
}

