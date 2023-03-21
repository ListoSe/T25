#include<iostream>
#include<string>
#include<map>
#include<vector>
#include"GAI.h"
#include"Date.h"
using namespace std;

int main() {
	GAI g;
	g.addViol("123", *new Violation());
	g.addViol("123", *new Violation("a",Date(),20, "a"));
	g.addViol("123", *new Violation("a", Date(), 14, "b"));
	g.addViol("321", *new Violation());
	g.addViol("321", *new Violation("b", Date(), 78, "a"));
	g.addViol("321", *new Violation("b", Date(), 87, "b"));
	g.show();
}


