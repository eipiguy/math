///////////////////////////////////////////////////////////////////////////////
// Matrix

// Generic Matrix
template <typename T, int rows, int cols>
struct Matrix{ T data[rows][cols]; };

// Square Specialization
template <typename T, int n>
struct Matrix<T, n, n>{ T data[n][n]; };