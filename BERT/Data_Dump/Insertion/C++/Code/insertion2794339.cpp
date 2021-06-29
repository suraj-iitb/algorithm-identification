#include <iostream>

void print_array(int a[], int n){
    for(int i=0; i<n; i++){
        std::cout << a[i];
        if(i<n-1){
            std::cout << " ";
        }
    }
    std::cout << '\n';
}

void sort(int a[], int n){
    print_array(a,n);
    for(int i=1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        print_array(a,n);
    }
}

int main(){

    int N;
    std::cin >> N;
    int A[N];
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }

    sort(A,N);

    return 0;
}
