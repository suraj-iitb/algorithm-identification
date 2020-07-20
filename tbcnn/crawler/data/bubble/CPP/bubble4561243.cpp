#include<iostream>
#include<vector>

int main(){
    int a,count=0;
    std::cin>>a;
    std::vector<int>vec(a);
    for(int i=0;i<a;i++){
        std::cin>>vec[i];
    }
    int flag=1;
    while(flag){
        flag=0;
        for(int i=a-1;i>0;i--){
            if(vec[i-1]>vec[i]){
                std::swap(vec[i-1],vec[i]);
                flag=1;
                count++;
            }
        }
    }
    for(int i=0;i<a;i++){
        std::cout<<vec[i];
        if(i!=a-1)std::cout<<" ";
    }
    std::cout<<std::endl;
    std::cout<<count<<std::endl;
}
