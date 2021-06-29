#include<iostream>
#include<vector>
int main(){
    int n;
    std::vector<int> v;
    std::cin>>n;
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        v.push_back(x);
    }
    int cnt=0;
   for (int i=1;i<n;i++) {
       for(int j=0;j<n;j++){
           std::cout<<v[j];
           if(j!=n-1)std::cout<<" ";
       }
       std::cout<<"\n";
    int tmp=v[i];
    if(v[i-1]>tmp) {
        int  j=i;
        do {
            v[j]=v[j-1];
            j--;
        } while (j>0 && v[j-1]>tmp);
        v[j]=tmp;
       }
       
        
   }
   for(int i=0;i<n;i++){
       std::cout<<v[i];
       if(i!=n-1)std::cout<<" ";
   }
   std::cout<<"\n";
}



