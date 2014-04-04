/* 
 * http://en.wikipedia.org/wiki/Matrix_(mathematics)
 */
template<class T, int N, int M>
class Matrix {
	T data[N][M];
	
	/* arithmetic */
	Matrix<T, N, M> operator+(Matrix<T, N, M>& other);
	Matrix<T, N, M> operator+=(Matrix<T, N, M> other);
	
	Matrix<T, N, M> operator-(Matrix<T, N, M>& other);
	Matrix<T, N, M> operator-=(Matrix<T, N, M>& other);
	
	Matrix<T, N, M> operator*(T scalar);
	Matrix<T, N, M> operator*=(T scalar);
	
	Matrix<T, N, M> operator*(Matrix<T, N, M>& other);
	Matrix<T, N, M> operator*=(Matrix<T, N, M>& other);
	
	Matrix<T, N, M> operator/(T scalar);
	Matrix<T, N, M> operator/=(T scalar);

	//template<>
	//T determinant<T, N, N>();
	
	Matrix<T, N, M> transpose();
	Matrix<T, N, M> inversion();
};