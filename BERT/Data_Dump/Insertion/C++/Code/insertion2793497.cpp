
#include<iostream>


void insert(int a[],int n){
  int i,j,k,v;
  for(i=0;i<n;i++){
    v = a[i];
    j = i-1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for(k=0;k<n;k++){
      if(k == n-1){
	std::cout<<a[k];
      }else{
	std::cout<<a[k]<<" ";
      }
    }
    std::cout<<"\n";
  }
}

int main(){
  int i,n,a[10000];

  std::cin>>n;
  for(i=0;i<n;i++){
    std::cin>>a[i];
  }
  insert(a,n);
  return 0;
}
