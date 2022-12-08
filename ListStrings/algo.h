//-----------------------------------------------------------------------------
// File algo.h
//-----------------------------------------------------------------------------
#ifndef ALGO_H_
#define ALGO_H_
//-----------------------------------------------------------------------------
#include "list.h"

//-----------------------------------------------------------------------------
using namespace StructInfoList;
//-----------------------------------------------------------------------------
namespace StructInfoAlgo {
//-----------------------------------------------------------------------------
typedef int (*Compare)(const string&, const string&);
//---------------------------------------------------------------------------
class Predicate {
public:
//	Predicate() {};
	virtual bool operator()(const string& name) const = 0;
   
};
//-----------------------------------------------------------------------------
// TODO ... (find, find_if, reverse, bubbelSort) 

    //trouver le value dans une sequence
	list::iterator find(list::iterator itbegin, list::iterator itend, list::value_type val);
	list::iterator find_if(list::iterator itbegin, list::iterator itend, const Predicate &p);
    //on inverse une sequence
	list::iterator reverse(list::iterator itbegin, list::iterator itend);
    //on trie par ordre alphabetique une sequence
	void bubbelSort(list::iterator itbegin, list::iterator itend, Compare cpr);
//-----------------------------------------------------------------------------
} // namespace StructInfoAlgo
//-----------------------------------------------------------------------------
#endif /*ALGO_H_*/
//-----------------------------------------------------------------------------
