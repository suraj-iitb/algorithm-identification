#include <stdio.h>

#define N 100000

typedef struct{
  char type;
  int data;
}A;

int flag=0;

int prtition(A *,int,int);
void my_q_sort(A *,int,int);

int main(){
  int n,i,j,now;
  A ain[N],aout[N];
  //int check[1000000000]={0};
  //char check_c[1000000000][4]={0};

  scanf("%d\n",&n);

  for(i=0; i<n; i++){
    scanf("%c %d\n",&ain[i].type,&ain[i].data);
    aout[i]=ain[i];
    /*check_c[ain[i].data][check[ain[i].data]]=ain[i].type;
    check[ain[i].data]++;
    printf("DEBUG CALC");*/
  }
  /*for(i=0; i<n; i++){
    printf("%c %d\n",aout[i].type,aout[i].data);
    }*/
  my_q_sort(aout,0,n-1);
  now=aout[0].data;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(ain[j].data==now){
	if(ain[i].type!=aout[i].type){
	  flag=1;
	  break;
	}
      }
    }
    now++;
    if(flag==1) break;
  }
  
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  for(i=0; i<n; i++){
    printf("%c %d\n",aout[i].type,aout[i].data);
  }
  
  return 0;
}

int partition(A *a,int p,int r){
  int x,i,j;
  A t;
  x=a[r].data;
  i=p-1;
  //printf("x=%d,i=%d,p=%d,r=%d\n",x,i,p,r);
  for(j=p; j<r; j++){
    if(a[j].data<=x){
      i++;
      //t=a[i].data;a[i].data=a[j].data;a[j].data=t;
      //T=a[i].type;a[i].type=a[j].type;a[j].type=T;
      t=a[i];a[i]=a[j];a[j]=t;
    }
  }
  //t=a[i+1].data;a[i+1].data=a[r].data;a[r].data=t;
  //T=a[i+1].type;a[i+1].type=a[r].type;a[r].type=T;
  t=a[i+1];a[i+1]=a[r];a[r]=t;
  return i+1;
}

void my_q_sort(A *a,int p,int r){
  int q;
  if(p<r){
    q=partition(a,p,r);
    my_q_sort(a,p,q-1);
    my_q_sort(a,q+1,r);
  }
}

