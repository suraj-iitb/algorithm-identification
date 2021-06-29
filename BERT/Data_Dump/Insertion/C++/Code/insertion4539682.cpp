#include<iostream>

int main(){
    int a;
    std::cin>>a;
    int b[a];
    for(int i=0;i<a;i++){
        std::cin>>b[i];
    }
    for(int i=1;i<a;i++){
        int j=i-1;
        int v=b[i];
        for(int i=0;i<a;i++){
            if(i==a-1) std::cout<<b[i]<<std::endl;
            else std::cout<<b[i]<<" ";
        }
        while(j>=0&&b[j]>v){
            std::swap(b[j],b[j+1]);
            j--;
        }
    }
    for(int i=0;i<a;i++){
        if(i==a-1) std::cout<<b[i]<<std::endl;
        else std::cout<<b[i]<<" ";
    }
    return 0;
}

