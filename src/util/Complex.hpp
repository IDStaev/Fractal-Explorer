#pragma once
#include <ostream>

template<typename T>
class Complex {
public:
    Complex();
    Complex(const T& x, const T& y);

    const T& get_x() const;
    const T& get_y() const;
    void set_x(const T& x);
    void set_y(const T& y);

    Complex<T> square() const;

    // Returns copy of a temporary
    Complex<T> operator+(const Complex<T>& other) const;
    Complex<T> operator-(const Complex<T>& other) const;
    Complex<T> operator*(const Complex<T>& other) const;
private:
    // (const) T& would require callers object to outlive
    T x;
    T y;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Complex<T>& c) {
    os << '(' << c.get_x() << ',' << c.get_y() << ')';
    return os;
}

template<typename T>
Complex<T>::Complex()
    : Complex(T(), T()) {
}

template<typename T>
Complex<T>::Complex(const T& x, const T& y)
    : x(x), y(y) {
}

template<typename T>
const T& Complex<T>::get_x() const {
    return this->x;
}

template<typename T>
const T& Complex<T>::get_y() const {
    return this->y;
}

template<typename T>
void Complex<T>::set_x(const T& x) {
    this->x = x;
}

template<typename T>
void Complex<T>::set_y(const T& y) {
    this->y = y;
}

template<typename T>
Complex<T> Complex<T>::square() const {
    Complex<T> squared;
    squared.set_x(this->x * this->x - this->y * this->y);
    squared.set_y(2 * this->x * this->y);
    return squared;
}

template<typename T>
Complex<T> Complex<T>::operator+(const Complex<T>& other) const {
    T newX = this->get_x() + other.get_x();
    T newY = this->get_y() + other.get_y();
    return Complex<T>(newX, newY);
}

template<typename T>
Complex<T> Complex<T>::operator-(const Complex<T>& other) const {
    T newX = this->get_x() - other.get_x();
    T newY = this->get_y() - other.get_y();
    return Complex<T>(newX, newY);
}

template<typename T>
Complex<T> Complex<T>::operator*(const Complex<T>& other) const {
    T newX = this->get_x() * other.get_x() - this->get_y() - other.get_y();
    T newY = this->get_y() * other.get_x() + this->get_x() * other.get_y();

    return Complex<T>(newX, newY);
}
