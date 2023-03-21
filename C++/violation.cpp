#include "violation.h"
#include"Date.h"
Violation::Violation()
{
   driver = "No name";
   date = Date();
   fine = 0;
   info = "Empty";
}

Violation::Violation(string driver, Date date, float fine, string info)
{
    this->driver = driver;
    this->date = date;
    this->fine = fine;
    this->info = info;
}


void Violation::setDriver(string driver)
{
    this->driver = driver;
}

void Violation::setDate(Date date)
{
    this->date = date;
}

void Violation::setFine(float fine)
{
     this->fine = fine;
}

void Violation::setInfo(string info)
{
     this->info = info;
}

string Violation::getDriver() const
{
    return driver;
}

Date Violation::getDate() const
{
    return date;
}

float Violation::getFine() const
{
    return fine;
}

string Violation::getInfo() const
{
    return info;
}

void Violation::show() const
{
    cout << "Driver " << driver << " violated: " << info << " at ";
    date.showDate();
    cout << "They owe " << fine << "UAH \n";
}

