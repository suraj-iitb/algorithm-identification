

#include <iostream>
using namespace std;


void show(int* list, int N){
    for (int i=0; i<N-1; i++)
        cout << list[i] << " ";
    cout << list[N-1] << endl;
}

int selection_sort(int* list, int N){
    int count = 0;
    for (int i=0; i<N-1; i++){
        int min = i;
        for (int j=i+1; j<N; j++){
            if (list[min] > list[j])
                min = j;
        }
        swap(list[min], list[i]);
        if (min != i) count += 1;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i=0; i<N; i++) cin >> a[i];
    
    int count = selection_sort(a, N);
    show(a, N);
    cout << count << endl;
    return 0;
}
