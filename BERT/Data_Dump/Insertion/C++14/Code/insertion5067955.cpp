#include<iostream>
#include<vector>
void insertion_sort(std::vector<int> &a){
    int N = a.size();
    for(int i=0; i<N; ++i) std::cout << a[i] << (i == N-1 ? '\n' : ' ');
    for(int i=1; i<N; ++i){
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = v;
        for(int i=0; i<N; ++i) std::cout << a[i] << (i == N-1 ? '\n' : ' ');
    }
    return;
}

int main(){
    int N; std::cin >> N;
    std::vector<int> a(N);
    for(int i=0; i<N; ++i) std::cin >> a[i];
    insertion_sort(a);
    return 0;
}
