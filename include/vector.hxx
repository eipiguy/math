///////////////////////////////////////////////////////////////////////////////
// Vector

// Generic Vector
template <typename T, int n>
struct Vector{
    T data[n]

    // Constructors

    // Component-Wise Operations
    Vector operator+(Vector left, Vector right);
    Vector operator-(Vector left, Vector right);
};

// Specializations for 2, 3, and 4 Dimensions
template <typename T>
struct Vector<T, 2> {
    union {
        T data[n];
        struct { T x, y; }
    };
};

template <typename T>
struct Vector<T, 3> {
    union {
        T data[n];
        struct { T x, y, z; }
        struct { T r, g, b; }
        Vector<T, 2> xy;
    };
};

template <typename T>
struct Vector<T, 4> {
    union {
        T data[n];
        struct { T x, y, z, w; }
        struct { T r, g, b, a; }
        Vector<T, 2> xy;
        Vector<T, 3> xyz;
        Vector<T, 3> rgb;
    };
};