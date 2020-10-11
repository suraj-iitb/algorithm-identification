#include<stdio.h>
#include<stdlib.h>



typedef struct{
  int key;
  char s;
}card;






int n;



int partition(card **A,int p,int r){
  int x;
  card *swap;
  x=A[r]->key;
  int i,j;
  i=p;
  for(j=p;j<=r;j++){
    if((A[j]->key) <= x){
       swap=A[i];
       A[i]=A[j];
       A[j]=swap;
       i++;
    }
  }
  return i-1;
}

void q_sort(card **A,int a,int b){
  int q;
  q=partition(A,a,b);
  if(q-1 > a) q_sort(A,a,q-1);
  if(q+1 < b) q_sort(A,q+1,b);
}



void stable(card **A,card **B){
    int i,j,k=0;
    for(i=0;i<n-1;i++){
      if(A[i]->key !=A[i+1]->key) k=0;
      else{
        for(j=k;j<n;j++){
          if(A[i]->key == B[j]->key){
            if(A[i]->s!=B[j]->s){
              printf("Not stable\n");
              return;
            }
            k=j+1;
            break;
          }
        }
      }
    }
    printf("Stable\n");
}


int main(){
  int i;
  card **A,**B;
  scanf("%d",&n);
  A=malloc(n*sizeof(card *));
  B=malloc(n*sizeof(card *));
  for(i=0;i<n;i++){
    A[i]=malloc(sizeof(card));
    B[i]=malloc(sizeof(card));
    scanf(" %c",&(A[i]->s));
    scanf("%d",&(A[i]->key));
    B[i]->key=A[i]->key;
    B[i]->s=A[i]->s;
  }
  q_sort(A,0,n-1);
  stable(A,B);
  for(i=0;i<n;i++) printf("%c %d\n",A[i]->s,A[i]->key);
  return 0;
}
  
