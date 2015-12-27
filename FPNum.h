//
// Created by 马浩程 on 15/12/24.
//

#ifndef ARCTAN_FPNUM_H
#define ARCTAN_FPNUM_H


#include <sys/_types/_int32_t.h>
#include <iostream>
#include <iomanip>

using namespace std;

class FPNum
{
    static int accuracy;
private:
    int32_t *intPart,*decPart;
    int intL,decL;
    bool sign;

    void normalize();
    void deleteZero();

//    FPNum(const FPNum &rhs);
//    FPNum &operator=(const FPNum &rhs);


public:
//    FPNum()
//    {
//        sign = true;
//        intL=1;
//        decL=accuracy/9+1;
//        intPart=new int32_t[intL+decL];
//        decPart=intPart+intL;
//        memset(intPart,0,sizeof(int32_t[intL+decL]));
//    }


    ~FPNum()
    {
        if(intPart)
            delete[] intPart;
    }


    FPNum(char *s);
    FPNum(const int intL,const int decL);
    FPNum(const FPNum &ins);
    FPNum & operator =(const FPNum &ins);
    FPNum operator +(const FPNum &ins);
    FPNum operator -(const FPNum &ins);
    FPNum operator *(const FPNum &ins);
    FPNum operator /(const FPNum &ins);
    FPNum operator /(const int32_t divisor);
    FPNum operator ^(const FPNum &ins);

//    bool operator>(const FPNum & T)const;   //大数和另一个大数的大小比较
    bool operator>(const int & t)const;      //大数和一个int类型的变量的大小比较


    friend ostream& operator<<(ostream&,const FPNum&);
//    friend istream& operator>>(istream&,FPNum&);


};

ostream &operator<<(ostream &out, const FPNum &b);

#endif //ARCTAN_FPNUM_H
