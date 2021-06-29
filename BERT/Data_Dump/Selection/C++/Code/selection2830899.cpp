#include <iostream>

void selectionSort(int *a, int n){

    int min_idx;
    int counter = 0;

    for(int i = 0; i < n; i++){
        min_idx = i;
        for(int j = i+1; j < n; j++){
            if(a[min_idx] > a[j]){
                min_idx = j;
            }
        }
        if(i != min_idx){
            counter++;
            std::swap(a[min_idx], a[i]);
        }
    }


    for(int c = 0; c < n; c++){
        if(c == n-1){
            std::cout << a[c] <<std::endl;
        }else{
            std::cout << a[c] << " ";
        }
    }
    
    std::cout << counter << std::endl;

}

int main(){

    int n, tmp;
    std::cin >> n;

    int a[n];

    for(int i = 0; i < n; i++){
        std::cin >> tmp;
        a[i] = tmp;
    }

    selectionSort(a, n);

}
