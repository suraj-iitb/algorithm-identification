#include <stdio.h>
#define max 100000
#define nel 2000000000
#define n_max 9000000000
struct card{
  char it;
  int lue;
};

struct card L[max/2+2],R[max/2+2];

void c_merge(struct card *,int ,int  ,int , int );
void c_sort(struct card *,int ,int ,int );
int c_p (struct card *,int ,int ,int );
void c_q(struct card *,int ,int ,int );



int main(){
  int n,i,v,O[n_max],M[n_max];
  struct card P[max],Q[max];
  char S[10];
  int ble=1;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",S,&v);
    P[i].it=Q[i].it=S[0];
    P[i].lue=Q[i].lue=v;
  }
  c_sort(P,n,0,n);
  c_q(Q,n,0,n-1);
  for(i=0;i<n;i++){
    if(P[i].it !=Q[i].it)ble=0;
  }

  if(ble==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",Q[i].it,Q[i].lue);
  }
  return 0;
}


void c_merge(struct card P[],int n,int left ,int mid, int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;
  for(i=0;i<n1;i++)L[i]=P[left+i];
  for(i=0;i<n2;i++)R[i]=P[mid+i];
  L[n1].lue=R[n2].lue=nel;
  i=j=0;
  for(k=left;k<right;k++){
    if(L[i].lue<=R[j].lue){
      P[k]=L[i++];
    }else {
      P[k]=R[j++];
    }
  }
}


void c_sort(struct card P[],int n,int left,int right){
  int mid;
  if (left+1<right){
    mid=(left+right)/2;
    c_sort(P,n,left,mid);
    c_sort(P,n,mid,right);
    c_merge(P,n,left,mid,right);
  }
}

int c_p (struct card P[],int n,int p,int r){
  int i,j;
  struct card t,x;
  x=P[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(P[j].lue<=x.lue){
      i++;
      t=P[i];
      P[i]=P[j];
      P[j]=t;
    }
  }
  t=P[i+1];
  P[i+1]=P[r];
  P[r]=t;
  return i+1;
}

void c_q(struct card P[],int n,int p,int r){
  int q;
  if(p<r){
    q=c_p(P,n,p,r);
    c_q(P,n,p,q-1);
    c_q(P,n,q+1,r);
  }
}


