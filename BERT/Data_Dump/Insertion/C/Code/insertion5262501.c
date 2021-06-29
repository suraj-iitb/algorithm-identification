#include<stdio.h>
void printsort(int N,int a[]);
int main(void){
  int N,a[100],v,j;
  scanf("%d",&N);
  for (int i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  printsort(N,a);
  for(int i=1;i<=N-1;i++){
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    printsort(N,a);
  }
  
  
  return 0;
}

void printsort(int N,int a[]){
  for(int i=0;i<N;i++){
    printf("%d",a[i]);
    if(i!=N-1) printf(" ");
    else printf("\n");
  }
}

