#include<stdio.h>
static const int N=100;

void bubble(int ,int []);

int main(){
  
  int i,m;
  int n[N];
  scanf("%d",&m);
  for(i = 0; i < m; i++){
    scanf("%d",&n[i]);
  }
  bubble(m,n);
  return 0;
}
void bubble(int m,int n[]){
  
  int i,j,a=0,b=0;
  
  for(i = 0; i < m; i++){
    
    for(j = m-1; j > i; j--){
      
      if(n[j]<n[j-1]){
	b=n[j-1];
	n[j-1]=n[j];
	n[j]=b;
	a++;
      }
    }
  }
  for(i=0;i<m;i++){
    printf("%d",n[i]);
    if(i<m-1){
      printf(" ");
    }
  }
  printf("\n%d\n",a);
}
