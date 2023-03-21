#include "GAI.h"

void GAI::show() 
{
	for (auto y : db) {
		cout << y.first << " - \n";
		showAt(y.first);
	}
}

void GAI::addViol(string s, Violation& v)
{
	db[s].push_back(v);
}

void GAI::showAt(string i) 
{
	for (auto x : db[i]) {
		x.show();
	}
}
