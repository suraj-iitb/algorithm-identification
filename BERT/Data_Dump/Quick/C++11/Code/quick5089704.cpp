#include <iostream>
using namespace std;

int c = 0, L[300000], R[300000], B[1000000], str_B[1000000], L_str[300000], R_str[300000];
void merge(int l, int mid, int r){
    int n1, n2, i, j;
    //cout << "l: " << l << "  r: " << r<< endl;
    n1 = mid - l;
    n2 = r - mid;
    for(int d = 0; d < n1; d++){
        L[d] = B[l + d];
        L_str[d] = str_B[l + d];
    }
    for(int i = 0; i < n2; i++){
        R[i] = B[mid + i];
        R_str[i] = str_B[mid + i];
        //cout << "L: " <<  L[i] << " R: " << R[i] << endl;
    }
    L[n1] = 1000000000;
    R[n2] = 1000000000;
    i = 0;
    j = 0;
    for(int k = l; k < r; k++){
        c += 1;
        if(L[i] <= R[j]){
            B[k] = L[i];
            str_B[k] = L_str[i];
            i += 1;
        }else{
            B[k] = R[j];
            str_B[k] = R_str[j];
            j += 1;
        }
    }
}
void mergesort(int l, int r){ //分割
    int mid;
    if ((l + 1) < r){
        mid = (l + r) / 2;
        mergesort(l, mid);
        mergesort(mid, r);
        merge(l, mid, r);
    }
}

int partition(int A[], int p, int r, char str[]){
    int x, i, j, tem, tem_str, t;
    x = A[r];
    i = p - 1;

    for(j = p; j < r; j++){
        if(A[j] <= x){
            i++;
            tem = A[i];
            tem_str = str[i];

            if(A[i] == A[i + 1] || A[i - 1]){
                c++;
            }
            A[i] = A[j];
            str[i] = str[j];

            A[j] = tem;
            str[j] = tem_str;
        }
    }
    tem = A[i + 1];
    tem_str = str[i + 1];
    if(A[i] == A[i + 1] || A[i - 1]){
        c++;
    }
    A[i + 1] = A[r];
    str[i + 1] = str[r];
    A[r] = tem;
    str[r] = tem_str;
    return i + 1;
}
void quicksort(int A[], int p, int r, char str[]){
    int q;
    if (p < r){
        q = partition(A, p, r, str);
        quicksort(A, p, q - 1, str);
        quicksort(A, q + 1, r, str);
    }
}
int main(){
    int n, A[1000000],tem = 0, flag = 0, ca = 0;
    char str[1000000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str[i] >> A[i];
        B[i] = A[i];
        str_B[i] = str[i];
    }
    quicksort(A, 0, n - 1, str);
    mergesort(0, n);
    //cout << c << " " << ca << endl;
    for(int i = 0; i < n; i++){
        if(str[i] != str_B[i]){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        cout << "Not stable" << endl;
    }else{
        cout << "Stable" << endl;
    }
    for(int i = 0; i < n; i++){
        cout << str[i] << " " << A[i] << endl;
    }
    return 0;

}
