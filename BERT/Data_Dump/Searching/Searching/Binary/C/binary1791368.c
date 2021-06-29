#include <stdio.h>



int  n1,n2,a[100000],b[50000];

int linear(int);


int main(){
  int i,sum=0;
  scanf("%d",&n1);
 
  for(i=0;i<n1;i++) scanf("%d",&a[i]);
scanf("%d",&n2);
 
  for(i=0;i<n2;i++) scanf("%d",&b[i]);
  for(i=0;i<n2;i++){
    sum+=linear(b[i]);




}
  printf("%d\n",sum);

return 0;
}
int linear(int key){
  int i,l,r,m;
  l=0;
  r=n1;

  while(l<r){
    m=(l+r)/2;
    if(a[m]==key) return 1;
    else if(key<a[m])r=m;
    else l=m+1;
}
  return 0;

}
