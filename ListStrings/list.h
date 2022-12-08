//-----------------------------------------------------------------------------
// File list.h
//-----------------------------------------------------------------------------
#ifndef LIST_H_
#define LIST_H_
//-----------------------------------------------------------------------------
#include <string>
using std::string ;
//-----------------------------------------------------------------------------
// Pour list, il faut dans TData : copy constructor, operator =, destructor
// Pour bubbleSort, il faut dans TData : <
// Pour find, il faut dans TData : ==
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
namespace StructInfoList {
//-----------------------------------------------------------------------------
class list {

    public:
        typedef string value_type;
        
    
protected:
	//-------------------------------------------------------------------------
	
    struct TNode {
        ////node a trois element: les deux pointeurs pNext et pPrevious et la data en string.
        TNode* pPrevious;
        TNode* pNext;
        value_type value;
       
        //destructeur 
        ~TNode();
        //constructeur
        TNode(TNode& copyNode);
        TNode();
        	
	};
	//-------------------------------------------------------------------------
public:
	//-------------------------------------------------------------------------
	class const_iterator;
	class iterator {
	public:
	  // TODO ...
      //destructeur 
      
      ~iterator();
      //constructeur 
      iterator(TNode* node);
      iterator(const iterator& itr);
      iterator();
      //operateur 
      bool operator==(iterator itr); //equals
      bool operator!=(iterator itr); //differents
      iterator operator++(); //iterator suivant
      iterator operator--();//iterator precedent
      value_type& operator*(); //iterator pour recuperer la valeur de l'objet
      
   
      
      
      
      
	protected:
		// TODO ...
          TNode* itrNode;
          
        friend class list;
      
	};

	class const_iterator {
	public:
        //destructeur
       
        ~const_iterator();
        //constructeur
         const_iterator();
        const_iterator(TNode* node);
        const_iterator(const const_iterator& const_itr);
        const_iterator(const iterator& const_itr);
        const_iterator operator--();
        const_iterator operator++();
        //operateur
        bool operator==(const_iterator const_itr) const;//equals
        bool operator!=(const_iterator const_itr) const;//differents
        value_type& operator*() const;
        
         
	protected:
		// TODO ...
       TNode* const_Node;
        friend class list;
	};

	// TODO ... (typedefs)
    
    
	//-------------------------------------------------------------------------
	// TODO ...
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
    void insert(iterator& itrNextelement, value_type& value);//insert next to itrNextelement
    iterator insert(iterator nextelement, iterator itr_begin,iterator itr_end); // ajouter une sequence de node
    int size() const ;
    bool IsEmptyList(list& listnode);
    int nodeCountmethod() const;
   
    //operator
  //  list& operator=(list& listNode);
    
    
protected:
	//-------------------------------------------------------------------------
   // TNode* _begin;//pointe vers le noeud garde fou (dernier element vide)
   // TNode* _end;
    TNode* pEndNode;
    int nodeCount;//nbre d'element de la chaine 
	//-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------
#endif /*LIST_H_*/
