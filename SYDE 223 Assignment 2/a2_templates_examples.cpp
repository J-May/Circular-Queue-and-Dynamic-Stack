#include <iostream>

// Examples of function template

template<class T>
void swapValues(T& var1, T& var2);

template<class T1, class T2>
void swapValues2(T1& var1, T2& var2);

template<class T>
void swapValues(T& var1, T& var2) {
    T temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

template<> // explicit specialization; needs to be defined before the first usage (i.e., before main())
void swapValues(bool& var1, bool& var2) {
    var1 = false; // randomly assigned values to differentiate from the regular swapValues
    var2 = false;
}

template<class T1, class T2>
void swapValues2(T1& var1, T2& var2) {
    T1 temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

// Examples of class template


template<class T>
class Pair {
public:
    Pair(T firstVal, T secondVal);
    void setFirst(T newVal);
    void setSecond(T newVal);
    T getFirst() const;
    T getSecond() const;
private:
    T first;
    T second;
};

template<class T>
Pair<T>::Pair(T firstVal, T secondVal) : first(firstVal), second(secondVal) 
{}

template<class T>
void Pair<T>::setFirst(T newVal) {
    first = newVal;
}

template<class T>
T Pair<T>::getFirst() const {
    return first;
}

template<class T>
void Pair<T>::setSecond(T newVal) {
    second = newVal;
}

template<class T>
T Pair<T>::getSecond() const {
    return second;
}

int templateMain() {
    bool b1 = true, b2 = true;
    char c1 = 'b', c2 = 'a';
    double d1 = 5.0, d2 = 4.0;
    int i1 = 11, i2 = 7;
    int a1[10], a2[10];

    swapValues(b1, b2);
    std::cout << b1 << " and " << b2 << std::endl;

    swapValues2(c1, c2);
    std::cout << c1 << " and " << c2 << std::endl;

    swapValues(d1, d2);
    std::cout << d1 << " and " << d2 << std::endl;

    swapValues(i1, i2);
    std::cout << i1 << " and " << i2 << std::endl;

    Pair<int> pair(5,6);
    std::cout << pair.getFirst() << " and " << pair.getSecond() << std::endl;

    Pair<double> pair2(14.5,16.7);
    std::cout << pair2.getFirst() << " and " << pair2.getSecond() << std::endl;

    return 0;
}

