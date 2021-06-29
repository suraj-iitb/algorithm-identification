#include <stdio.h>
  
#define MAX 500000
  
int a[MAX],n,ntc=0,pet[MAX];
  
void mg(int x[],int ll,int ri){
  int i,j,k;
  if(ll>=ri) return;
  
  mg(x,ll,(ll+ri)/2);
  mg(x,((ll+ri)/2+1),ri);
  
  for(i=ll;i<=(ll+ri)/2;i++){
    pet[i]=x[i];
  }
  for(i=((ll+ri)/2+1),j=ri;i<=ri;i++,j--){
    pet[i]=x[j];
  }
  i=ll;
  j=ri;
  for(k=ll;k<=ri;k++){
    if(pet[i]<=pet[j]) x[k]=pet[i++];
    else x[k]=pet[j--];
    ntc++;
  }
}
int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  mg(a,0,n-1);
  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n%d\n",a[n-1],ntc);
  return 0;
}

