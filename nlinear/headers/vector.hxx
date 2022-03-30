#include <initializer_list>

///////////////////////////////////////////////////////////////////////////////
// Vector

// Generic Vector
template <typename T, int n>
struct Vector {
    T data[n];

    // Constructors
    constexpr explicit Vector<T, n> (const T fill);
    constexpr explicit Vector<T, n> (const std::initializer_list<T> list);

    // Component-Wise Operations
    Vector<T,n> operator+ (const Vector<T,n> right);
    Vector<T,n> operator- (const Vector<T,n> right);

    // Vector Specific Operations
    constexpr T length();
    constexpr void normalize();
};

//=============================================================================
// Vector-Based Functions

template <typename T, int n>
T dot(const Vector<T, n> left, const Vector<T, n> right);

template <typename T, int n>
Vector<T, n> cross(const Vector<T, n> left, const Vector<T, n> right);

///////////////////////////////////////////////////////////////////////////////
// Specializations for 2, 3, and 4 Dimensions

template <typename T>
struct Vector<T, 2> {
    union {
        T data[2];
        struct { T x, y; };
    };
};

template <typename T>
struct Vector<T, 3> {
    union {
        T data[3];
        struct { T x, y, z; };
        struct { T r, g, b; };
        Vector<T, 2> xy;
    };
};

template <typename T>
struct Vector<T, 4> {
    union {
        T data[4];
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        Vector<T, 2> xy;
        Vector<T, 3> xyz;
        Vector<T, 3> rgb;
    };
};

///////////////////////////////////////////////////////////////////////////////
// Typedefs for Ease of Use

typedef Vector<float, 2> float2;
typedef Vector<float, 3> float3;
typedef Vector<float, 4> float4;

typedef Vector<double, 2> double2;
typedef Vector<double, 3> double3;
typedef Vector<double, 4> double4;