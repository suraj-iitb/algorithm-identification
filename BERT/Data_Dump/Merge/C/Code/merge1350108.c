#include <stdio.h>
#include <math.h>

int  c = 0;
int *merge(int *, int, int, int);
int *mergesort(int *, int, int);


int main(){
  int n, s[500002], left, right, i;
  int *t;

  scanf("%d" ,&n);
  for(i = 0; i < n; i++) scanf("%d" ,&s[i]);

  left = 0;
  right = n;

  t = mergesort(s, left, right);

  for(i = 0; i < n - 1; i++) printf("%d " ,t[i]);
  printf("%d\n%d\n" ,t[i] ,c);  

  return 0;
}


int *merge(int *s, int left, int mid, int right){
  int le[250001], ri[250001], n1, n2, i, j, k;

  n1 = mid - left;
  n2 = right - mid;
  
  for(i = 0; i <  n1; i++) le[i] = s[left + i];
  for(i = 0; i <  n2; i++) ri[i] = s[mid + i];

  le[n1] = pow(10, 9) + 1;
  ri[n2] = pow(10, 9) + 1;

  i = 0;
  j = 0;

  for(k = left; k < right; k++){
    if(le[i] <= ri[j]){
      s[k] = le[i];
      i++;
      c++;
    }
    else{
      s[k] = ri[j];
      j++;
      c++;
    }    
  }

  return s;
}

int *mergesort(int *s, int left, int right){
  int mid;
  int *t;

  if(left + 1 < right){
    mid = (left + right)/2;
    mergesort(s, left, mid);
    mergesort(s, mid, right);
    t = merge(s, left, mid, right);
    return t;
  }
}
