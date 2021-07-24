#include "my_matrix.hpp"


int main () {


  //  Matrix<double> a(2,2,3) ; 
    

 //   a(1,1) = 2.12  ;
 //   std::cout<<"Matrix dimensio is " <<  a.dimension(1)<<std::endl  ;  
 

        Matrix<int> a {{ 2, 1,4 },{2,0,5},{2,1,1}}  ; 
	//std::cout<<"Matrix row dimension is:"<< b.dimension(1)<<std::endl ; 
	//std::cout<<"Matrix col dimension is:"<< b.dimension(2)<<std::endl ;
	//b.Tr() ;
        //std::cout<<"Matrix row dimension is now:"<< b.dimension(1)<<std::endl ; 
	//std::cout<<"Matrix col dimension is now:"<< b.dimension(2)<<std::endl ;

        //std::cout << b(1,1) << std::endl ; 
 
   
        //Matrix<int> b (2,2,1) ;  
        //Matrix<int> c =  a*b ; 
Matrix<int>  k = a.gauss_elimination() ;   
        
	//std::vector<int> diag  = a.diag(0) ;  
        std::cout<< k<<std::endl ;  

}

