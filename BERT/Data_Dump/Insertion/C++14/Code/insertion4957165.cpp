#include <iostream>
#include <vector>

int main(){

    int n;
    std::cin>>n;
    std::vector<int> a(n,0);
    for(auto &x:a){
        std::cin>>x;
    }

    int temp;

    for (int i=0;i<n;i++){
        temp = a[i];
        int j = i - 1;
        while(j>=0&&a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] =temp;
        for(int i = 0;i<n;i++){
           std::cout<<(i ? " " : "")<<a[i];
        } 
        std::cout<<std::endl;
    }
    return 0;
}



