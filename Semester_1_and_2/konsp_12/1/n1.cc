#include <bits/stdc++.h>

int main() {
	
	int arr[5] = {1, 2, 3, 4,5};
	int* n = arr;
	for (int i = 0; i<5; i++) {
		std::cout << *n << ' ';       
		++n;
	}	
	return 0;

}
