#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int a[100];
  for(int i=0;i < n;i++){
 std::cin>>a[i];
  }

 for(int k=0;k<n;k++){
   if(k<n-1){
   std::cout<<a[k]<<" ";
   }
   else std::cout<<a[k]<<"\n";
    } 
    
  int j,v;
  for(int i=1;i<n;i++){
    v = a[i];
    j = i-1;
    while(j>=0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
 for(int k=0;k<n;k++){
  if(k<n-1){
   std::cout<<a[k]<<" ";
  }
else std::cout<<a[k]<<"\n";
    }
  }
 return 0;
}
