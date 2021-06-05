#include<vector>
#include<initializer_list>
#include<iostream>
#include<algorithm> 
#include<iterator> 

template <typename T >
class Matrix {

	public:
		Matrix ( const uint & row, const uint & col, T matrix_element ) ;  
		Matrix ( std::initializer_list<std::vector<T>> init_list ) ; 

		T dimension (const uint & idx) ; 
		T & operator () ( const uint &row_idx, const uint &col_idx ) ; 
		T operator () ( const uint &row_idx, const uint &col_idx ) const ; 
		
		template <typename U>
		friend std::ostream& operator << ( std::ostream & out, const Matrix<U> & a) ;  		

	private:

		uint row ; 
		uint col ;	
		std::vector<std::vector<T>> matrix ; 

} ;

 
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
{}

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
T  Matrix<T>::dimension (const uint & idx)
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


