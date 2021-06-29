#include<iostream>
#include<vector>
int main(){
    int a;
    std::cin>>a;
    std::vector<int>vec(a);
    for(int i=0;i<a;i++){
        std::cin>>vec[i];
    }
    int mini=0,count=0;
    for(int i=0;i<a;i++){
        mini=i;
        for(int j=i;j<a;j++){
            if(vec[mini]>vec[j]){
                mini=j;
            }
            
        }
        if(mini!=i)count++;
        std::swap(vec[mini],vec[i]);
    }
    for(int i=0;i<a;i++){
        std::cout<<vec[i];
        if(i<a-1)std::cout<<" ";
    }
    std::cout<<std::endl;
    std::cout<<count<<std::endl;
    return 0;
}
