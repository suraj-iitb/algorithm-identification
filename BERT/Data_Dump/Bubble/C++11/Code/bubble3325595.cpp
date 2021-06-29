//	-*- mode: C++ -*-
//	Bubble Sort
//		Write a program of the Bubble Sort algorithm which sorts a sequence A in ascending order. The algorithm should be based on the following pseudocode:

//		BubbleSort(A)
//		1 for i = 0 to A.length-1
//		2     for j = A.length-1 downto i+1
//		3         if A[j] < A[j-1]
//		4             swap A[j] and A[j-1]
//		Note that, indices for array elements are based on 0-origin.

//		Your program should also print the number of swap operations defined in line 4 of the pseudocode.

//	Input
//		The first line of the input includes an integer N, the number of elements in the sequence.

//		In the second line, N elements of the sequence are given separated by spaces characters.

//	Output
//		The output consists of 2 lines.

//		In the first line, please print the sorted sequence. Two contiguous elements of the sequence should be separated by a space character.

//		In the second line, please print the number of swap operations.

//	Constraints
//		1 ≤ N ≤ 100

//	Sample Input 1
//		5
//		5 3 2 4 1
//	Sample Output 1
//		1 2 3 4 5
//		8

//	Sample Input 2
//		6
//		5 2 4 6 1 3
//	Sample Output 2
//		1 2 3 4 5 6
//		9

#include <iostream>
#include <vector>

unsigned int BubbleSort(std::vector<int>&	A)
{
	unsigned int swapCount	{0};

	for(unsigned int i = 0; i < A.size() - 1; i++){
		for(unsigned int j = A.size() - 1; j > i; j--){
			if(A[j] < A[j - 1]){
				auto	tmp	= A[j];
				A[j]		= A[j - 1];
				A[j - 1]	= tmp;
				swapCount++;
			}
		}
	}

	return swapCount;
}

int	main(int	argc,
		 char*	argv[])
{
	unsigned int		N	{0};
	std::vector<int>	A	{};

	std::cin >> N;

	for(unsigned int i = 0; i < N; i++){
		int	element	{0};
		std::cin >> element;
		A.push_back(element);
	}

	unsigned int swapCount	= BubbleSort(A);

	unsigned int count	{0};

	for(auto element : A){
		std::cout << element;
		count++;
		if(count < N){
			std::cout << ' ';
		}
		else{
			std::cout << '\n';
		}
	}

	std::cout << swapCount << '\n';
    return 0;
}

