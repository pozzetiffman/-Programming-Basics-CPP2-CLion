#ifndef COUNTER_H
#define COUNTER_H

class Counter {
protected:
    int basicCislo;

public:
    explicit Counter(int basicCislo = 0);

    [[nodiscard]] int getCislo() const;
    void getCislo(int cs) ;
    int setplas();
    int setMinus();
};

#endif // COUNTER_H