#include<stdio.h>

int main(){
  int N,i,j,cnt=0,temp;
  int a[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
}
  for(i=0;i<N;i++)
    for(j=0;j<N-1;j++){
      if(a[j]  > a[j+1]){
	temp = a[j];
	a[j] = a[j+1];
	a[j+1] = temp;
	cnt++;
      }
}
  for(i=0;i<N;i++){
    if(i == N-1){
      printf("%d\n",a[i]);
      break;
  }
    printf("%d ",a[i]);
}
  printf("%d\n",cnt);

  return 0;
}

