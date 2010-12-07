#ifndef VECTOR_H
#define VECTOR_H

typedef double Scalar;

class Vector 
{
public:
    Vector();
    Vector( double x, double y, double z );
    // DONE : Implement either [Set] method or overload '=' operator.
    void Set( double x, double y, double z );
    // 1. Assignment
    Vector& operator=(const Vector &rhs);
    // 2. Addition
    Vector operator+(const Vector &rhs);
    // 3. Substraction
    Vector operator-(const Vector &rhs);
    // 4. Multiplication by a scalar
    Vector operator*(const Scalar &rhs);
    // 5. Division by a scalar
    Vector operator/(const Scalar &rhs);
    // 6. Dot product
    Scalar operator|(const Vector &rhs);
    // 7. Cross product
    Vector operator^(const Vector &rhs);
    // 8. Magnitude
    Scalar operator~();
    // 9. Unit
    Vector operator!();
    ~Vector();

    double x;
    double y;
    double z;
};

#endif

