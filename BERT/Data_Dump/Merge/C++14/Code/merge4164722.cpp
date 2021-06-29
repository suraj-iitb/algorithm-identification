#include <iostream>
#include <climits>
using namespace std;

int c = 0;

void merge(int A[], int left, int mid, int right){
   int n1, n2; //分割後の要素数
   n1 = mid - left;
   n2 = right - mid;
   int L[n1 + 1], R[n2 + 1];
   for(int i = 0; i < n1; i++)
      L[i] = A[left + i];

   for(int i = 0; i < n2; i++)
      R[i] = A[mid + i];
   L[n1] = INT_MAX;
   R[n2] = INT_MAX;
 
   //ソートする
   int j = 0, k = 0;
   for(int i = left; i < right; i++){
      if(L[j] <= R[k]){
         A[i] = L[j];
         j++;
         c++;
      }
      else{
         A[i] = R[k];
         k++;
         c++;
      }
   }
}

void merge_sort(int A[], int left, int right){//マージソートする関数
   if(left + 1 < right){//もし要素が2つ以上であれば分割
      int mid = (left + right) / 2;
      merge_sort(A, left, mid);
      merge_sort(A, mid, right);
      
      //併合する
      merge(A, left, mid, right);
   }
}

int main(void){
    int n;
    cin >> n;
    int B[n];
    for(int i = 0; i < n; i++) cin >> B[i];

    merge_sort(B, 0, n);
    
    for(int i = 0; i < n; i++){
       if(i != n - 1)
       cout << B[i] << " ";
       else
       cout << B[i] << endl;
    }
    cout << c << endl;
}

