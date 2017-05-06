// Copyright Kildishev Maxim 2017

#include <include/dichotomy.h>
#include <cmath>
#include <climits>
#include <iostream>
//За унимодальную функцию примем y = afactor*(x+bfactor)^2 + cfactor
double Dichotomy::findMin(int afactor, int bfactor, int cfactor,
     double leftBorder, double rightBorder, double eps) {
    if (rightBorder < leftBorder)
        throw "Incorrect borders";
    if (std::abs(rightBorder-leftBorder) < 0.0001)
        throw "Too close values";
    if ((afactor == 0) && (cfactor == 0))
        throw "Function is ZERO";
    if (eps <=0)
        throw "Eps must be higher then zero";
    double c = (leftBorder + rightBorder)/2;
    double funcValueC = afactor*(c+bfactor)*(c+bfactor) + cfactor;
    while (rightBorder - leftBorder > eps) {
        double x = (leftBorder + c)/2;
        double funcValueX = afactor*(x+bfactor)*(x+bfactor) + cfactor;
        double y = (c + rightBorder)/2;
        double funcValueY = afactor*(y+bfactor)*(y+bfactor) + cfactor;
        if ((funcValueX < funcValueY) && (funcValueX < funcValueC)) {
                rightBorder = c;
                c = x;
                funcValueC = funcValueX;
            } else if ( (funcValueC < funcValueX)
            && (funcValueC < funcValueY) ) {
                leftBorder = x;
                rightBorder = y;
            } else {
                leftBorder = c;
                c = y;
                funcValueC = funcValueY;
            }
        //Поскольку метод дихотомии должен вернуть отрезок, на котором
        //должен находиться минимум, возьмём за оценку решения его середину
    }
    return (leftBorder + rightBorder) / 2;
}
