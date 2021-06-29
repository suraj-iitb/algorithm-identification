#include <stdio.h>
int main(){
  int n,list[105],check=0;
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    scanf("%d",&list[i]);
  }
  for (int i=0;i<n ;i++){
    int temp=i;
    for(int j=i+1;j<n;j++){
      if(list[j]<list[temp]){
        temp=(j);
      }
    }
    if(temp!=i){
      int hold=list[i];
      list[i]=list[temp];
      list[temp]=hold;
      check++;
    }
  }
  for(int i=0;i<n;i++){
    if(i<(n-1)){
      printf("%d ",list[i]);
    }else{
      printf("%d\n",list[i]);
    }
  }
  printf("%d\n",check);
}
