#include<stdio.h>

double s[100000], t[50000];

void intAryScan(double b[], int size)
{
  int i;
  for(i = 0; i < size; i++){
    scanf("%lf", &b[i]);
  }
  return;
}

int main()
{
  int c, i, j, mid, n, q;

  scanf("%d", &n);
  intAryScan(s, n);
  scanf("%d", &q);
  intAryScan(t, q);

  c = 0;
  for(i = 0; i < q; i++){
	mid = n/2;
	if(s[mid] < t[i]){
      for(j = mid + 1; (j < n) && (s[j] < t[i]); j++)
		 ;
	  if(j < n && t[i] == s[j]){
		  c++;
	  }
	}else if(t[i] < s[mid]){
	  for(j = 0; (j < mid) && (s[j] < t[i]); j++)
		 ;
	  if(j < mid && t[i] == s[j]){
		  c++;
	  }
	}else if(s[mid] == t[i]){
		c++;
	}
  }
  printf("%d\n", c);

  return(0);
}
