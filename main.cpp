#include "my_matrix.hpp"


int main () {


    Matrix a(2,2,3.14) ; 


    a(1,1) = 0.0  ;
  
   Matrix b {{ 2, 1 },{2, 2 }}  ; 

  std::cout <<b (1,1) << std::endl ; 

}

