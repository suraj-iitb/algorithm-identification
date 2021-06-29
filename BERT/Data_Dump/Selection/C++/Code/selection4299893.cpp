#include<bits/stdc++.h>

int selectionSort(std::vector<int>& a, int n){
    int minj, tmp, cnt;
    cnt = 0;
    for(int i = 0;  i < n; i++){
        minj = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
        if(i != minj){
            cnt++;
        }
    }
    return cnt;
}

void displayVector(std::vector<int> a, int n){
    for(int i = 0; i < n; i++){
        std::cout << a[i];
        if(i != n-1){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main(void){
    int n, cnt;
    scanf("%d", &n);
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    cnt = selectionSort(a, n);
    displayVector(a, n);
    std::cout << cnt << std::endl;
    
    return 0;
}
