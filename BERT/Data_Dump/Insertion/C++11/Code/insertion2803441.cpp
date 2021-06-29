#include<iostream>
#include<algorithm>
#include<vector>

void print_vec(std::vector<int> v){
	for(auto it=v.begin();it!=v.end();++it){
		std::cout << *it;
		if(it!=v.end()-1) std::cout << ' ';
		else std::cout << std::endl;
	}
}

int main() {
	int n;
	std::vector<int> ele;

	std::cin >> n;

	int temp;
	for(int i=0;i<n;i++){
		std::cin >> temp;
		ele.push_back(temp);
	}

	print_vec(ele);

	for(auto it1=ele.begin()+1;it1!=ele.end();++it1){
		auto it2=it1;
		int key=*it1;
		while(key < *(it2-1) && it2!=ele.begin()){
			*it2 = *(it2-1);
			*(it2-1) = key;
			--it2;
		}
		print_vec(ele);
	}

	return 0;
}

