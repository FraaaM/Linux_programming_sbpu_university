#include <iostream>


int main() {

   	#if defined(USE_GPU) && !defined(USE_FLOAT)
   	std::cout << "USE_GPU" << std::endl;
   
	#elif !defined(USE_GPU) && defined(USE_FLOAT)
	std::cout << "USE_FLOAT" << std::endl;
    	
	#elif defined(USE_GPU) && defined(USE_FLOAT)
    	std::cout << "USE_GPU USE_FLOAT" << std::endl;
    	
    	#elif !defined(USE_GPU) && !defined(USE_FLOAT)
	std::cout << "Not defined" << std::endl;
    	
    	#endif
}
