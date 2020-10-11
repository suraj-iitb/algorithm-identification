#include<stdio.h>

int Partition(int p, int r);
void QuickSort(int p, int r);

int Anum[1000000];
char Amark[1000000];
int Anum0id[1000000];
char Amark0id[1000000];
void aaaaa(int);

int n, a=10;

int main(){
  int isStable = -1;
  int i, p, j;
  char tmp[10];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%s %d", tmp, &Anum[i]);
    Amark[i]=tmp[0];
    Anum0id[i]=Anum[i];
    Amark0id[i]=tmp[0];
  }
  QuickSort(0, n-1);
  for(i=1; i<n; i++){
    if(Anum[i-1]==Anum[i]){
      for(j=0; j<n; j++){
	if(Amark0id[j]==Amark[i] && Anum0id[j]==Anum[i]){
	  isStable=0;
	  break;
	}
	else if(Amark0id[j]==Amark[i-1] && Anum0id[j]==Anum[i-1]){
	  break;
	}
      }
    }
    if(isStable==0)break;
  }
  if(isStable==-1)isStable=1;
  if(isStable)printf("Stable\n");
  else printf("Not stable\n");

  for(i=0; i<n; i++){
    printf("%c %d\n", Amark[i], Anum[i]);
  }
  aaaaa(a);
  return 0;
}

void aaaaa(int a){
  int i, count=0;
  for(i=0; i<a; i++){
    count++;
  }
}
int Partition(int p, int r){
  int x, i, j, tmp;
  x=Anum[r];
  i=p-1;
  for(j=p; j<=r-1; j++){
    if(Anum[j]<=x){
      i++;
      tmp=Anum[i];
      Anum[i]=Anum[j];
      Anum[j]=tmp;
      tmp=Amark[i];
      Amark[i]=Amark[j];
      Amark[j]=tmp;
    }
  }
  tmp=Anum[i+1];
  Anum[i+1]=Anum[r];
  Anum[r]=tmp;
  tmp=Amark[i+1];
  Amark[i+1]=Amark[r];
  Amark[r]=tmp;
  return i+1;
}

void QuickSort(int p, int r){
  int q;
  if(p<r){
    q=Partition(p, r);
    QuickSort(p, q-1);
    QuickSort(q+1, r);
  }
}

