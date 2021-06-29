#include <iostream>
#include <vector>

int main(){
  int n,s,t;
  std::cin>>n;

  std::vector<int>a;
  int x;
  for(int i=0;i<n;i++){
    std::cin>>x;
    a.push_back(x);
  }

  for(int i=0;i<n;i++){

    s=a[i];
    t=i-1;
    while(t>=0 && a[t]>s){
      a[t+1]=a[t];
      t--;
    }
    a[t+1]=s;

    for(int j=0;j<n;j++){
      if(j==n-1){
	std::cout<<a[j]<<"\n";
	break;
      }
      std::cout<<a[j]<<" ";
    }

  }

  return 0;
}
