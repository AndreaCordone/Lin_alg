#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

 template <typename T>
 class Vector {

	public:
	
		Vector ( const uint & dim_, T & value ) ;  	
                T get_element(const uint & pos) ; 
	




	private: 

	std::vector<T> vect ; 
	double dim ;


} ; \


template <typename T>
Vector<T>::Vector ( const uint & dim_, T & value )
		:vect(dim_,value) {} 


T Vector<T>::get_element(const uint & pos) { return this->vect[pos] ; } 
