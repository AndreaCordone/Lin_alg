#include "my_matrix.hpp"


Matrix::Matrix (const uint & n_row, const uint & n_col, double  matrix_element) 
		: row(n_row)
		, col(n_col)
                , matrix(row, std::vector<double>(col, matrix_element)) 
{}

Matrix::Matrix (std::initializer_list<std::vector<double>>   init_list) 
		:matrix(init_list) 
{}

// Method to return the matrix dimension
std::pair<uint,uint> Matrix::dimension ()
{
	return std::make_pair( this->row,this->col) ; 
}


// Methods to assign a value to a matrix element of the a  Matrix object
double & Matrix::operator()( const uint &row_idx, const uint &col_idx ) 
{

	return this->matrix[row_idx][col_idx] ; 

}

// Methods to get the matrix element of a Matrix object give the row and column indices
double  Matrix::operator () (const uint &row_idx, const uint &col_idx) const 
{
	return this->matrix[row_idx][col_idx] ; 

}


