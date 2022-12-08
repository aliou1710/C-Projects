//-----------------------------------------------------------------------------
// File list.h
//-----------------------------------------------------------------------------
#ifndef LIST_H_
#define LIST_H_
//-----------------------------------------------------------------------------
// Pour list, il faut dans TData : copy constructor, operator =, destructor
// Pour bubbleSort, il faut dans TData : <
// Pour find, il faut dans TData : ==
//-----------------------------------------------------------------------------
namespace StructInfoList {
//-----------------------------------------------------------------------------
template<class TData> class list {
protected:
	//-------------------------------------------------------------------------
	struct TNode {
		// TODO ...
         ////node a trois element: les deux pointeurs pNext et pPrevious et la data 
        TNode* pPrevious;
        TNode* pNext;
        TData value;
       
        //destructeur 
        ~TNode(){}
        //constructeur
        TNode(){}
        
        TNode(TNode& copyNode){
            TNode* node = new TNode();
            node->pPrevious = copyNode.pPrevious;
            node->pNext = copyNode.pNext;
            memcpy(&(node->value), &copyNode.value , sizeof(copyNode.value));
            //return node;
        }
        TNode(TData& valuedata) {
				value = valuedata;
			}
	};
	//-------------------------------------------------------------------------
public:
	//-------------------------------------------------------------------------
	class const_iterator; // !!!
	class iterator {
public:
	// TODO ... (déclarations + définitions inline)
      ~iterator(){}
      //constructeur 
      iterator(){}
      iterator(TNode* node){itrNode = node;}
      iterator(const iterator& itr){itrNode = itr.itrNode;}
      //operators
      inline iterator operator++(){
          itrNode = itrNode->pNext;
          return *this;
        }
        
       inline iterator operator--(){
        itrNode = itrNode->pPrevious;
        return *this;
       }
       
       inline TData& operator*(){
            return itrNode->value;
        }
                
     
        
        inline const TData& operator*() const {
            return (itrNode->value);
			}
        
        bool operator==(iterator itr){
            if(itrNode== itr.itrNode){
                return true;
            }
            else{
                return false;
                }
            }
        
        
        bool operator!=(iterator itr){
            if(itrNode!= itr.itrNode){
                return true;
            }
            else{
                return false;
                }
            }
            
protected:
	// TODO ...
     TNode* itrNode;
     friend class list; 
	};

	class const_iterator { // !!!
public:
	// TODO ... (déclarations + définitions inline)
    ~const_iterator(){}//destructeur
    const_iterator(){}// constructeur vide
    const_iterator(TNode* node){const_Node = node;}
    
    const_iterator(const const_iterator& const_itr){
    const_Node = const_itr.const_Node;
    }
    
    const_iterator(const iterator& itr){
        const_Node=itr.itrNode;
    }

    //operateurs
    bool operator==(const_iterator const_itr) const {
        if(const_Node== const_itr.const_Node){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator!=(const_iterator const_itr) const{
        if(const_Node!= const_itr.const_Node){
            return true;
        }
        else{
            return false;
        }
    
    }
    
    TData& operator*() const {
		return const_Node->value;
	} 


    const_iterator operator--() {
		const_Node  = const_Node->pPrevious;
		return *this;
	}
    const_iterator operator++() {
		const_Node  = const_Node->pNext;
		return *this;
	}
    
    inline TData* operator->() {
				return &(const_Node->value);
        }
protected:
	// TODO ...
    TNode* const_Node;
    friend class list;
	};

	// TODO ... (typedefs)
    	typedef TData value_type;
		typedef const TData& const_reference;
        typedef TData& reference;
		
	//-------------------------------------------------------------------------
	// TODO ... (déclarations)
    //destructeur
    ~list();
    //constructeur
    list();
    //copy constructeur
    list(list& listNode);
    list* CreateList();
    TNode* _CreateHeaderNode();
    TNode* _CreateHeaderNodeCopyList();
    //TNode* _CreateEndNode();
    //TNode* _CreatebeginNode();
    //method
    const_iterator end_consitr();
    const_iterator begin_consitr();
    iterator begin() const ;
    iterator end() const;
    iterator erase(iterator itr);//supprimer un node
    iterator erase(iterator itr_begin, iterator itr_end); //supprimer une sequence de node
    void insert(iterator itrNextelement, TData& value);//insert avant to itrNextelement
    iterator insert(iterator nextelement, iterator itr_begin,iterator itr_end); // ajouter une sequence de node
    inline int size() const ;
    inline bool IsEmptyList();
    inline int nodeCountmethod() const;
    
protected:
	//-------------------------------------------------------------------------
	// TODO ...
        TNode* pEndNode;
        int nodeCount;//nbre d'element de la chaine 
	//-------------------------------------------------------------------------
};
//-----------------------------------------------------------------------------
// TODO ... (template<class TData> inline list<TData>::TNode::...)
template<class TData>
typename list<TData>::TNode* list<TData>::_CreateHeaderNode(){
    TNode* element =new TNode();
     element->pPrevious = element;
    element->pNext =element;
     return element;
    }
      


template<class TData>
typename list<TData>::TNode* list<TData>::_CreateHeaderNodeCopyList(){
    TNode* element =new TNode();
     element->pPrevious = element;
    element->pNext =element;
     return element;
}
//-----------------------------------------------------------------------------
// TODO ... (template<class TData> inline list<TData>::iterator::...)

template<class TData>
typename list<TData>::iterator list<TData>::begin() const {
    
    iterator* itr = new iterator(pEndNode->pNext );
    return *itr;
    }

template<class TData>
 inline int list<TData>::nodeCountmethod() const {
    
    return this->nodeCount;
    }
    
template<class TData>
typename list<TData>::iterator list<TData>::end() const {
    
    iterator* itr = new iterator(pEndNode);
    return *itr;
    }

template<class TData>
bool list<TData>::IsEmptyList(){
    if(nodeCount ==0){
        return  true;
    }else{
        return false;
        }
        
}


    
template<class TData>
 inline int list<TData>::size() const{
    
    return nodeCount;
     }

template<class TData>
typename list<TData>::iterator list<TData>::insert(iterator nextelement, iterator itr_begin,iterator itr_end) {
		int count =0;
        int nodecount = this->nodeCount;
        while (count!=nodecount) {
            
            //on insert devant nextelement qui est le p3
			insert(nextelement, *itr_begin);
			++itr_begin;
            count++;
		}
		return nextelement;
	}
        

template<class TData>
typename list<TData>::iterator list<TData>::erase(iterator itr_begin,iterator itr_end){
    iterator tmp =NULL;
	tmp = itr_begin;
	/*supprime chaque element de cette boucle*/
	while(tmp != itr_end ){
		tmp = erase(tmp);
    
		}
    return itr_end;
    }

template<class TData>
typename list<TData>::iterator list<TData>::erase(iterator itr){
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
//-----------------------------------------------------------------------------
// TODO ... (template<class TData> inline list<TData>::const_iterator::...)
template<class TData>
typename list<TData>::const_iterator list<TData>::begin_consitr(){
    
    list<TData>::const_iterator* itr = new list<TData>::const_iterator(pEndNode->pNext);
    return *itr;
    }
    
    
template<class TData>
typename list<TData>::const_iterator list<TData>::end_consitr(){
    
    list::const_iterator* itr = new list::const_iterator(pEndNode);
    return *itr;
    }
//-----------------------------------------------------------------------------
// TODO ... (template<class TData> inline list<TData>::...)
//      et  (template<class TData> list<TData>::...)
template<class TData>
list<TData>::~list(){
    while (nodeCount != 0) {
        erase(begin());
    }
}
template<class TData>
list<TData>::list(){
     this->nodeCount= 0;
     this->pEndNode = _CreateHeaderNode();
}

template<class TData>
list<TData>::list(list& listNode){
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


template<class TData>
 void list<TData>::insert(iterator itrNextelement, TData& value) {
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




//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------

#endif /*LIST_H_*/
