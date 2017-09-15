#include<iostream>
using namespace std;

class Matrix {
private:
	double* m; // points to a single vector of double...
	int rows;
	int cols;
public:
	// Constructor, fills with zeros
	Matrix(int rows, int cols) : rows(rows) , cols(cols)  {
		double a[rows * cols];
		m = new double[rows*cols];
		for(int i = 0; i < rows*cols; i++){
			m[i] = 0.0;
		}
	}
	// constuctor, fills with value
	Matrix(int rows, int cols, double value) : rows(rows),cols(cols) {
		double a[rows * cols];
		m = new double[rows*cols];
		for(int i = 0; i < rows*cols; i++){
			m[i] = value;
		}
	}
	
	// Copy constructor
	Matrix(const Matrix& orig) : m(new double[orig.cols*orig.rows]), rows(orig.rows), cols(orig.cols){
		for(int i = 0; i < cols*rows; i++)
			m[i] = orig.m[i];
	} 
	double  operator ()(int i, int j) const {
		return m[ i * this->cols + j];
	}
	double&  operator ()(int i, int j) {
		return m[ i * this->cols + j];
	}
	
	//Move Constructor?
	Matrix(Matrix&& orig) : m(orig.m), rows(orig.rows), cols(orig.cols){
		orig.m = nullptr;
	}
	// Addition operation overload
	friend Matrix operator +(const Matrix& a, const Matrix& b) {
		// test if the two matrices are equal in size!!!
		if(a.cols != b.cols || a.rows != b.rows)
			return a;
		Matrix ans(a.rows, a.cols);
		
		for(int i = 0; i < a.rows; i++){
			for(int j = 0; j < a.cols; j++)
				ans.m[i*ans.cols + j] = a.m[i*ans.cols + j] + b.m[i*ans.cols + j];
		}
		return ans;
	}
	
	// equal operator
	void operator =(const Matrix& orig){
		if(this != &orig){
			delete [] m;
			m = new double[orig.rows*orig.cols];
			rows = orig.rows;
			cols = orig.cols;
			for (int i = 0; i < rows*cols; i++)
				m[i] = orig.m[i];
		}
	}
	// cout operation overload
	friend ostream& operator << (ostream& s, const Matrix& a){
		for(int i = 0; i < a.rows; i++){
			s << '\n';
			for(int j = 0; j < a.cols; j++)
				s << a.m[i * a.cols + j] << " ";
		}
		return s;
	}
	//destructor
	~Matrix(){
		delete[] m;
	}		
};

int main() {
	Matrix m1(3, 4); // zeros
	Matrix m2(2, 3, 1.5); // fill with 1.5
	cout << m1 << '\n';
	/*
	0   0   0   0
    0   0   0   0
    0   0   0   0
	*/
	cout << m1(0, 1) << '\n';
	m1(0,1) = 5.5;
	Matrix m3 = m1 + m1;
	Matrix m4 = m3;  //copy constructor
	cout << m4 << '\n';
	m4(1,2) = 11.2;
	m3 = m4; // operator =
}
