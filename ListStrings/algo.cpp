//-----------------------------------------------------------------------------
// file algo.cpp
//-----------------------------------------------------------------------------
#include <iostream>
#include "algo.h"
#include "list.h"

//-----------------------------------------------------------------------------
using namespace StructInfoList;
//-----------------------------------------------------------------------------
inline void swap(string& d1, string& d2) {
	string temp(d1);
	d1=d2;
	d2=temp;
}
//-----------------------------------------------------------------------------
namespace StructInfoAlgo {
//-----------------------------------------------------------------------------
// TODO ...

list::iterator find(list::iterator itbegin, list::iterator itend,list::value_type val) {
		while (itbegin != itend) {
			if (*itbegin == val) {
				return itbegin;
			}
			else{ ++itbegin;}
		}
		return itend;
	}


list::iterator reverse(list::iterator itbegin, list::iterator itend){
    	--itend;
		while (itbegin != itend) {
			swap(*itbegin, *itend);
			if (++itbegin != itend) {
				--itend;
			}
			else break;
		}
		return itend;
    }
    

list::iterator find_if(list::iterator itbegin, list::iterator itend, const Predicate &p) {
        
       
        while (itbegin != itend) {
			if (p(*itbegin)) {
				return itbegin;
			}
			else {
                ++itbegin;
           
            }
         
		}
		return itend;
	}
void bubbelSort(list::iterator itr1, list::iterator itr2, Compare cpr){
    
    
      it it_(itr1);
      it itsecond(itr2);
        
        itsecond = ++it_;
        --it_;
      for(;itr1!=itr2;){   
          //it_ et itsecond sont des copie constructeut
         //exple: it pointe sur itr1 et itsecond pointe sur la case après itr1
        //ensuite pour la premiere boucle: on compare it et itsecond , si it > itsecond ,on swap  et ensuite on incremente
      
        for(;itsecond!=itr2; ++itsecond ){
                //on veut mettre dans le case que pointe itr la valeur la plus petite
                //on verifie si la difference est >0 ,si oui, le valeur que pointe itr1 est > que la valeur que pointe it
                  
                if (cpr(*it_, *itsecond) > 0) {
					swap(*it_, *itsecond);
          //        std::cout<<"boucle =>"<<"value1 " <<*itr1<<"  value2 "<<*it<<" value3 " <<*itr2<<std::endl;
				}
            ++it_;
        }
        //ensuite on fait la meme operation, dans l'autre sens
        //les deux copie pointeur changent de position et on incremente de 1 
        --itr2;
        --it_;
        --itsecond;
        if(itr1 == itr2){break;}
        
        //la on veut faire la meme operation mais dans le sens opposé.
        // cad on cherche l'élement le plus grand et on les met dans la case que pointe itr2
        
       
        
       for(;itsecond!=itr1; --it_ ){
                
                 
                if (cpr(*it_, *itsecond) > 0) {
					swap(*it_, *itsecond);
          }
                --itsecond;
        }
        
            
            
        ++itr1;
        ++it_;
        ++itsecond;
      
    }
    
    
}
//-----------------------------------------------------------------------------
} // namespace StructInfoAlgo
//-----------------------------------------------------------------------------
