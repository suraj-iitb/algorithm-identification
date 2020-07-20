#include<iostream>
#include<vector>
#include<algorithm>

int bubblesort(int n, std::vector<int> &a){
    int number_of_swap = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= i+1; j--){
            if(a[j-1] > a[j]) {
                std::swap(a[j-1], a[j]);
                number_of_swap++;
            }
        }
    }
    
    return number_of_swap;
}

int main(){
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    
    int number_of_swap = bubblesort(n, a);
    
    for(int i = 0; i < n; i++){
        if(i) std::cout << " ";
        std::cout << a[i];
    }
    std::cout << std::endl;
    
    std::cout << number_of_swap << std::endl;
    return 0;
}


