#include <iostream>
#include<vector>

void insertion(std::vector<int>& a, int n){
    for(int i=0;i<n;i++){
        int v = a[i];
        int j = i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(int k=0;k<n;k++){
            std::cout << a[k];
            if(k<n-1){
                std::cout << " ";
            }else{
                std::cout << '\n';
            }
        }
    }
}


int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }
    insertion(a,n);
    return 0;
}
