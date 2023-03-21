#include "Date.h"

Date::Date()
{
	struct tm *tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);

	day = tim->tm_mday;
	month = 1+ tim->tm_mon;
	year = 1900 + tim->tm_year;
}

Date::Date(const int d, const int m, const int y)
{
	day = d;
	month = m;
	year = y;
}

Date::Date(const Date & a)
{
	this->day = a.day;
	this->month = a.month;
	this->year = a.year;
}

Date & Date::operator=(const Date & a)
{
	this->day = a.day;
	this->month = a.month;
	this->year = a.year;

	return *this;
}

Date::~Date()
{
}

void Date::showDate() const
{
	cout << day / 10 << day % 10 << "-" << month / 10 << month % 10 << "-" << year << endl;
}

bool Date::isLeap() const
{
	if (year % 4 == 0) {
		if (year % 100 == 0 && year % 400 != 0) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int Date::MonD() const
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}
	else if (month == 2) {
		if (isLeap()) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 0;
	}
	return 0;
}

void Date::nextD()
{
	day++;
	if (day > MonD()) {
		day = 1;
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
}

void Date::prevDate()
{
	day--;
	if (day <= 0) {
		month--;
		if (month <= 0) {
			month = 12;
			year--;
		}
		day = MonD();
	}
}

void Date::setYear(const int y)
{
	year = y;
}

const int Date::getYear()
{
	return year;
}

void Date::setMonth(const int m)
{
	if (m > 12) {
		month = m % 12;
		year += m / 12;
	}
	else {
		month = m;
	}

}

const int Date::getMonth()
{
	return month;
}

void Date::setDay(const int d)
{
	if (d > MonD()) {
		day = d % 12;
		month += d / 12;
		if (month > 12) {
			month = month % 12;
			year += month / 12;
		}
	}
	else {
		day = d;
	}

}

const int Date::getDay()
{
	return day;
}

bool Date::valid() const
{
	if (day > 0 && day <= MonD() && month <= 12 && month > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator==(const Date & obj) const &
{
	if (this->day == obj.day && this->month == obj.month && this->year == obj.year) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator!=(const Date & obj) const &
{
	//if (this->day == obj.day && this->month == obj.month && this->year == obj.year) {
	//	return false;
	//}
	//else {
	//	return true;
	//}
	return !(*this == obj);
}

bool Date::operator>(const Date & obj) const &
{
	if (this->year > obj.year) {
		return true;
	}
	else {
		if (this->year == obj.year &&this->month > obj.month) {
			return true;
		}
		else {
			if (this->month==obj.month && this->year == obj.year && this->day > obj.day) {
				return true;
			}
			else {
				return false;
			}
		}

	}
}

bool Date::operator<(const Date & obj) const &
{
	if (!(*this > obj) && *this != obj) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator>=(const Date & obj) const &
{
	if (*this>obj || *this==obj) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator<=(const Date & obj) const &
{
	if (*this < obj || *this == obj) {
		return true;
	}
	else {
		return false;
	}
}

Date & Date::operator+=(int days)
{
	for (int i = 0; i < days; i++)
	{
		nextD();
	}
	return*this;
}

Date & Date::operator-=(int days)
{
	for (int i = 0; i < days; i++)
	{
		prevDate();
	}
	return*this;
}

Date & Date::operator+=(float months)
{
	this->month += months;
	if (month > 12) {
		year += month / 12;
		month = month % 12;
	}
	return*this;
}

Date & Date::operator-=(float months)
{
	this->month -= months;
	if (month < 1) {
		year -= (abs(month) / 12)+1;
		month = 12 + (this->month) % 12;
	}
	return*this;
}

Date & Date::operator+=(long years)
{
	year += years;
	if (day > MonD()) {
		day = MonD();
	}
	return *this;
}

Date & Date::operator-=(long years)
{
	year -= years;
	if (day > MonD()) {
		day = MonD();
	}
	return *this;
}

Date Date::operator+(int days) const &
{
	Date tmp(*this);
	for (int i = 0; i < days; i++)
	{
		tmp.nextD();
	}
	return tmp;

}

Date Date::operator-(int days) const &
{
	Date tmp(*this);
	for (int i = 0; i < days; i++)
	{
		tmp.prevDate();
	}
	return tmp;
}

Date Date::operator+(float months) const &
{
	Date tmp(*this);
	tmp.month += months;
	if (tmp.month > 12) {
		tmp.year += tmp.month / 12;
		tmp.month = tmp.month % 12;
	}
	return tmp;
}

Date Date::operator-(float months) const &
{
	Date tmp(*this);
	tmp.month -= months;
	if (tmp.month < 1) {
		tmp.year -= (abs(tmp.month) / 12) + 1;
		tmp.month = 12 + (tmp.month) % 12;
	}
	return tmp;
}

Date Date::operator+(long years) const &
{
	Date tmp(*this);
	tmp.year += years;
	if (tmp.day > tmp.MonD()) {
		tmp.day = tmp.MonD();
	}
	return tmp;
}

Date Date::operator-(long years) const &
{
	Date tmp(*this);
	tmp.year -= years;
	if (tmp.day > tmp.MonD()) {
		tmp.day = tmp.MonD();
	}
	return tmp;
}

int Date::operator-(const Date & obj) const &
{
	Date tmp(obj);
	int a = 0;
	if(*this>obj) {
		while (!(*this == tmp)) {
			tmp.nextD();
			a++;
		}
	}
	else if (*this < obj) {
		while (!(*this == tmp)) {
			tmp.prevDate();
			a++;
		}
	}
	return a;
}

Date & Date::operator--()
{
	this->prevDate();
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	this->prevDate();
	return tmp;
}

Date & Date::operator++()
{
	this->nextD();
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	this->nextD();
	return tmp;
}

istream & operator>>(istream & b, Date& a)
{
	do {
		cout << "dd mm yyyy: ";
		b >> a.day >> a.month >> a.year;
	} while (!a.valid());
	return b;
}

ostream & operator<<(ostream & b, Date a)
{
	b << a.day / 10 << a.day % 10 << "." << a.month / 10 << a.month % 10 << "." << a.year;
	return b;
}

Date operator+(int n, Date a)
{
	for (int i = 0; i < n; i++)
	{
		a.nextD();
	}
	return a;
}

Date operator-(int n, Date a)
{
	for (int i = 0; i < n; i++)
	{
		a.prevDate();
	}
	return a;
}
