/*the use of functors (function objects) and templates in C++*/

#include<iostream>
#include<vector>
#include<algorithm>

/*define a functor 'Add' to add two integers together*/
struct Add{ /*global*/
    int operator()(int a,int b){
        return a+b;
    }
};

/*defines a template functor 'Sub' to subtract any type of a,b*/
template<typename T>/*global better as template, reusable for other types*/
struct Sub{
    T operator()(T a,T b){
        return a-b;
    }
};

/*defines a template functor 'Mul' to multiply any type of a,b*/
template<typename T>
struct Mul{
    T operator()(T a,T b){
        return a*b;
    }
};

int main(){
    std::cout<<"The functor is the solution if you want a functionality in an other function close to your problem.\n";
    std::cout<<"It is an alternative to using a lambda function\n";

	Add sAdd;
	std::cout<<sAdd(9,7)<<'\n';
	
	/*Create a Sub functor for integers. */
	Sub<int> sSub;/*<int> needed otherwise type deduction will fail*/
	std::cout<<sSub(9,7)<<'\n';
	
	struct Pair{ // Define a pair struct with integers x and y
	    int x;
	    int y;
	    struct ShowPair{ /*struct displays the Pair elements*/
		    void operator()(Pair p){
			    std::cout<<'{'<<p.x<<','<<p.y<<'}';
		    }
	    };

    };

    struct AddPair{/*struct adds the Pair elements, not in scope of Pair*/
        int operator()(Pair p){
            return p.x+p.y;
        }
	};

	std::vector<Pair> v{{1,2},{2,3},{3,4}};/*creates a vector of Pair objects*/
	AddPair aP; /*not in scope*/
	std::cout<<aP({9,9})<<'\n';/*Braces for overloading pair in argument, calls AddPair's operator() with Pair(9,9)*/
	Pair::ShowPair sP;/*in scope of Pair struct*/
	std::for_each(v.begin(),v.end(),sP); /*using the for_each algorithm to apply ShowPair's operator() to each element in the vector*/

	return 0;
}
