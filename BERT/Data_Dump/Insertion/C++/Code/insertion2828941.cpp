#include <iostream>

void printList(int *a, int n){
    for(int c = 0; c < n; c++){
        if(c == n-1){
            std::cout << a[c] <<std::endl;
        }else{
            std::cout << a[c] << " ";
        }
    }
}

int main(){

    int n;
    int tmp;
    std::cin >> n;

    int a[n];

    for(int i = 0; i < n; i++){
        std::cin >> tmp;
        a[i] = tmp;
    }

    printList(a, n);


    for(int i = 1; i < n; i++){
        tmp = a[i];

        int j = i;
        
        while(j-1 >= 0 && a[j-1] > tmp){
            a[j] = a[j-1];
            j--;
        }
        a[j] = tmp;

        printList(a, n);
    }
}
