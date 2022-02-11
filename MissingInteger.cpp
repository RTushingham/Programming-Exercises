
#include <map>
#include <vector>

int MissingInteger(vector<int> &A){
	
	std::map<int, integer> observedvalues;
	
	for(unsigned indexofA=0; indexofA<A.size()); indexofA++){
		observedvalues.insert({A[indexofA], 1});
	}
	
	unsigned returnvalue;
	for(returnvalue = 1; observedvalues.contains(returnvalue); returnedvalue++);
	return returnvalue;
	
}

