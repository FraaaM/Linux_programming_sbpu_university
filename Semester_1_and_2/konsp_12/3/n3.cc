#include <iostream>
#include <climits>

int main() {
        
	unsigned int ua = UINT_MAX;
	std::cout << "ua=" <<  ua << '\n';
        int a = static_cast<int>(ua);
	std::cout << "a=" << a  << '\n';
        
	int b = INT_MAX;
	std::cout << "b=" << b << '\n';
        unsigned int ub = static_cast<unsigned int>(b);
	std:: cout << "ub=" << ub << '\n';
        
	return 0;
}
