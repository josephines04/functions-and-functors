/*Overloading the operator() and using structures and inner structures to display and add a pair of elements together*/

#include <iostream>
#include <vector>
#include<algorithm>

struct Pair{
	int x;
	int y;
	struct ShowPair{ /*struct displays the Pair elements*/
		void operator()(Pair p){ /*overloaded operator ()*/
			std::cout<<'{'<<p.x<<','<<p.y<<'}';
		}
	};

	struct AddPair{ /*calculates sum of Pair elements*/
		int operator()(Pair p){
			return p.x+p.y;
		}
	};
};

int main(){

	Pair::AddPair aP;
	std::cout<<aP({9,9})<<'\n'; /*Braces for overloading pair in argument, calls AddPair's operator() with Pair(9,9)*/
	std::vector<Pair> v{{1,2}, {3,4}, {5,6}}; /*creates a vector of Pair objects*/
	Pair::ShowPair sP;
	std::for_each(v.begin(), v.end(), sP); /*using the for_each algorithm to apply ShowPair's operator() to each element in the vector*/

	return 0;
}
