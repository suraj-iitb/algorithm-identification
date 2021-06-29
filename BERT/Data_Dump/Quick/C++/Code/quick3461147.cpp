#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

struct C{
    char mark;
    int value;
};

C c1[100000];
C c2[100000];
C L[50001];
C R[50001];

void merge(C c[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++){
        L[i] = c[left+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = c[mid+i];
    }
    L[n1].value = 1000000001;
    R[n2].value = 1000000001;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
        if(L[i].value <= R[j].value){
            c[k] = L[i];
            i++;
        }
        else{
            c[k] = R[j];
            j++;
        }
    }
}
 
void mergeSort(C c[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(c, left, mid);
        mergeSort(c, mid, right);
        merge(c, left, mid, right);
    }
}

int partition(C c[], int p, int r){
    C x = c[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(c[j].value <= x.value){
            i++;
            swap(c[i], c[j]);
        }
    }
    swap(c[i+1], c[r]);
    return i + 1;
}

void quickSort(C c[], int p, int r){
    if(p < r){
        int q = partition(c, p, r);
        quickSort(c, p, q-1);
        quickSort(c, q+1, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        scanf("%c%d", &c1[i].mark, &c1[i].value);
        c2[i] = c1[i];
        getchar();
    }

    mergeSort(c1, 0, n);
    quickSort(c2, 0, n-1);

    bool flag = true;
    for(int i = 0; i < n; i++){
        if(c1[i].mark != c2[i].mark){
            flag = false;
            break;
        }
    }

    if(flag){
        printf("Stable\n");
    }
    else{
        printf("Not stable\n");
    }
    for(int i = 0; i < n; i++){
        printf("%c %d\n", c2[i].mark, c2[i].value);
    }
}
