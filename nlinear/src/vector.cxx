#include "vector.hxx"
#include <cmath>

///////////////////////////////////////////////////////////////////////////////
// Generic Vector

//=============================================================================
// Constructors

template <typename T, size_t n>
constexpr Vector<T,n> :: Vector (const T &fill) {
    for( T d : data ){
        d = fill;
    }
    return;
}

template <typename T, size_t n>
constexpr Vector<T,n> :: Vector (const std::initializer_list<T> &list)
    : data(list) {}

//=============================================================================
// Assignment & Access

template <typename T, size_t n>
void Vector<T,n> :: operator= (const Vector<T,n> &right){
    data = right.data;
}

template <typename T, size_t n>
T Vector<T,n> :: operator[] (size_t i){
    return data[i];
}

//=============================================================================
// Component-Wise

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator+ (const Vector<T,n> &right){
    Vector<T,n> out;
    for(size_t i=0; i<n; ++i){
        out.data[i] = data[i] + right.data[i];
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator- (const Vector<T,n> &right){
    Vector<T,n> out;
    for(size_t i=0; i<n; ++i){
        out.data[i] = data[i] - right.data[i];
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator* (const Vector<T,n> &right){
    Vector<T,n> out;
    for(size_t i=0; i<n; ++i){
        out.data[i] = data[i] * right.data[i];
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator/ (const Vector<T,n> &right){
    Vector<T,n> out;
    for(size_t i=0; i<n; ++i){
        out.data[i] = data[i] / right.data[i];
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator% (const Vector<T,n> &right){
    Vector<T,n> out;
    for(size_t i=0; i<n; ++i){
        out.data[i] = data[i] % right.data[i];
    }
    return out;
}

//-----------------------------------------------------------------------------

template <typename T, size_t n>
void Vector<T,n> :: operator+= (const Vector<T,n> &right){
    for(size_t i=0; i<n; ++i){
        data[i] += right.data[i];
    }
    return;
}

template <typename T, size_t n>
void Vector<T,n> :: operator-= (const Vector<T,n> &right){
    for(size_t i=0; i<n; ++i){
        data[i] -= right.data[i];
    }
    return;
}

template <typename T, size_t n>
void Vector<T,n> :: operator*= (const Vector<T,n> &right){
    for(size_t i=0; i<n; ++i){
        data[i] *= right.data[i];
    }
    return;
}

template <typename T, size_t n>
void Vector<T,n> :: operator/= (const Vector<T,n> &right){
    for(size_t i=0; i<n; ++i){
        data[i] /= right.data[i];
    }
    return;
}

template <typename T, size_t n>
void Vector<T,n> :: operator%= (const Vector<T,n> &right){
    for(size_t i=0; i<n; ++i){
        data[i] %= right.data[i];
    }
    return;
}

//-----------------------------------------------------------------------------

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: abs () {
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i; ){
        out.data[i] = abs( d[i] );
    }
}

//=============================================================================
// Scalar From Right

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator+ (const T &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = data[i] + right;
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator- (const T &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = data[i] - right;
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator* (const T &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = data[i] * right;
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator/ (const T &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = data[i] / right;
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> Vector<T,n> :: operator% (const T &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = data[i] % right;
    }
    return out;
}

//=============================================================================
// Comparison

template <typename T, size_t n>
Vector<bool,n> Vector<T,n> :: operator== (const Vector<T,n> &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = ( data[i] == right.data[i] );
    }
    return out;
}

template <typename T, size_t n>
Vector<bool,n> Vector<T,n> :: operator!= (const Vector<T,n> &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = ( data[i] != right.data[i] );
    }
    return out;
}

template <typename T, size_t n>
Vector<bool,n> Vector<T,n> :: operator< (const Vector<T,n> &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = ( data[i] < right.data[i] );
    }
    return out;
}

template <typename T, size_t n>
Vector<bool,n> Vector<T,n> :: operator<= (const Vector<T,n> &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = ( data[i] <= right.data[i] );
    }
    return out;
}

template <typename T, size_t n>
Vector<bool,n> Vector<T,n> :: operator> (const Vector<T,n> &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = ( data[i] > right.data[i] );
    }
    return out;
}

template <typename T, size_t n>
Vector<bool,n> Vector<T,n> :: operator>= (const Vector<T,n> &right){
    Vector<bool,n> out;
    for( size_t i=0; i<n; ++i ){
        out.data = ( data[i] >= right.data[i] );
    }
    return out;
}

//=============================================================================
// Utility

template <typename T, size_t n>
auto Vector<T,n> :: length (){
    return sqrt( dot(this,this) );
}

template <typename T, size_t n>
void Vector<T,n> :: normalize (){
    auto l = this.length();
    for( T d : data ){
        d /= l;
    }
    return;
}

//-----------------------------------------------------------------------------

template <typename T, size_t n>
T Vector<T,n> :: sum(){
    T total = 0;
    for( T d : data ){
        total += d;
    }
    return total;
}

template <typename T, size_t n>
T Vector<T,n> :: product(){
    T total = 1;
    for( T d : data ){
        total *= d;
    }
    return total;
}

template <typename T, size_t n>
T Vector<T,n> :: min(size_t *minID){
    if(minID){
        *minID = 0;
    }
    T m = data[0];
    for( size_t i=0; i<n; ++i ){
        if( data[i] < m ){
            m = data[i];
            if(minID){
                *minID = i;
            }
        }
    }
    return m;
}

template <typename T, size_t n>
T Vector<T,n> :: max(size_t *maxID){
    if(maxID){
        *maxID = 0;
    }
    T m = data[0];
    for( size_t i=0; i<n; ++i ){
        if( d > m ){
            m = d;
            if(maxID){
                *maxID = i;
            }
        }
    }
    return m;
}

//-----------------------------------------------------------------------------

template <typename T, size_t n>
bool Vector<T,n> :: all(){
    for( T d : data ){
        if( !d ){
            return false;
        }
    }
    return true;
}

template <typename T, size_t n>
bool Vector<T,n> :: any(){
    for( T d : data ){
        if( d ){
            return true;
        }
    }
    return false;
}

//=============================================================================
// Scalar Operators from Left

template <typename T, size_t n>
Vector<T,n> operator+ (const T &left, const Vector<T,n> &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = left + right[i];
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> operator- (const T &left, const Vector<T,n> &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = left - right[i];
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> operator* (const T &left, const Vector<T,n> &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = left * right[i];
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> operator/ (const T &left, const Vector<T,n> &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = left / right[i];
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> operator% (const T &left, const Vector<T,n> &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = left % right[i];
    }
    return out;
}

//=============================================================================
//Component-Wise Non-Operators

template <typename T, size_t n>
Vector<T,n> min(const Vector<T,n> &left, const Vector<T,n> &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = std::min(left[i], right[i]);
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> min(const T &left, const Vector<T,n> &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = std::min(left, right[i]);
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> min(const Vector<T,n> &left, const T &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = std::min(left[i], right);
    }
    return out;
}

//-----------------------------------------------------------------------------

template <typename T, size_t n>
Vector<T,n> max(const Vector<T,n> &left, const Vector<T,n> &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = std::max(left[i], right[i]);
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> max(const T &left, const Vector<T,n> &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = std::max(left, right[i]);
    }
    return out;
}

template <typename T, size_t n>
Vector<T,n> max(const Vector<T,n> &left, const T &right){
    Vector<T,n> out;
    for( size_t i=0; i<n; ++i ){
        out[i] = std::max(left[i], right);
    }
    return out;
}

//-----------------------------------------------------------------------------
/*
template <typename T, size_t n>
Vector<T,n> clamp(const Vector<T,n> &v, const Vector<T,n> &min, const Vector<T,n> &max);

template <typename T, size_t n>
Vector<T,n> clamp(const Vector<T,n> &v, const T &min, const Vector<T,n> &max);

template <typename T, size_t n>
Vector<T,n> clamp(const Vector<T,n> &v, const Vector<T,n> &min, const T &max);

template <typename T, size_t n>
Vector<T,n> clamp(const Vector<T,n> &v, const T &min, const T &max);
*/
//=============================================================================
// Vector-Based Free Functions

template <typename T, size_t n>
T dot (const Vector<T,n> &left, const Vector<T,n> &right){
    T sum = 0;
    for( size_t i=0; i<n; ++i ){
        sum += left[i]*right[i];
    }
    return sum;
}

///////////////////////////////////////////////////////////////////////////////
// Specializations for 2, 3, and 4 Dimensions

//=============================================================================
// 2 Dimensions

//=============================================================================
// 3 Dimensions

template <typename T>
Vector<T,3> cross (const Vector<T,3> left, const Vector<T,3> right){
    Vector<T,3> out;
    out.x = (left.y * right.z) - (left.z * right.y);
    out.x = (left.z * right.x) - (left.x * right.z);
    out.x = (left.x * right.y) - (left.y * right.x);
    return out;
}

//=============================================================================
// 4 Dimensions