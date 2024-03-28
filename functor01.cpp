//Example of a functor (function object) vs a regular function

#include <iostream>

struct Add{
	int operator() (int a,int b){ //overload the function call operator '()' for the struct.
	return a+b;
	}
};

int add(int a,int b){ //simple regular function
	return a+b;
}

int main(){
	std::cout<<add(8,8)<<'\n'; //calls the simple function, adds 8+8
	Add sAdd; //creates an instance of the Add structure
	/*calls the overloaded '()' operator of the 'Add' structure with the arguments (a,b)*/
	std::cout<<sAdd(7,4)<<'\n';
	std::cout<<sAdd(1,4)<<'\n';
	return 0;
}
