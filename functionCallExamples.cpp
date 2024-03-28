/*Using different function calls via various parameter passing methods.*/
/*etc. by value, by reference, by pointer*/

#include<iostream>
#include<vector>

template<typename T>
	void myFkt(T a){ //generic function
		std::cout<<"hello "<<a<<'\n';
	}

/*fktCallByValue takes an unsigned int 'a' by value, by creating a copy of a and working with that copy.*/
/*this is discussed in more detail in callByValue.cpp*/
void fktCallByValue(unsigned int a){ 
	a+=10;
	std::cout<<"a in fktCallByValue "<<a<<'\n';
}

/*fktCallByRef takes an unsigned int 'a' by reference.*/
/*this means it directly modifies the original 'a' in the calling function.*/
void fktCallByRef(unsigned int& a){
	a+=10;
	std::cout<<"a in fktCallByRef "<<a<<'\n';
}

/*fktCallByPTR takes a pointer to an unsigned integer 'a'*/
/*means that it modifies the value at the memory location pointed to by 'a'*/
void fktCallByPTR(unsigned int* a){
	(*a)+=10;
	std::cout<<"a in fktCallByPTR "<<*a<<" Address of a "<<a<<'\n';
}


int main(){

	auto a{0u}; //declares and initialises an unsigned int 'a' with value 0
	
	fktCallByValue(a); //calls function with 'a' passed by value.
	std::cout<<"a in main "<<a<<'\n';
	
	fktCallByRef(a);//calls function with 'a' passed by reference.
	std::cout<<"a in main return "<<a<<'\n';
	
	auto aPTR{&a}; //Create a pointer 'aPTR' pointing to the address of 'a.
	fktCallByPTR(aPTR);//calls function with 'aPTR' passed as a pointer.
	std::cout<<"a in main return "<<a<<'\n';
	
	auto bPTR{new int(7)}; //creates pointer 'bPTR' and allocates memory for an int with  value 7.
	std::cout<<*bPTR<<'\n';
	delete bPTR; //frees the memory allocated to stop memory leak
	
	void(*handle)(unsigned int){fktCallByValue}; //creates a function pointer 'handle' that points to fktCallByValue
	handle(70);
	
	myFkt(9);
	myFkt(A);
	myFkt(9.0f);
	myFkt(9.9);
	myFkt("halo ");

	return 0;
}

