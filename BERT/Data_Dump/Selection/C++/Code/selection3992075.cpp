#include<iostream>
#include<algorithm>

int selection_sort(int a[], int n){
    int sw = 0;
    for(int i = 0; i < n-1; i++){
        int mini = i;
        for(int j = i; j < n; j++){
            if(a[mini] > a[j]) mini = j;
        }
        std::swap(a[mini], a[i]);
        if (mini != i) sw++;
    }
    return sw;
}

int main(void){
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int swap_number = selection_sort(a, n);

    for(int i = 0; i < n; i++){
        if(i != n-1){
            std::cout << a[i] << " ";
        }
        else{
            std::cout << a[i] << std::endl;
        }
    }
    std::cout << swap_number << std::endl;
    return 0;
}
