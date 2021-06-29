#include<iostream>
#include<vector>

int selectionsort(std::vector<int> &a,int &n);

int main(){
    int n;
    std::cin>>n;

    std::vector<int> a(n);
    for(auto &x:a){
        std::cin>>x;
    }

    int count = selectionsort(a,n);
    

    for(int k=0;k<n;k++){
        std::cout<<(k?" ":"")<<a[k];
    }
    std::cout<<std::endl;
    std::cout<<count<<std::endl;
    return 0;

}

int selectionsort(std::vector<int> &a,int &n){
    int minj;
    int count = 0;

    for(int i=0;i<n;i++){
        minj = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(i!=minj){
            std::swap(a[i],a[minj]);
            count +=1;
        }
    }

    return count;
}
