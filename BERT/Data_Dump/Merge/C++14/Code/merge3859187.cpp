#include <iostream>
#include <sstream>
#include <vector>

int compare_times = 0;

void my_merge(std::vector<int>& A, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    
    // create array L[0...n1], R[0...n2]
    std::vector<int> L(n1+1), R(n2+1);
    for(int i = 0; i < n1; i++){
	L.at(i) = A.at(left + i);
    }
    for(int i = 0; i < n2; i++){
	R.at(i) = A.at(mid + i);
    }
    const int SENTINEL = 1000000002;
    L.at(n1) = SENTINEL;
    R.at(n2) = SENTINEL;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
	compare_times++;
	if(L.at(i) <= R.at(j)){
	    A.at(k) = L.at(i);
	    i = i + 1;
	}else{
	    A.at(k) = R.at(j);
	    j = j + 1;
	}
    }
}

void my_merge_sort(std::vector<int>& A, int left, int right){
    if(left + 1 < right){
	int mid = (left + right) / 2;
	my_merge_sort(A, left, mid);
	my_merge_sort(A, mid, right);
	my_merge(A, left, mid, right);
    }
}

int main(int argc, char **argv){

    int n;
    std::cin >> n;

    std::vector<int> A(n);
    for(int i = 0; i < n; i++){
	std::cin >> A.at(i);
    }

    my_merge_sort(A, 0, A.size());

    std::stringstream ss;
    std::string sep = "";
    for(int i = 0; i < n; i++){
	ss << sep << A.at(i);
	sep = " ";
    }
    std::cout << ss.str() << std::endl;
    std::cout << compare_times << std::endl;
    
}

