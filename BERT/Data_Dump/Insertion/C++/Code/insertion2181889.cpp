#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
using namespace std;

int N,v,j;
void insertionSort(int *list, int size);
void print(int *list, int size);

int main()
{
    scanf("%d", &N);
    int list[N];
    REP(i, N){
      scanf("%d", &list[i]);
    }
    insertionSort(list, N);
    return 0;
}

void insertionSort(int *list, int size)
{
    print(list, size);
    FOR(i, 1, size){
        v = list[i];
        j = i - 1;
        while( j >= 0 && list[j] > v) {
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = v;
        print(list, size);
    }
}

void print(int *list, int size) {
    REP(i, size){
      if (i == size - 1) {
        cout << list[i] << endl;
      } else {
        cout << list[i] << " ";
      }
    }
}
