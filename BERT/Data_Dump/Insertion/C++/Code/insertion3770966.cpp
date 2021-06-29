#include <bits/stdc++.h>

int main(){
    
    int n;
    std::cin >> n;
    
    const int N = n;
    int Array[N];
    
    for(int i = 0; i < N; i++){
        std::cin >> Array[i];
    }
    
    for(int i = 1; i < N; i++){
        
        for(int k = 0; k < N; k++){
            std::cout << Array[k];
            if(k == N -1 ){
                std::cout << "\n";
            } else {std::cout << " ";}
        }
        
        int key = Array[i];
        int j = i - 1;
        while( (j >= 0) && (Array[j] > key) ){
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = key;
    }
    for(int k = 0; k < N; k++){
        std::cout << Array[k];
        if(k == N -1 ){
            std::cout << "\n";
        } else {std::cout << " ";}
    }
    
    return 0;
}
