#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++){
        std::cin >> v[i];
    }
    for(int j=0;j<n;j++){
        std::cout << v[j];
        if(j<(n-1)) std::cout << " ";
        else std::cout << "\n";
     }
    for(int i=1;i<n;i++){
        int comp = v[i];
        int j = i-1;
        while(j>=0 && v[j] > comp){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = comp;
        for(int j=0;j<n;j++){
            std::cout << v[j];
            if(j<(n-1)) std::cout << " ";
            else std::cout << "\n";
        }
    }
    return 0;
}
