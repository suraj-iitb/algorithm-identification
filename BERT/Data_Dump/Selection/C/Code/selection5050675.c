#include<stdio.h>
int main(){
  int hr,c,cn=0,j,i,f,N,in[100],minj,t;
  scanf("%d",&N);
  for(i=0;i<N;i++){
  scanf("%d",&in[i]);
  }
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(in[j]<in[minj])minj=j;
    }
    if(in[i]==in[minj])cn--;
    t=in[i];
    in[i]=in[minj];
    in[minj]=t;
    cn++;
    hr=0;
    for(c=0;c<N-1;c++){
      if(in[c]<in[c+1])hr++;
    }
    if(hr==N-1)break;
  }
  for(f=0;f<N;f++){
    printf("%d",in[f]);
    if(f<N-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",cn);
  return 0;
}


