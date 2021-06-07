#include <stdio.h>
#define MAX 100000

int binary(int);

int n,s[MAX],q,t[MAX];

int main()
{

  int i=0;

  int count=0,j=0;

  scanf("%d",&n);

  for(i = 0;i < n;i++){

    scanf("%d",&s[i]);

  }

  scanf("%d",&q);

  for(i = 0;i < q;i++){

    scanf("%d",&t[i]);

  }

  for(j = 0;j < q;j++){

    count = count + binary(j);

  }

  printf("%d\n",count);

  return 0;

}
 /* kokokara  */

 int binary(int j){

   int left,right,mid;

left = 0;

right = n;

while(left < right){

  mid = (left + right) / 2;

  if(s[mid] == t[j]){

    return 1;
  }

  else if(t[j] < s[mid]){

    right = mid;

    continue;

  }

  else {

    left = mid + 1;

    continue;
  }

  return 0;

}

return 0;

}

