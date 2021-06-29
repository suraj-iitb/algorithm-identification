#include<stdio.h>

void sort(int a[],int b[],int c);

int main(){
  int a,b[2000000],d[10001]={0},M=0,i;
  scanf("%d",&a);
  for(i=0;i<a;i++){scanf("%d",&b[i]);
    if(M<b[i])M=b[i];
    d[b[i]]++;
  }
  for(i=0;i<=M;i++)d[i+1]+=d[i];
  //for(i=0;i<=M;i++)printf("%d\n",d[i]);
  
  sort(b,d,a);
  /*for(i=a-1;i>=0;i--){
    c[d[b[i]]]=b[i];
    d[b[i]]--;
  }*/
  //for(i=0;i<=M;i++)printf("%d\n",d[i]);
  for(i=0;i<a;i++){
    printf("%d",b[i]);
    if(i==a-1)printf("\n");
    else printf(" ");
  }
}
void sort(int a[],int b[],int c){
  int i,d[c];
  for(i=c-1;i>=0;i--){
    d[b[a[i]]]=a[i];
    b[a[i]]--;
  }
  for(i=0;i<=c;i++)a[i]=d[i+1];
}

