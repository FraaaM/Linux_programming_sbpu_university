#include <iostream> 

int main() {
        int a =10 ;
        char b = 'c';
        bool c = true;
	//std::cout << "address a: " << &a << "\naddress b: " << &b << "\naddress c: " << &c << "\n\n";
        uintptr_t adrA = reinterpret_cast<uintptr_t>(&a);
        uintptr_t adrB = reinterpret_cast<uintptr_t>(&b);
        uintptr_t adrC = reinterpret_cast<uintptr_t>(&c);
	std::cout << "address a: " << adrA << "\naddress b: " << adrB << "\naddress c: " << adrC << "\n\n";
        adrA = adrA - adrA;
	adrB = adrB - adrA;
        adrC = adrC - adrA;
	std::cout << "result a: " << adrA << "\nresult b: " << adrB << "\nresult c: " << adrC << '\n';

	return 0;
}
