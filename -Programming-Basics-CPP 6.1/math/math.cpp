#include <complex>

double add (double a = 0, double b = 0) {
    return a + b;
}
double sub(double a, double b) {
    return a - b;
}
double mult(double a, double b) {
return a * b;
}
double dev(double a, double b) {
return a / b;
}
double expon(double a, double b) {
  double result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}




