#include <string>
#include <iostream>
#include <fstream>

int main(){
	std::string val1;
	std::string val2;
	std::ifstream f("hack_test.txt");
	
	std::getline(f,val1);
	std::getline(f,val2);

	std::cout << "C++:  "<< val1 << std::endl;
	std::cout << "C++:  "<< val2 << std::endl;
	

return 1;
}

