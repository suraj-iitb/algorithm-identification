int linearSearch(int );

int S[100000],n;

int main(){

  int i,j,q,T[50000],C;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d",&T[i]);
      if((linearSearch(T[i]))==0)
      C++;
    }
    printf("%d\n",C);
    return 0;
}

int linearSearch(int key){
  int i=0;
  S[n]=key;
  while(S[i]!=key){
    i++;
    if(i==n)
      return 1;
  }
  return 0; 
  }
