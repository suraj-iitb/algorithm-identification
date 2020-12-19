#include<iostream>
int main(){
	int n;
	int a[100];
	int key;
	int i,j,k;

	std::cin >> n;
	for(i=0;i<n;i++){
		std::cin >> a[i];
	}
	for(i=0;i<n;i++){
		if(i>0){
			std::cout << " ";
		}
		std::cout << a[i];
	}
	std::cout << "\n";

	for(i=1;i<n;i++){
		key = a[i];
		j=i-1;
		while(j>=0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
		for(k=0;k<n;k++){
			if(k>0){
				std::cout << " ";
			}
			std::cout << a[k];
		}
		std::cout << "\n";
	}
	return (0);
}
