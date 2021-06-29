#include<iostream>

void print_array(int a[],int n){
    
    for (int k=0; k<n; k++){
        if (k>0) std::cout << ' ';
        std::cout << a[k] ;
    }
    std::cout << '\n';
}

int main(){
    int n;
    std::cin >> n;
    int a[n],key;
    for (int i = 0;i<n; i++){
        std::cin >> a[i];
    }
    for (int i=1;i<n;i++){
        
        print_array(a,n);
        key = a[i];
        for (int j = i; j>=0; j--){
            if(key < a[j-1]){
                a[j] = a[j-1];
            }else {
                a[j] = key;
                break;
            }
        }
    }
    print_array(a,n);
    
    return 0;
}

