#include<vector>
#include<initializer_list>
#include<iostream>
#include<algorithm> 
#include<iterator> 
#include<numeric>
#include<random>
/**
*@file my_matrix.hpp
*@author Andrea Cordone
*
*/
///@brief Class template of a matrix to make linear algebra task (hopefully) more friendly 


template <typename T >
class Matrix {

	public:

		/**
		* 		
		*@brief Constructor to create an empty matrix.
		*
		*@param row Number of rows. 
		*@param col Number of columns.
		*/
		Matrix (const uint & row, const uint & col);
	        
		/**
		*
		*@brief  Constructor to create a matrix populated by a given value.	
		*
		*@param row Number of rows.
		*@param col Number of cols.
		*@param matrix_element Numerical value used to fill the matrix.
		**/ 
		Matrix (const uint & row, const uint & col, T matrix_element) ; 
	        
		/**
		*
		*@brief Constructor to initialize with an curly brace initialization list. 
		*
		*
		*@tparam T Any real-like type such as double, float, or long double. 
		*@param init_list Initialization list. 
		**/ 
		Matrix (std::initializer_list<std::vector<T>> init_list);
	        
		/**
		*@brief Constructor via a vector of vector
		*
		*@param matrix_ A usual  vector of vector from STD
		*/
                Matrix ( std::vector<std::vector<T>> ) ; 
	        
		/** 
		*@brief Constructor of a random valued matrix
		*
		*@param 	row Number of rows
		*@param 	col Number of columns
		*@param		mean Mean of the normal distribution
		*@param 	sd Standard deviation of the normal distribution
		*/ 
		Matrix ( const uint & row, const uint & col, const double & mean, const double & sd) ; 

	        	

		/**
		*@brief  Return the std::vector<std::vector<T>>> attribute of the class
		*
		*
		**/ 
		std::vector<std::vector<T>> get_matrix () const; 
	        
		
		/**
		*
		*@brief Method to return the diagonal of a matrix.
		*@param id Integer number indicating which diagonal to extract.
		*@note The main diagonals has id = 0. The lower diagonal have negative id while upper diagonals have positive id.
		*/
		std::vector<T> diag(const int id) const ; 

		// Extract submatrix
		Matrix<T> operator () (const uint &row_1 , const uint &row_2 , const uint &col_1 , const uint &col_2 ) ;  

		// Return the dimension of the matrix 
	        T dimension (const uint & idx) const ;
		
		// Change an element of the matrix  
		T & operator () ( const uint &row_idx, const uint &col_idx ) ; 
		
		// Return the elemt of the matrix 
		T operator () ( const uint &row_idx, const uint &col_idx ) const ;
		
	
                // Return the determinant 
	        double determinant () ; 			
			
		//Method for the ranspose 	
		void Tr () ; 
		
		// Method for scalar multiplication
		template <typename U>	
		friend Matrix<U> operator * ( const Matrix<U> & a, const  U & scalar ) ; 

		// Method to print the matrix 
		template <typename U>
		friend std::ostream& operator << ( std::ostream & out, const Matrix<U> & a) ;  		
		
		// Methods to perform the determinant
		T det(); 
		
		//Matrix<T> gauss_elimination() ; 
		Matrix<T> gauss_elimination() ;




	private:

		uint row ; 
		uint col ;	
		uint n ; 
		int sign ; 
		std::vector<std::vector<T>> matrix ; 

} ;



// Constructor with a std::vector<std::vector<T>>

template <typename T> 
Matrix<T>::Matrix (std::vector<std::vector<T>> matrix_) 
		: row(matrix_.size())
		, col(matrix_[0].size())
		, matrix(matrix_) {} 

// Simple constructor  
template <typename T>
Matrix<T>::Matrix (const uint & n_row, const uint & n_col) 
		: row(n_row)
		, col(n_col)
		, matrix(row,std::vector<T>(col)) {} 



// Constructor: Create a matrix with n_row and n_column with a single value  
template <typename T> 
Matrix<T>::Matrix (const uint & n_row, const uint & n_col, T matrix_element) 
		: row(n_row)
		, col(n_col)
		, matrix(row, std::vector<T>(col, matrix_element)){}

// Constructor with an initialization list 
template <typename T>
Matrix<T>::Matrix (std::initializer_list<std::vector<T>>   init_list) 
		
		: matrix(init_list) 
		{
			this->row = this->matrix.size() ; 
			this->col = this->matrix[0].size() ;
		}


// Construct random matrix 
template <typename T>  
Matrix<T>::Matrix (const uint & row , const uint & col, const double & mean, const double &sd )
		: row(row)
		, col(col)
		, matrix(row, std::vector<T>(col, 0))

{
	std::random_device rd{};
	std::mt19937 gen{rd()};
        std::normal_distribution<T> d{mean,sd};


	for (size_t i = 0 ;  i<row;  ++i) 
	{
		for (size_t k =0 ;  k<col ;  ++k) 
		{
		      matrix[i][k] =  d(gen) ;  	
		
		}
	}
 
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



// Return the diagonal 
template <typename T>
std::vector<T> Matrix<T>::diag(const int id ) const  
{
	if ( this->dimension(1) != this->dimension(2) ) 
		throw std::invalid_argument("Diagonal only available for Square matrix");  



	std::vector<T> diagonal ; 

	if (id <= 0 ) 
{
		
	
	for ( size_t i = 0; i<row ; ++i)
	{ 
			diagonal.push_back(matrix[i+id][i]) ; 
	}

}	
	
	else
{
	for ( size_t i = 0 ; i<row ; ++i ) 
	{	
		diagonal.push_back(matrix[i][i+id]) ; 
	}

}

return diagonal; 

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

	// Return the std::vector<std::vector>> attribute 
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
			
		std::cout<< "Matrix dimension are:"<<a.dimension(1)<<"x"<<a.dimension(2)<<" and "<<b.dimension(1)<<"x"<<b.dimension(2)<<std::endl ; 
		throw std::invalid_argument ( " Matrix dimension must agree for matrix multiplication " ); \

	}  
		
	Matrix<T> res (a.dimension(1) , b.dimension(2) ) ; 

	 for ( uint i = 0; i<a.dimension(1); i++ ) {

		for ( uint k =  0 ; k<a.dimension(2) ; k++ ) {

			res(i,k)  += a(i,k)*b(i,k) ;  

		}

	 }
	return res ; 
	}	


	// Gauss elimination 
	template <typename T>
	Matrix<T> Matrix<T>::gauss_elimination()  {

		if ( this->dimension(1) != this->dimension(2) ) 
	{

		throw std::invalid_argument ( " Gauss elimination only implemented for square matrices" ) ; 
	}

		std::vector<std::vector<T>> res  = this->matrix;   
		

			
		for( unsigned int i = 0; i<row-1 ; i++ ) 
		{

			if ( res[i][i] == 0 ) 

			{  
				T max_el = 0 ; 
				size_t idx_max = 0 ; 

				for ( size_t k = i+1 ; k<col-1 ; ++k ) 
				{
					if (std::abs(res[i+1][k]) > max_el)  
					{  
						max_el  = res[k][i] ;
						idx_max = k ; 
					}
				}		
				
				std::vector<T> temp = res[i]; 
				res[i] = res[idx_max];
				res[idx_max] = temp ; 	
				sign = sign*-1 ; 	
			}	



		for (unsigned int j = i+1; j<col ; j++) 
		{


		      T factor = res[j][i] / res[i][i] ; 
				
		      for ( unsigned int k = i ; k < col ; k++ ) 
		      {

				   res[j][k] = res[j][k] - factor*res[i][k] ; 
				   
		      }		
		}
	}


	Matrix<T> result (res)  ; 
	result.sign = sign ; 
	return result; 

	}


	// Return the determinant 
	template <typename T>
	T Matrix<T>::det() 
	{

		Matrix<T> up_triag = this->gauss_elimination() ; 
		
		std::vector<T> diagonal = up_triag.diag(0);

		T  det = std::accumulate(diagonal.begin(),diagonal.end(), 1.0, std::multiplies<T>());
		
		
		return det;  




	}

	// Return the submatrix 
	template <typename T>
	Matrix<T> Matrix<T>::operator () ( const uint &row1, const uint &row2, const uint &col1, const uint &col2) 
	{
			
			unsigned int size_row = row2-row1 +1 ; 
			unsigned int size_col = col2-col1 +1 ; 

			std::vector<std::vector<T>> res ( size_row , std::vector<T>(size_col, 0))  ; 
			
			for ( size_t i = row1; i<=row2 ; ++i ) 
			{
				
				for ( size_t k=col1; k<= col2; ++k ) 
				{
					
					res[i-row1][k-col1] = this->matrix[i][k] ; 
				}
			}	

		Matrix<T> result (res) ; 		
		return result;	
	}	










		



