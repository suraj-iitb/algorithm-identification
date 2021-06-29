#include <iostream>
#include <algorithm>
#define INFTY 1e9+1

using namespace std;

typedef struct tCard_
{
    char mark;
    int num;
}tCard;

int Partition(tCard card[], int p, int r){
    int x = card[r].num;
    int i = p;
    
    for(int j = p; j < r; j++){
        if(card[j].num <= x){
        swap(card[i++], card[j]);
        }
    }
    swap(card[i], card[r]);
    return i;
}

void QuickSort(tCard card[], int p, int r){
    int q;
    if(p < r){
        q = Partition(card, p, r);
        QuickSort(card, p, q-1);
        QuickSort(card, q+1, r);
    }
}

void Marge(tCard c[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    tCard L[n1], R[n2];
    int i, j, k;

    for(i = 0; i < n1; i++){
        L[i] = c[left+i];
    }
    for(i = 0; i < n2; i++){
        R[i] = c[mid+i];
    }

    L[n1].num = INFTY;
    R[n2].num = INFTY;
    i=0; j=0;

    for(k = left; k < right; k++){
        if(L[i].num <= R[j].num){
            c[k] = L[i];
            i++;
        }
        else{
            c[k] = R[j];
            j++;
        }
    }
}

void MargeSort(tCard c[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        MargeSort(c, left, mid);
        MargeSort(c, mid, right);
        Marge(c, left, mid, right);
    }
}

bool isStable(tCard c1[], tCard c2[], int N){
    for(int i = 0; i < N; i++){
        if(c1[i].mark != c2[i].mark){ return false; }
    }
    return true;
}

int main(){
    int n;
    tCard qc[100000], mc[100000];
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> qc[i].mark >> qc[i].num;
        mc[i].mark = qc[i].mark;
        mc[i].num = qc[i].num;
    }
    
    QuickSort(qc, 0, n-1);
    MargeSort(mc, 0, n);
    
    if(isStable(qc, mc, n)){ cout << "Stable" << endl; }
    else{ cout << "Not stable" << endl; }
    for(int i = 0; i < n; i++){
        cout << qc[i].mark << " " << qc[i].num << endl;
    }

    return 0;
}
