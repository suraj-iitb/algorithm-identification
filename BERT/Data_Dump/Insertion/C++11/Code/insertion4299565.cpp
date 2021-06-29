#include<bits/stdc++.h>

int main(void){
    int n;
    scanf("%d", &n);
    //std::cin >> n;
    std::vector<int> a(n);
    int v, j;

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i = 1; i < n; i++){

        for(auto i : a){
        std::cout << i;
        if(i != a[n-1]){
            std::cout << " ";
        }
    }
    std::cout << std::endl;

        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        
    }

    for(auto i : a){
        std::cout << i;
        if(i != a[n-1]){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}
