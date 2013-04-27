#include <cstdio>
#include <cstring>

#ifndef __SWEETHEADER
#define __SWEETHEADER

#include <iostream>
#include <cmath>
#define debug(x) std::cerr << #x << " = " << x << "\n"
const double eps = 1e-8;
inline bool eq(double a,double b) {return a - b < eps && b - a < eps;}
inline bool ls(double a,double b) {return a + eps < b;}
inline bool le(double a,double b) {return a - eps < b;}
inline bool gr(double a,double b) {return a - eps > b;}
inline bool ge(double a,double b) {return a + eps > b;}
#endif

int main() {
    return 0;
}
