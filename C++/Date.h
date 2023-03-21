#pragma once
#include<iostream>
#include<ctime>

using namespace std;
class Date
{
	int day;
	int month;
	int year;

public:
	Date();
	Date(const int d, const int m, const int y);
	Date(const Date& a);
	Date& operator = (const Date& a);
	~Date();

	void showDate() const;

	bool isLeap() const;
	int MonD() const;
	void nextD();
	void prevDate();

	void setYear(const int y);
	const int getYear();
	void setMonth(const int m);
	const int getMonth();
	void setDay(const int d);
	const int getDay();

	bool valid()const;

	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;

	Date& operator += (int days); 
	Date& operator -= (int days); 
	Date& operator += (float months); 
	Date& operator -= (float months); 
	Date& operator += (long years); 
	Date& operator -= (long years); 

	Date operator + (int days)const&;
	Date operator - (int days)const&;
	Date operator + (float months)const&;
	Date operator - (float months)const&; 
	Date operator + (long years)const&;
	Date operator - (long years)const&; 

	int operator - (const Date& obj)const&;

	Date& operator -- ();
	Date operator -- (int);
	Date& operator ++ ();
	Date operator ++ (int);

	friend istream& operator>>(istream& b, Date& a);
	friend ostream& operator<<(ostream& b, Date a);

	friend Date operator + (int n, Date a);
	friend Date operator - (int n, Date a);

};

