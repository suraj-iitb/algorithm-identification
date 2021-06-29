#include <stdio.h>

#define T_SIZE 100000
#define S_SIZE 50000

int binary(long T[], long find, long left, long right)
{
  long half;
  if(left > right) return -1;

  half = (right + left) / 2 ;

  if(T[half] < find){
    return binary(T, find, half + 1, right);
  }else if(find < T[half] ){
    return binary(T, find, left, half - 1);
  }else{
    return half;
  }
}

int main(void)
{
  long T[T_SIZE];
  long S[S_SIZE];
  long n, q;
  long i;
  long found;

  scanf("%10ld", &n);
  for(i = 0; i < n ; i++) scanf("%10ld", &T[i]);

  scanf("%10ld", &q);
  for(i = 0; i < q ; i++) scanf("%10ld", &S[i]);

  found = 0;

  for(i = 0; i < q; i++){
    int ret;
    ret = binary(T, S[i], 0, n);
    if(ret > 0) found++;
  }

  printf("%ld\n", found);

  return 0;
}
