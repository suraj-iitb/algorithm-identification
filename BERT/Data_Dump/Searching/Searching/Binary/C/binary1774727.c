#include <stdio.h>

#define N 100000
#define Q 50000

int left, right, mid, n;
int s[N], t[Q];

int binarySearch(int);

int main()
{

  int i, j, q, c = 0;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);

  for(j=0; j<q; j++){
    scanf("%d", &t[j]);
  }

  for(j=0; j<q; j++){
    if(binarySearch(t[j]) == 1){
      c++;
    }
  }

  printf("%d\n", c);

  return 0;

}

int binarySearch(int key)
{

  left = 0;
  right = n;

  while(left < right){
    mid = (left + right) / 2;

    if(s[mid] == key){
      return 1;
    }

    else if(key < s[mid]){
      right = mid;
    }

    else{
      left = mid + 1;
    }
  }

  return 0;
}
