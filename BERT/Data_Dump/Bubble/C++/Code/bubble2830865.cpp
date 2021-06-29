#include <iostream>

void bubbleSort(int *a, int n){

    int tmp;
    int counter = 0;

    for(int i = n-1; i > 0; i--){
        for(int j = n-1; j > n-i-1; j--){
            if(a[j] < a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                counter++;
            }
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

    bubbleSort(a, n);


}
