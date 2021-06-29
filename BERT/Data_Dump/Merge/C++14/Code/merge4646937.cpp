#include<iostream>
#include<vector>

std::vector<int> A;
static const int INF = 1001001001;
int cnt = 0;

void merge(int left, int midp1, int right){
    std::vector<int> B, C;
    int an, bn, cn, j, k;

    an = right - left + 1;
    bn = midp1 - left;
    cn = right - midp1 + 1;

    B.resize(bn);
    C.resize(cn);

    for(int i = 0; i < bn; i++){
	B[i] = A[left + i];
    }
    for(int i = 0; i < cn; i++){
	C[i] = A[midp1 + i];
    }

    B.push_back(INF);
    C.push_back(INF);

    j = 0;
    k = 0;

    for(int i = 0; i < an; i++){
	if(B[j] < C[k]){
	    A[left + i] = B[j];
	    j++;
	}else{
	    A[left + i] = C[k];
	    k++;
	}
	cnt++;
    }
}

int mergeSort(int left, int right){
    if(left >= right){
	return 0;
    }
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid + 1, right);
    return 0;
}
    

int main(void){
    int m, n;
    std::cin >> n;
    A.resize(n);

    for(int i = 0; i < n; i++){
	std::cin >> A[i];
    }

    mergeSort(0, n-1);

    for(int i = 0; i < n; i++){
	if(i != 0){
	    std::cout << " " << A[i];
	}else{
	    std::cout << A[i];
	}
    }
    std::cout << std::endl;

    std::cout << cnt << std::endl;

    return 0;

}

