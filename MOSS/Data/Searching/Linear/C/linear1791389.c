#include <stdio.h>

#define N 10000
#define Q 500

int linearSearch();

int main() {
 
int n,q,S[N],T[Q];
int i,key,num,sum=0;

scanf("%d",&n);
for(i=0; i<n;i++)
  scanf("%d",&S[i]);

scanf("%d",&q); 
for(i=0; i<q;i++)
  scanf("%d",&T[i]);

for (i=0; i<q; i++){

num = linearSearch(n,S,T[i]);
sum += num;
}

printf("%d\n",sum);


return 0;
}

int linearSearch(int n,int S[],int t){

int i = 0;
S[n] = t;

while(S[i] != t){

  i++;
if (i==n)
  return 0;
}

return 1;
}
