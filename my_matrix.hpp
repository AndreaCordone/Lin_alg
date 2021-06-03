#include<vector>
#include<initializer_list>
#include<iostream>

class Matrix {

	public:
		Matrix ( const uint & row, const uint & col, double matrix_element ) ;  
		Matrix ( std::initializer_list<std::vector<double>> init_list ) ; 

		std::pair<uint,uint> dimension () ; 
		double & operator () ( const uint &row_idx, const uint &col_idx ) ; 
		double operator () ( const uint &row_idx, const uint &col_idx ) const ; 


	private:

		uint row ; 
		uint col ;	
		std::vector<std::vector<double>> matrix ; 

} ; 
