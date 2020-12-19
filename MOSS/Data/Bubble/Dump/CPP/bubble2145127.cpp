#include<iostream>

int main(){
	int n;
	int a[100];
	int i,j;
	int bf;
	int counter=0;

	std::cin >> n;
	for(i=0;i<n;i++){
		std::cin >> a[i];
	}

	for(i=0;i<n;i++){
		for(j=n-1;j>=i+1;j--){
			if(a[j] < a[j-1]){
				bf = a[j];
				a[j] = a[j-1];
				a[j-1] = bf;
				counter++;
			}
		}
	}

	for(i=0;i<n;i++){
		if(i>0){
			std::cout << " ";
		}
		std::cout << a[i];
	}
	std::cout << "\n";
	std::cout << counter << "\n";

	return (0);
}
