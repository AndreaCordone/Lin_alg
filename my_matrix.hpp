#include<vector>
#include<initializer_list>
#include<iostream>
#include<algorithm> 
#include<iterator> 




template <typename T >
class Matrix {

	public:
		// COnstructor to create an empty matrix
		Matrix ( const uint & row, const uint & col) ;
	        // Constructor to create a matrix populated only by one element	
		Matrix ( const uint & row, const uint & col, T matrix_element ) ; 
	        // Constructor to create a matrix with initialization list 	
		Matrix ( std::initializer_list<std::vector<T>> init_list ) ;
	        // Constructor with a std::vector<std::vector>>	
                Matrix ( const uint & row,const uint & col, std::vector<std::vector<T>>) ; 
		
		// Return the std::vector<std::vector>>
		std::vector<std::vector<T>> get_matrix () const; 
	        
		// Return the dimension of the matrix 
	        T dimension (const uint & idx) const ;
		
		// Change an element of the matrix  
		T & operator () ( const uint &row_idx, const uint &col_idx ) ; 
		
		// Return the elemt of the matrix 
		T operator () ( const uint &row_idx, const uint &col_idx ) const ; 
		
		//Method for the ranspose 	
		void Tr () ; 
		
		// Method for scalar multiplication
		template <typename U>	
		friend Matrix<U> operator * ( const Matrix<U> & a, const  U & scalar ) ; 

		// Method to print the matrix 
		template <typename U>
		friend std::ostream& operator << ( std::ostream & out, const Matrix<U> & a) ;  		
		
		// Methods to perform 



	private:

		uint row ; 
		uint col ;	
		std::vector<std::vector<T>> matrix ; 

} ;



// Constructor with a std::vector<std::vector<T>>

template <typename T> 
Matrix<T>::Matrix (  const uint & n_row, const uint & n_col, std::vector<std::vector<T>> matrix_) 
		: row(n_row)
		, col(n_col)
		, matrix(matrix_) {} 

// Simple constructor  
template <typename T>
Matrix<T>::Matrix ( const uint & n_row, const uint & n_col) 
		: row(n_row)
		, col(n_col)
		,matrix(row,std::vector<T>(col)) {} 



// Constructor: Create a matrix with n_row and n_column with all elemt eqaul  
template <typename T> 
Matrix<T>::Matrix ( const uint & n_row, const uint & n_col, T matrix_element) 
		: row(n_row)
		, col(n_col)
                , matrix(row, std::vector<T>(col, matrix_element)) 
{}

// Constructor with an initialization list 
template <typename T>
Matrix<T>::Matrix (std::initializer_list<std::vector<T>>   init_list) 
		:matrix(init_list) 
{
this->row = this->matrix.size() ; 
this->col = this->matrix[0].size() ; 

}

// Return the element of a matrix 
template <typename T>  
T Matrix<T>::operator () (const uint &row_idx, const uint &col_idx) const 
{
	return this->matrix[row_idx][col_idx] ; 

}
// Method to change a matrix element 
template <typename T>  
T &  Matrix<T>::operator () (const uint &row_idx, const uint &col_idx)  
{
	return this->matrix[row_idx][col_idx] ; 

}


// Method to return the matrix dimension
template <typename T> 
T  Matrix<T>::dimension (const uint & idx) const 
{
	if (idx == 1) { return this->row  ; }

	else { return this->col ; }
	
}


// Metodo per printare il contenuto della matrice 
template <typename U>  
std::ostream& operator<< (std::ostream& out, const Matrix<U> & a) { 

   for (auto it = a.matrix.begin();  it != a.matrix.end(); ++it ) {

	std::copy (it->begin(),it->end(),std::ostream_iterator<U>(out, " ")) ; 
        out << "\n" ; 
	} 
		

      return out ; 
  }


// Methods to perform the transpose 
template <typename T> 
void Matrix<T>::Tr () {

 std::vector<std::vector<T>> res ( this->col, std::vector<T>(this->row, 0 ) ) ; 
 
 
 
for (int row_idx = 0; row_idx != this->row; ++row_idx) {
	for (int col_idx = 0; col_idx != this->col ; ++col_idx) {

		res[col_idx][row_idx] = this->matrix[row_idx][col_idx]  ;
} }

 this->matrix.assign(res.begin(),res.end()) ; 
 
 const int temp = this->col ;
 this->col = this->row ; 
 this->row = temp ; 
 
      	
}


template <typename T>
std::vector<std::vector<T>> Matrix<T>::get_matrix () const { return this->matrix ; }  

// Multuply by a scalar 
template <typename U>	
Matrix<U> operator * (const Matrix<U> & a, const U & scalar ) {


std::vector<std::vector<U>> src = a.get_matrix() ; 
std::vector<std::vector<U>> dst(a.dimension(1),std::vector<U>(a.dimension(2),0))	;  

for (auto it = std::make_pair(src.begin(),dst.begin()) ; it.first != src.end() ; ++it.first,++it.second ) {
	
std::transform(it.first->begin(), it.first->end(), it.second->begin(), [& scalar](auto & it_value ){ return scalar*it_value;});
 
}

Matrix<U> res (a.dimension(1),a.dimension(2),dst) ; 
 
return  res ; 
} 


// Methods to perform matrix multiplication 
template <typename T>
Matrix<T> operator * (const Matrix<T> & a , const Matrix<T> & b ) {

if (  a.dimension(2)!= b.dimension(1) ) { 
         	throw "Number of column of first matrix does not match number of rows"; 
}  
	
Matrix<T> res (a.dimension(1) , b.dimension(2) ) ; 

 for ( uint i = 0; i<a.dimension(1); i++ ) {

	for ( uint k =  0 ; k<a.dimension(2) ; k++ ) {

		res(i,k)  += a(i,k)*b(i,k) ;  

	}

 }
return res ; 
}	




