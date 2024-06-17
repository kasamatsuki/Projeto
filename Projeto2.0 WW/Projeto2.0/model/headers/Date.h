#ifndef MODEL_HEADERS_DATE_H
#define MODEL_HEADERS_DATE_H

class Date  {
private:
    int day;
    int month; //[1;12]
    int year;
    bool isLeapYear(int year);
    bool isValid(int day, int month, int year);
    void setDate(int day, int month, int year);
public:
    Date(); //Use only constructor
    std::string getDate();
    bool operator == (const Date& obj) const;
    bool operator > (const Date& obj)const;
    bool operator < (const Date& obj) const;

};

#endif //MODEL_HEADERS_DATE_H