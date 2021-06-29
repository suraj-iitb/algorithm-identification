#include <stdio.h>

#define A 500000
#define B 2000000000

int L_s[A/2+2],R_s[A/2+2];
int count=0;

void meg(int in[],int z,int l,int m,int r){
  int s1,s2,i,j,k;

  s1=m-l;
  s2=r-m;
  
  for(i=0;i<s1;i++){
    L_s[i]=in[l+i];
  }
  for(i=0;i<s2;i++){
    R_s[i]=in[m+i];
  }

  L_s[s1]=R_s[s2]=B;
  i=j=0;
  for(k=l;k<r;k++){
    count++;
    if(L_s[i]<R_s[j]){
      in[k]=L_s[i++];
    }
    else {
      in[k]=R_s[j++];
    }
  }
}

void meg_sort(int in[],int z,int left,int right){
  if(left+1<right){
    int m=(left+right)/2;
    meg_sort(in,z,left,m);
    meg_sort(in,z,m,right);
    meg(in,z,left,m,right);
  }
}

int main()
{
  int in[A],i,g;

  scanf("%d",&g);
  for(i=0;i<g;i++){
    scanf("%d",&in[i]);
  }
  meg_sort(in,g,0,g);

  for(i=0;i<g;i++){
    if(i>0) printf(" ");
    printf("%d",in[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}
  

