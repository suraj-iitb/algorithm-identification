#include <stdio.h>

int ttt[5000000];
void merge(int *,int,int);
int co=0;

int main(){
  int i,q,n,m;
  int t[2500050],u[2500050];

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  merge(t, 0, q-1);

  for(i=0;i<q;i++){
    if(i!=q-1){
      printf("%d ",t[i]);
    }
    else printf("%d",t[i]);
  }
  printf("\n%d\n",co);
}


void merge(int t[ ],int left,int right){
  int md,i,j,o;

  if(left>=right){
    return;
  }

  md=(left+right)/2;
  merge(t, left, md);
  merge(t, md+1, right);

  for(i=left;i<=md;i++)
    ttt[i]=t[i];
  

  for(i=md+1,j=right; i<=right; i++,j--){
    ttt[i]=t[j];
  }

  i=left;
  j=right;

  for(o=left;o<=right;o++)
    if(ttt[i]<=ttt[j]){
      co++;
      t[o]=ttt[i++];
    }
    else{
      co++;
      t[o]=ttt[j--];
    }

}


