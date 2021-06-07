#include <stdio.h>



int  n1,n2,a[10000],b[500];

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
  int i;
  for(i=0;i<n1;i++){
    if(key==a[i])return 1;

}
  return 0;

}
