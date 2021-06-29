#include<bits/stdc++.h>

void displayVector(std::vector<int> a, int n){
    for(int i = 0; i < n; i++){
        std::cout << a[i];
        if(i != n-1){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int bubbleSort(std::vector<int>& a, int n){
    bool flag = true;
    int tmp;
    int cnt = 0;
    //displayVector(a, n);
    while(flag){
        flag = false;
        for(int j = n-1; j > 0; --j){
            if(a[j] < a[j-1]){
                tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
                cnt++;
                flag = true;
            }
        }
        //displayVector(a, n);
    }
    return cnt;
}

int main(void){
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    
    int cnt = bubbleSort(a, n);
    displayVector(a, n);
    std::cout << cnt << std::endl;
    return 0;
}
