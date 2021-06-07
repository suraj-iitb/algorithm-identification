#include <stdio.h>

int main(){
  int n, q, i, j, k, x=0, z;
  int b[500];
  scanf("%d", &n);
  int s[n];
  for(i=0;i<n;i++)scanf("%d", &s[i]);
  scanf("%d", &q);
  int t[q];
  for(j=0;j<q;j++)scanf("%d", &t[j]);
  for(i=0;i<n;i++){
    for(j=0;j<q;j++){
          if(s[i]==t[j]){
            for(k=0,z=0;k<x;k++){
              if(s[i]==b[k])z=1;
            }
            if(z==0){
                b[x]=s[i];
                x++;
            }
          }
    }
  }
  printf("%d\n", x);
  return 0;
}
