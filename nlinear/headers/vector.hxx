#include "nlinear_export.h"
#include <initializer_list>

using std::size_t;

///////////////////////////////////////////////////////////////////////////////
// Vector

// Generic Vector
template <typename T, size_t n>
struct NLINEAR_EXPORT Vector {
    T data[n];

    // Constructors
    constexpr explicit Vector (const T &fill);
    constexpr explicit Vector (const std::initializer_list<T> &list);

    // Assignment & Access
    void operator= (const Vector<T,n> &right);
    T operator[] (const size_t i);

    // Component-Wise
    Vector<T,n> operator+ (const Vector<T,n> &right);
    Vector<T,n> operator- (const Vector<T,n> &right);
    Vector<T,n> operator* (const Vector<T,n> &right);
    Vector<T,n> operator/ (const Vector<T,n> &right);
    Vector<T,n> operator% (const Vector<T,n> &right);

    void operator+= (const Vector<T,n> &right);
    void operator-= (const Vector<T,n> &right);
    void operator*= (const Vector<T,n> &right);
    void operator/= (const Vector<T,n> &right);
    void operator%= (const Vector<T,n> &right);

    Vector<T,n> abs();

    // Scalar From Right
    Vector<T,n> operator+ (const T &right);
    Vector<T,n> operator- (const T &right);
    Vector<T,n> operator* (const T &right);
    Vector<T,n> operator/ (const T &right);
    Vector<T,n> operator% (const T &right);

    // Comparison
    Vector<bool,n> operator== (const Vector<T,n> &right);
    Vector<bool,n> operator!= (const Vector<T,n> &right);
    Vector<bool,n> operator< (const Vector<T,n> &right);
    Vector<bool,n> operator<= (const Vector<T,n> &right);
    Vector<bool,n> operator> (const Vector<T,n> &right);
    Vector<bool,n> operator>= (const Vector<T,n> &right);

    // Utility
    auto length ();
    void normalize ();

    T sum();
    T product();

    T min(size_t *minID=nullptr);
    T max(size_t *maxID=nullptr);

    bool all();
    bool any();
};

//=============================================================================
// Scalar Operators from Left

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> operator+ (const T &left, const Vector<T,n> &right);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> operator- (const T &left, const Vector<T,n> &right);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> operator* (const T &left, const Vector<T,n> &right);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> operator/ (const T &left, const Vector<T,n> &right);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> operator% (const T &left, const Vector<T,n> &right);

//=============================================================================
//Component-Wise Non-Operators

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> min(const Vector<T,n> &left, const Vector<T,n> &right);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> min(const T &left, const Vector<T,n> &right);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> min(const Vector<T,n> &left, const T &right);

//-----------------------------------------------------------------------------

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> max(const Vector<T,n> &left, const Vector<T,n> &right);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> max(const T &left, const Vector<T,n> &right);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> max(const Vector<T,n> &left, const T &right);

//-----------------------------------------------------------------------------

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> clamp(const Vector<T,n> &v, const Vector<T,n> &min, const Vector<T,n> &max);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> clamp(const Vector<T,n> &v, const T &min, const Vector<T,n> &max);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> clamp(const Vector<T,n> &v, const Vector<T,n> &min, const T &max);

template <typename T, size_t n>
NLINEAR_EXPORT Vector<T,n> clamp(const Vector<T,n> &v, const T &min, const T &max);

//=============================================================================
// Vector-Based Free Functions

template <typename T, size_t n>
NLINEAR_EXPORT T dot(const Vector<T,n> &left, const Vector<T,n> &right);

///////////////////////////////////////////////////////////////////////////////
// Specializations for 2, 3, and 4 Dimensions

//=============================================================================
// 2 Dimensions

template <typename T>
struct NLINEAR_EXPORT Vector<T,2> {
    union {
        T data[2];
        struct { T x, y; };
    };
};

//=============================================================================
// 3 Dimensions

template <typename T>
struct NLINEAR_EXPORT Vector<T,3> {
    union {
        T data[3];
        struct { T x, y, z; };
        struct { T r, g, b; };
        Vector<T,2> xy;
    };
};

template <typename T>
NLINEAR_EXPORT Vector<T,3> cross (const Vector<T,3> left, const Vector<T,3> right);

//=============================================================================
// 4 Dimensions

template <typename T>
struct NLINEAR_EXPORT Vector<T,4> {
    union {
        T data[4];
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        Vector<T,2> xy;
        Vector<T,3> xyz;
        Vector<T,3> rgb;
    };
};