//-----------------------------------------------------------------------------
// file list.cpp
//-----------------------------------------------------------------------------
#include "list.h"
#include <iostream>
//-----------------------------------------------------------------------------
namespace StructInfoList {
//-----------------------------------------------------------------------------
// TODO ... (list::TNode::...)

list::~list(){
    // value = valueNode;

}
    
    //a = sx12412
    //a = 5
 list::list(list& listNode){
    //on veut l'objet 
    this->nodeCount = 0;
    this->pEndNode = _CreateHeaderNodeCopyList();
    iterator i1;
    //on insert avant le dernier element
    iterator endtoinsert = end();
    for (i1 = listNode.begin(); i1 != listNode.end(); ++i1) {
        
			insert(endtoinsert, *i1);
		}

 }

     
 list::TNode::TNode(TNode& copyNode){
    TNode* node = new TNode();
    
    node->pPrevious = copyNode.pPrevious;
    node->pNext = copyNode.pNext;

    memcpy(&(node->value), &copyNode.value , sizeof(copyNode.value));
    //return node;
    }
    
    
 list::TNode::~TNode(){
    }
    
  list::TNode::TNode(){
    //constructeur vide
    }   
    
list::list(){
   
    this->nodeCount= 0;
    this->pEndNode = _CreateHeaderNode();
    //this->_begin = _CreatebeginNode();
    //this->_end = _CreateEndNode();
    }
    

list::TNode* list::_CreateHeaderNode(){
    TNode* element =new TNode();
     element->pPrevious = element;
    element->pNext =element;
     return element;
    }
    
list::TNode* list::_CreateHeaderNodeCopyList(){
    TNode* element =new TNode();
     element->pPrevious = element;
    element->pNext =element;
     return element;
        }
        
        
 //noeud garde fou
/*list::TNode* list::_CreatebeginNode(){
	
                      
	TNode* begin_ =new TNode();
    
    begin_->pPrevious = NULL;
    begin_->pNext =this->_end;
     return begin_;
	}
    
    
 //noeud garde fou
list::TNode* list::_CreateEndNode(){
	
    TNode* end_ =new TNode();                
	 end_->pPrevious = this->_begin;
     end_->pNext =NULL;
     return end_;
    
     return end_;
	}
  */  
    
    
//-----------------------------------------------------------------------------
// TODO ... (list::iterator::...)

list::iterator::iterator(){
   //constructeur vide
}

list::iterator::~iterator() {
   // destructeur
}

list::iterator::iterator(TNode* node){
    itrNode = node;
    }

list::iterator::iterator(const iterator& itr){
    itrNode = itr.itrNode;
    }


bool list::iterator::operator==(iterator itr){
    if(itrNode== itr.itrNode){
    return true;
        }
    else{
        return false;
        }
    
    }
bool list::iterator::operator!=(iterator itr){
    if(itrNode!= itr.itrNode){
    return true;
        }
    else{
        return false;
        }
    
    }

list::iterator list::iterator::operator++(){
    
    itrNode = itrNode->pNext;
    return *this;
    }
list::iterator list::iterator::operator--(){
    
    itrNode = itrNode->pPrevious;
    return *this;
    }
    

list::value_type& list::iterator::operator*(){
    return itrNode->value;
    }
    

//---------------------------------------------------------------------------
// TODO ... (list::const_iterator::...)


list::const_iterator::~const_iterator(){
    //destructeur
    }
list::const_iterator::const_iterator(){
   // constructeur vide
    }
list::const_iterator::const_iterator(TNode* node){
    const_Node = node;
    }
list::const_iterator::const_iterator(const const_iterator& const_itr){
    const_Node = const_itr.const_Node;
    }
list::const_iterator::const_iterator(const iterator& itr){
        const_Node=itr.itrNode;
    }


bool list::const_iterator::operator==(const_iterator const_itr) const {
    if(const_Node== const_itr.const_Node){
    return true;
        }
    else{
        return false;
        }
    
    }

bool list::const_iterator::operator!=(const_iterator const_itr) const{
    if(const_Node!= const_itr.const_Node){
    return true;
        }
    else{
        return false;
        }
    
    }
 list::value_type& list::const_iterator::operator*() const {
		return const_Node->value;
	} 


list::const_iterator list::const_iterator::operator--() {
		const_Node  = const_Node->pPrevious;
		return *this;
	}
list::const_iterator list::const_iterator::operator++() {
		const_Node  = const_Node->pNext;
		return *this;
	}


//-----------------------------------------------------------------------------
// TODO ... (list::...)
//probleme 
//-----const_iterator-----
list::const_iterator list::begin_consitr(){
    
    list::const_iterator* itr = new list::const_iterator(pEndNode->pNext);
   
    }
list::const_iterator list::end_consitr(){
    
    list::const_iterator* itr = new list::const_iterator(pEndNode);

    }

//*********iterator*****
//le begin commence à gauche et le end à droite du noeud garde fou
list::iterator list::begin() const {
    
    //iterator* itr = new iterator(_pEndNode->pNext );
   // return *itr;
    iterator* itr = new iterator(pEndNode->pNext );
    return *itr;
    }
int list::nodeCountmethod() const {
    
    return this->nodeCount;
    }
list::iterator list::end() const {
    
    //iterator* itr = new iterator(_pEndNode);
    //return *itr;
    iterator* itr = new iterator(pEndNode);
    return *itr;
    }



bool list::IsEmptyList(list& listnode){
    if(listnode.nodeCount ==0){
        return  true;
    }else{
        return false;
        }
        
    }
    
int list::size() const{
    
    return nodeCount;
     }

//*********insert**************
//********************************on insere un element entre deux noeud*****************************
void list::insert(iterator& itrNextelement, value_type& value) {
        //j'insere un element entre deux nodes. donc on va jouer avec l'iterateur qui change de position de pointage 
        //itr pointe vers le node . 
       
        
        
        //je crée le noeud
		TNode* nodeCreated = new TNode();
        //l'iterateur pointe vers un node . donc le pNext du noeud crée  = au noeud pointée par l'iterateur
		nodeCreated->pNext = itrNextelement.itrNode;
        //l'iterateur change de position; donc l'iterateur pointe vers un noeud precedent 
		//--itrNextelement;
		nodeCreated->pPrevious = itrNextelement.itrNode->pPrevious;//donc le noeud crée entre deux noeud
        /*je copie le contenu de s dans element->value*/
        nodeCreated->value = value;
        itrNextelement.itrNode->pPrevious->pNext = nodeCreated;
        itrNextelement.itrNode->pPrevious = nodeCreated;
      
		nodeCount++;
		
	}

list::iterator list::insert(iterator nextelement, iterator itr_begin,iterator itr_end) {
		int count =0;
        int nodecount = this->nodeCount;
        std::cout<<"nodecount = "<<nodecount<<std::endl;
        while (count!=nodecount) {
            
            //on insert devant nextelement qui est le p3
			insert(nextelement, *itr_begin);
            std::cout<<*itr_begin<<std::endl;
			++itr_begin;
            count++;
		}
		return nextelement;
	}
    
    
list::iterator list::erase(iterator itr){
    //itr est l'element à supprimer
    //itr.itrNode->pPrevious est l'element avant itr
    //itr.itrNode->pNext est l'element apres itr
	
    
    
    itr.itrNode->pPrevious->pNext = itr.itrNode->pNext;
    itr.itrNode->pNext->pPrevious = itr.itrNode->pPrevious;
	iterator nextitr(itr.itrNode->pNext);
    
    delete [] &itr;
   
    nodeCount-=1;

   
	return nextitr;
    }
list::iterator list::erase(iterator itr_begin,iterator itr_end){
    
    iterator tmp =NULL;
	tmp = itr_begin;
	/*supprime chaque element de cette boucle*/
	while(tmp != itr_end ){
		tmp = erase(tmp);
    
		}
    return itr_end;
    }

//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------
