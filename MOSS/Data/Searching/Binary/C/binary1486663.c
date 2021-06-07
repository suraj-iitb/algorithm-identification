#include <stdio.h>
 
int main()
{
  int a[100000], b[50000];
  int i, right, left, center, n, q, count=0;
  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }
  
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &b[i]);
  }
  
  for(i=0; i<q; i++){
    right = n;
    left = 0;
    while(left<=right){
      center = (right + left)/2;
      if(a[center] == b[i]) {
		count++;
		break;
      }
      else if(a[center] < b[i])
		left = center + 1;
      else
		right = center - 1;
    }
  }
  printf("%d\n", count);
  return 0;
}
