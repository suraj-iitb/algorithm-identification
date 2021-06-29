
#include<iostream>

void insertionSort(int a[],int n)
{
  int i,j,v;
  for(i=0;i<n;++i){
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
      a[j+1]=v;
    }
  }
}

int main()
{
  int n,i,j;
  std::cin>>n;

  int a[n];
  for(i=0;i<n;++i){
    std::cin>>a[i];
  }

  for(j=1;j<=n;++j){
    insertionSort(a,j);
    for(i=0;i<n-1;++i){
      std::cout<<a[i]<<" ";
    }
    std::cout<<a[n-1]<<"\n";
  }


  return 0;
}

