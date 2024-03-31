//the use of functors compared to lambdas for working with a Pair struct and a vector of Pair objects.

#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::cout<<"functor compared to lambda\n";

	struct Pair{ //define a Pair struct with integer members x and y
	    int x;
	    int y;
	    struct ShowPair{/*inner struct 'ShowPair' to display Pair elements, in scope of Pair*/
		    void operator()(Pair p){
			    std::cout<<'{'<<p.x<<','<<p.y<<'}';
		    }
	    };

    };

    struct AddPair{ //define a functor 'AddPair' to calculate the sum of Pair elements (not in scope)
        int operator()(Pair p){
            return p.x+p.y;
        }
	};

	/*Define a functor 'AddAndShowPairST' to both show and add Pair elements*/
	struct AddAndShowPairST {
	        void operator()(Pair p){
	            Pair::ShowPair sP; //create an instance of ShowPair
	            sP(p); // ShowPair displays the Pair
	            AddPair aP;//create an instance of addPair
	            std::cout<<" = "<<aP(p)<<'\n'; //AddPair calculates and displays the sum
        }
	};
	
	std::vector<Pair> v{{1,2},{2,3},{3,4}}; //create a vector of Pair objects

	AddAndShowPairST aasP; // create an instance of AddAndShowPairST functor
	std::for_each(v.begin(),v.end(), aasP); //use for_each to apply AddAndShowPairST to each element in vector
	std::cout<<'\n';	

	/*Using a lambda for ShowPair*/
	auto ShowPair{[](Pair p){std::cout<<'{'<<p.x<<','<<p.y<<'}';}};

	/*Quasi-nested function, Using a lambda for AddAndShowPair, capturing ShowPair by reference*/
	auto AddAndShowPair{[&ShowPair](Pair p){ShowPair(p);std::cout<<" = "<<p.x+p.y<<'\n';}};
	
	std::cout<<'\n';
    std::for_each(v.begin(),v.end(),AddAndShowPair);
    
	// Using a lambda for AddAndShowPair in one lambda, directly displaying and adding
    auto AddAndShowPairInOne{[](Pair p){std::cout<<'{'<<p.x<<','<<p.y<<"} = "<< p.x+p.y<<'\n';}};//*void*/
	
	std::cout<<'\n';
    std::for_each(v.begin(),v.end(),AddAndShowPairInOne);
	
	return 0;
}
