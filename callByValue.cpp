/*a call by value example -  passing a variable "by value" to a function"

#include<iostream>
#include<vector>

void fktCallByValue(unsigned int a){ //function takes an unsigned integer 'a' by value - so it creates a copy of a and works with that copy.
	a+=10; //adds 10 to the value of a
	std::cout<<"a in fktCallByValue "<<a<<'\n'; //prints the modified value of 'a'
}

int main(){
	auto a{0u}; //declare and initialize an unsigned integer variable 'a' with value 0.
	fktCallByValue(a); //call the function fktCallByValue with 'a' as the argument.
	std::cout<<"a in main "<<a<<'\n';
	return 0;
}
