#include "counter.h"

Counter::Counter(int basicCislo) : basicCislo(basicCislo) {}


int Counter::getCislo() const {return basicCislo;}
void Counter::getCislo(int cs) {this->basicCislo = cs;}

int Counter::setplas ()  {
    return basicCislo++;
}
int Counter::setMinus () {
    return basicCislo--;
}