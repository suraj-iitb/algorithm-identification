#include<stdio.h>

int se(int X[],int num,int bn){
  int i=0;
  X[num] = bn;
  
  while(X[i] != bn){
    i++;
  }
  return i != num;
}

int main(){
  int i,num,An[10000+1],Bn,num2,S=0;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%d",&An[i]);
  }

  scanf("%d",&num2);
  for(i=0;i<num2;i++){
    scanf("%d",&Bn);
    if(se(An,num,Bn)){
      S++;
    }
  }

    printf("%d\n",S);

    return 0;
	  	 
}

