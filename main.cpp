#include"my_matrix.hpp"


int main () {


	  //  Matrix<double> a(2,2,3) ; 
	    

	 //   a(1,1) = 2.12  ;
	 //   std::cout<<"Matrix dimensio is " <<  a.dimension(1)<<std::endl  ;  
	 

	  //      Matrix<double> a {{ 2.3, 1.1,4.3 },{2.2,0.1,2.12},{2.29,1.2,1.3}}  ; 
		//std::cout<<"Matrix row dimension is:"<< b.dimension(1)<<std::endl ; 
		//std::cout<<"Matrix col dimension is:"<< b.dimension(2)<<std::endl ;
		//b.Tr() ;
		//std::cout<<"Matrix row dimension is now:"<< b.dimension(1)<<std::endl ; 
		//std::cout<<"Matrix col dimension is now:"<< b.dimension(2)<<std::endl ;

		//std::cout << b(1,1) << std::endl ; 
	 
	   
		//Matrix<int> b (2,2,1) ;  
		//Matrix<int> c =  a*b ; 
	// 	Matrix<double>  k = a.gauss_elimination() ;   
		 Matrix<double> a (2,2,0.0,1.0) ; 	
		
		Matrix<double> b = a.gauss_elimination() ; 

		std::vector<double> dd = b.diag(0) ;  
		
		/*double det = 1.0; 
		 for ( auto i = 0 ;  i<10; ++i ) 
		 {
			 det  = det*dd[i]; 
		 } */

		auto cc = a.det(); 
		std::cout<<cc<<std::endl;
		std::cout<<"--------"<<std::endl; 	
		std::cout<<b; 	
		//std::copy (dd.begin(), dd.end(), std::ostream_iterator<double>(std::cout, ", "));
	}

