 #include <iostream>
using namespace std;

    struct Date
    {
        unsigned int day;
        unsigned int month;
        unsigned int year;
    };

int sn(int m, int y)
{
    int songay[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (y%4==0 && y%100!=0 || y%400==0)
    {
        songay[2]=29;
    }
    return songay[m];
}

Date &operator++(Date &tmp){
    if (tmp.day<sn(tmp.month,tmp.year))
    {
        ++tmp.day;
    }else {
        tmp.day = 1;
        if (++tmp.month>12)
        {
            tmp.month = 1; tmp.year++;
        }
    }
    
return tmp;
}

Date &operator++(Date &tmp,int){
    Date old = tmp; 
    if (tmp.day<sn(tmp.month,tmp.year))
    {
        ++tmp.day;
    }else {
        tmp.day = 1;
        if (++tmp.month>12)
        {
            tmp.month = 1; tmp.year++;
        }
    }    
    return old;    
}

Date &operator--(Date &tmp){
    if (--tmp.day<1)
    {
        if(--tmp.month<1) tmp.month = 12; tmp.day = sn(tmp.month,tmp.year);
    }
    return tmp;
}

Date &operator--(Date &tmp,int){
    Date old = tmp; 
     if (--tmp.day<1)
    {
        if(--tmp.month<1) tmp.month = 12;tmp.day = sn(tmp.month,tmp.year);
    }   
    return old;    
}

istream &operator>> (istream &in, Date &tmp){
    in >> tmp.day >> tmp.month >> tmp.year;
    return in;
}


ostream &operator<< (ostream &out, Date &tmp){
    out << tmp.day << "/" << tmp.month << "/" << tmp.year;
    return out;
}

int main()
{
    Date D1,D2,D3;
    cin >> D1;
    cout << D1<< endl; // không thể thêm dấu ++ vào sau hoặc trước các biến
    --D1;
    cout << D1;
return 0;
}