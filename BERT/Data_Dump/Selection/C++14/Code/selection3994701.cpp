#include<algorithm>
#include<cstdio>
using namespace std;
static const int MAX = 100;

int n;
int A[MAX];

void selectionSort(){
    int min, num;
    num = 0;
    for (int i = 0; i < n; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
            if (A[min] > A[j]) min = j;
        }
        swap(A[i], A[min]);
        if (i != min) num++;
    }

    for (int i = 0; i < n; i++){
        if (i != n - 1) printf("%d ", A[i]);
        else printf("%d\n", A[i]);
    }
    printf("%d\n", num);
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    selectionSort();
    return 0;
}
