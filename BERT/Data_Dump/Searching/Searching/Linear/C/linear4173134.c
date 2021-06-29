#include <stdio.h>

 int linearSearch(int *,int,int);

int main(){
int n,q,s[10000],t,i,sum=0;

scanf("%d",&n);
for(i = 0 ; i < n ; i++){
  scanf("%d",&s[i]);
}
scanf("%d",&q);
for(i = 0 ; i < q ; i++){
  scanf("%d",&t);
if(linearSearch(s,t,n) == 1) sum++;
}
printf("%d\n",sum);
return 0;
}

int linearSearch(int *a,int key,int n){
int i = 0;
a[n] = key;
while(a[i] != key){
  i++;
}
if(i == n)return 0;
return 1;
}

