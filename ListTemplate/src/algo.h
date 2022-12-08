//-----------------------------------------------------------------------------
// File algo.h
//-----------------------------------------------------------------------------
#ifndef ALGO_H_
#define ALGO_H_

#include <iostream>
#include "algo.h"
#include "list.h" 
#include <string>

//-----------------------------------------------------------------------------
namespace StructInfoAlgo {
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <class TData>
int (*Compare)(const TData&, const TData&);
//---------------------------------------------------------------------------

template <class TData>
class Predicate {

public:
//	Predicate() {};
  
	virtual bool operator()(const TData& name) const = 0;
   
};



template<class T> static inline void swap(T& d1, T& d2);
//-----------------------------------------------------------------------------
// TODO ... Déclarations des prototypes (find, find_if, reverse, bubbelSort)
//trouver le value dans une sequence
template<class it,class T>
	it find(it itbegin, it itend, T val);
template<class it,class predicate>
	it find_if(it itbegin, it itend, const predicate &p);
    //on inverse une sequence
template<class it>
	it reverse(it itbegin, it itend);
template<class it,class Compare>
    //on trie par ordre alphabetique une sequence
	void bubbelSort(it itbegin, it itend, Compare cpr);
    
//-----------------------------------------------------------------------------
template<class T> static inline void swap(T& d1, T& d2) {
	T temp(d1);
	d1=d2;
	d2=temp;
}
//-----------------------------------------------------------------------------
// TODO ... Définitions des patrons de fonctions (find, find_if, reverse, bubbelSort)
template<class it,class compare>
void bubbelSort(it itr1, it itr2, compare cpr){
    
    
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

template<class it,class predicate>
it find_if(it itbegin, it itend, const predicate &p) {
        
       
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


template<class it>
it reverse(it itbegin, it itend){
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


template<class it,class T>
	it find(it itbegin, it itend, T val) {
		while (itbegin != itend) {
			if (*itbegin == val) {
				return itbegin;
			}
			else{ ++itbegin;}
		}
		return itend;
	}

//-----------------------------------------------------------------------------
} // namespace StructInfoAlgo
//-----------------------------------------------------------------------------
#endif /*ALGO_H_*/
//-----------------------------------------------------------------------------
