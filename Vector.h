#include <iostream>

using namespace std;

/*
 * http://en.wikipedia.org/wiki/Euclidean_vector
 */
template<class T, unsigned int N>
class Vector {
private:
	//coordinate system, we wait with this as it might not be what we want for
	//this class, though it's mathematical correct
public:
	/* make it an aggregate for convenience of construction */
	T data[N];
	
	/* arithmetic */
	Vector<T, N> operator+(Vector<T, N>& other);
	Vector<T, N> operator+=(Vector<T, N>& other);
	
	Vector<T, N> operator-(Vector<T, N>& other);
	Vector<T, N> operator-=(Vector<T, N>& other);
	
	Vector<T, N> operator*(T scalar);
	Vector<T, N> operator*=(T scalar);
	
	Vector<T, N> operator/(T scalar);
	Vector<T, N> operator/=(T scalar);
	
	T dot(Vector<T, N>& other);
	Vector<T, 3> cross(Vector<T, 3>& other); //not yet implemented
	Vector<T, 7> cross(Vector<T, 7>& other); //not yet implemented
	Vector<T, N> normalize();
	double magnitude();
	
	/* data access */
	T& operator[](unsigned int index);
};

template<class T, unsigned int N>
ostream& operator<<(ostream& os, const Vector<T, N>& vector) {
	os << "[ " << vector.data[0];
	for(int i=1; i<N; ++i) {
		os << " , " << vector.data[i];
	}
	os << " ]";
	return os;
}

template<class T, unsigned int N>
istream& operator>>(istream& is, const Vector<T, N>& vector) {
	is.ignore(2);
	is >> vector.data[0];
	for(int i=1; i<N; ++i) {
		is.ignore(3);
		is >> vector.data[i];
	}
	is.ignore(2);
}

template<class T, unsigned int N>
T& Vector<T, N>::operator[](unsigned int index) {
	return *(data+index);
}

template<class T, unsigned int N>
Vector<T, N> Vector<T, N>::operator+(Vector<T, N>& other) {
	Vector<T, N> result;
	for(int i=0; i<N; ++i) result[i] = (*this)[i]+other[i];
	return result;
}

template<class T, unsigned int N>
Vector<T, N> Vector<T, N>::operator+=(Vector<T, N>& other) {
	(*this) = (*this)+other;
	return (*this);
}

template<class T, unsigned int N>
Vector<T, N> Vector<T, N>::operator-(Vector<T, N>& other) {
	Vector<T, N> result;
	for(int i=0; i<N; ++i) result[i] = (*this)[i]-other[i];
	return result;
}

template<class T, unsigned int N>
Vector<T, N> Vector<T, N>::operator-=(Vector<T, N>& other) {
	(*this) = (*this)-other;
	return (*this);
}

template<class T, unsigned int N>
Vector<T, N> Vector<T, N>::operator*(T scalar) {
	Vector<T, N> result;
	for(int i=0; i<N; ++i) result[i] = (*this)[i]*scalar;
	return result;
}

template<class T, unsigned int N>
Vector<T, N> Vector<T, N>::operator*=(T scalar) {
	(*this) = (*this)*scalar;
	return (*this);
}

template<class T, unsigned int N>
Vector<T, N> Vector<T, N>::operator/(T scalar) {
	Vector<T, N> result;
	for(int i=0; i<N; ++i) result[i] = (*this)[i]/scalar;
	return result;
}

template<class T, unsigned int N>
Vector<T, N>  Vector<T, N>::operator/=(T scalar) {
	(*this) = (*this)/scalar;
	return (*this);
}

template<class T, unsigned int N>
T Vector<T, N>::dot(Vector<T, N>& other) {
	T result = 0;
	for(int i=0; i < N; ++i) result += (*this)[i]*other[i];
	return result;
}

template<class T, unsigned int N>
double Vector<T, N>::magnitude() {
	return sqrt(this->dot(*this));
}

template<class T, unsigned int N>
Vector<T, N> Vector<T, N>::normalize() {
	return (*this)/(*this).magnitude();
}