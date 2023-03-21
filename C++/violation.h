#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

class Violation
{
protected:
    string driver;
    Date date;
    float fine;
    string info;

public:
    Violation();
    Violation(string driver,  Date date,  float fine, string info);

    void setDriver(string driver);
    void setDate(Date date);
    void setFine(float fine);
    void setInfo(string info);

    string getDriver()const;
    Date getDate()const;
    float getFine()const;
    string getInfo()const;

    void show() const;
};

