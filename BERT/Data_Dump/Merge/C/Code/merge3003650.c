#include<stdio.h>

#define N 500000
#define Keeper 1000000001

int count;

void Merge(int *,int,int,int);
void MergeSort(int *,int,int);

int main(){
  int i;
  int Re[N],lo;

  scanf(" %d",&lo);
  for(i = 0 ; i < lo ; i++){
    scanf(" %d",&Re[i]);
  }

  MergeSort(Re,0,lo);

  for(i = 0 ; i < lo-1 ; i++){
    printf("%d ",Re[i]);
  }

  printf("%d\n%d\n",Re[lo-1],count);

  return 0;
}

  void Merge(int *X,int lside,int center,int rside){
    int i,j,k;
    int Lreng,Rreng;
    int Left[N/2+3],Right[N/2+3];

    Lreng = center - lside;
    Rreng = rside - center;

    for(i = 0 ; i < Lreng ; i++){
      Left[i] = X[lside+i];
    }

    for(i = 0 ; i < Rreng ; i++){
      Right[i] = X[center+i];
    }

    Left[Lreng] = Keeper;
    Right[Rreng] = Keeper;

    i = 0;
    j = 0;

    for(k = lside ; k < rside ; k++){
      if(Left[i] <= Right[j]){
        X[k] = Left[i];
        i++;
        count++;
      }
      else{
        X[k] = Right[j];
        j++;
        count++;
      }
    }

  }

  void MergeSort(int *X,int lside,int rside){
    int center;

    if(lside+1 < rside){
      center = (lside+rside) / 2;
      MergeSort(X,lside,center);
      MergeSort(X,center,rside);
      Merge(X,lside,center,rside);
    }
    }

