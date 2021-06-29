#include <iostream>
using namespace std;

typedef struct {
  int value;
  char mark;
}card;

int isstable(card *ori, card *srt,int N){
  int i=0,flg;
  while (i<N){
    flg=0;
    for (int j=0;j<N;j++){
      if (srt[i].value==ori[j].value && srt[i].mark==ori[j].mark){
	if (i+1<N && srt[i].value==srt[i+1].value)i++;
	else{
	  flg=1;
	  i++;
	  break;
	}
      }
    }
    if (flg) continue;
    else return 0;
  }
  return 1;
}

int partition(card *A,int p,int r){
  int x,i;
  card t;
  x=A[r].value;
  i=p-1;
  
  for (int j=p;j<r;j++){
    if (A[j].value<=x){
      i++;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  }

  t=A[i+1];
  A[i+1]=A[r];
  A[r]=t;

  return i+1;
}

void quicksort(card *A,int p,int r){
  int q;
  if (p<r){
    q = partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

int main(){
  int i,n;
  card A[100005];
  card B[100005];
  
  cin >> n;
  for(i=0;i<n;i++){
    cin >> A[i].mark >> A[i].value;
    B[i]=A[i];
  }
  quicksort(B,0,n-1);

  if (isstable(A,B,n))cout << "Stable" << endl;
  else cout << "Not stable"<<endl;

  for (i=0;i<n;i++)
    cout << B[i].mark << " " << B[i].value << endl;
  
  
  return 0;
}
