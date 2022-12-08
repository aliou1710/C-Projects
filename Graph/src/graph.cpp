//---------------------------------------------------------------------------
#include "graph.h"
#include "stack"
#include "iostream"
#include "list"

//---------------------------------------------------------------------------
using namespace std;

//---------------------------------------------------------------------------
class TWork {

  public: 
    TWork(const TGraph& _graph, int _begin, int _end, TPath& _path,double& _length);
    void DoWork();
    
  private:
	// TODO
    
	friend bool ComputeShortestPath(const TGraph& _graph, int _begin, int _end,
			TPath& _path, double& _length);
   	int bestLength;
    
    
    
	
};
//---------------------------------------------------------------------------
// TODO definitions for TDest

int& TDest::operator[](int i) {
	return pValues[i];
}

const int& TDest::operator[](int i) const {
	return pValues[i];
}

//---------------------------------------------------------------------------

int tintArray=0;
// TODO definitions for TGraph

void TGraph::allocateGraph() /* throw (BadSize) */ {
	
		if (dim != 0) {
			try {
				ppDest = new TDest[dim]; //tableu de TDest
				for (int l = 0; l < dim; ++l){ 
                //attention 
					ppDest[l].pValues = new int[dim];    // tableau de int
                    for (int c = 0; c < dim; ++c){
                        if(l==c){
                            ppDest[l].pValues[c] = 0;
                        }else{
                            ppDest[l].pValues[c] = INFINITY;
                        }
					}
				
				}
			} catch (...) {
				delete[] ppDest;
				
				ppDest = 0;
				throw;
			}
		}
	
}


TGraph::~TGraph() {
	delete[] ppDest;
}


TGraph::TGraph(int dim){
    this->dim = dim;
    tintArray = dim;
    allocateGraph();
    }
TDest& TGraph::operator[](int i) {
	return ppDest[i];
}

const TDest& TGraph::operator[](int i) const {
	return ppDest[i];
}

int TGraph::Dim() const {
	return dim;
}





//---------------------------------------------------------------------------
// TODO definitions for TPath
TPath::~TPath() {
	delete[] pNodes;
}
//_lengthMax: la taille maximum du chemin,
//length : nombre de noeud pour atteindre le noeud final
TPath::TPath(int _lengthMax){
    pNodes= new int[_lengthMax];
    cout<<"size pNodes"<< _lengthMax<<endl;
    this->length=0;
    this->lengthMax = _lengthMax;
    
    
    }
    
    
TPath::TPath(const TPath& _path){
        

    }
	

	int TPath::LengthMax() const{
        return lengthMax ;
        }
        
	int TPath::Length() const{
        return length;
        }
    
        
        
	void TPath::Erase(){
        delete[] pNodes;
        }
        
        
        
	bool TPath::Add(int _s){
        
        
        length+=1;
        cout<<"Taille legth:  "<<length<<endl;
        pNodes[length-1]=_s;
        return true;
     
    }
    void TPath::Reinitialize(int _s){
        this->length =_s;
        }
        
	bool TPath::Remove(){
         length-=1;
         
        return false;
        }
        
        
	int TPath::Last() const{
        
        
        return pNodes[lengthMax-1];
        }
	int& TPath::operator[](int _i){
        return pNodes[_i];
        }
	const int& TPath::operator[](int _i) const{
        
        return pNodes[_i];
        }
 

//---------------------------------------------------------------------------
// TODO definitions for TWork
//---------------------------------------------------------------------------



bool ComputeShortestPath(const TGraph& _graph, int _begin, int _end, TPath& _path,
                         double& _length) {
	if (_begin >= _graph.Dim() || _end >= _graph.Dim() || _path.LengthMax()
	        < _graph.Dim())
		return false;
	TWork t(_graph, _begin, _end, _path, _length);
	t.DoWork();
	_length = t.bestLength;
  
	if (_length < INFINITY)
		return true;
	else
		return false;
}
//------------------------------moi---------------------------------------------



int lengthPathCalcul(list<int> listcheckoutLength,int beginNode,const TGraph& _graph){
    
  int preced_value = beginNode;
  int longueur_chemin =0;
                
                  //on commence avec i = 1 comme on sait que la valeur qui correspond à la meme indice en colonne et en ligne =0 dans le graph   
  for(int i =1 ; i<listcheckoutLength.size();i++){
      
      //recupere la valeur de l'element à l'indice i
      auto l_front = listcheckoutLength.begin();   
      std::advance(l_front, i);
     
      int z =*l_front;
      //incrementation
      longueur_chemin+=  _graph[preced_value][z];
       preced_value= z;
                    
 }
  return longueur_chemin;  
}


//Global variable
//je cree une paire de liste pour stocker chaque valeur et le chemin parcouru
std::stack<pair<list<int>, int>> integer_stack;
bool *tarray;
list<int> listcheckoutLength;
int endvalue;
int beginvalue;



void TWork::DoWork(){}
void DFS(const TGraph& _graph,int bestLength){
  
      //je cree une paire  temporaire 
      pair<list<int>, int> tmp=  integer_stack.top();//on recupere la derniere paire d'elements du stack (qui est le Top)
      //top element in the stack (warning: the top element is the last element added in stack)
      int v = tmp.second;
      integer_stack.pop(); // remove the top element
      
      
      
      bool find= tarray[v];
      if(find==false){
      //si la valeur v correspond au sommet _end, 
         tarray[v] =true;
         if(v == endvalue){
              
             
              if(!listcheckoutLength.empty()){
                  
                  //on compare la longueur du chemin actuel à la longueur du chemin se trouvant dans la list listcheckoutLength
                  int precedLengthPath=lengthPathCalcul(listcheckoutLength,beginvalue,_graph);
                  int actuLengthPath = lengthPathCalcul(tmp.first,beginvalue,_graph);
                  //on verifie: est ce qu'il y a une liste qui a une taille < à taille de la liste stocké dans listcheckoutLength
                  if(actuLengthPath < precedLengthPath){
                         //on fait un copy constructeur
                         listcheckoutLength = list (tmp.first);
                         bestLength= actuLengthPath;
                      
                      } 
              }else{
                      
                      
                      listcheckoutLength = list (tmp.first);
                     
                      }
                //la valeur du end dans le tableau booleen  est mis  à false
                tarray[endvalue]=false;
            }else{
                
                
          
                 // on ajoute tous les somments suivants de v dans le stack
                 for(int j =0 ; j < _graph.Dim(); ++j){
             
                    if(v!= j && _graph[v][j] != INFINITY ){ //if value of array !=0 or value of array!=INFINITY 
                        //copie de la liste
                        list<int>tmpCopie = list (tmp.first);
                        //on ajoute l'element j dans la liste
                        tmpCopie.push_back(j);
                        pair<list<int>, int> tmp2(tmpCopie,j) ;
                       // on ajoute cette paire dans le stack
                        integer_stack.push(tmp2);
                    }
                }
        
        }
            
      }
        tmp.first.clear();
        
    if(!integer_stack.empty()){
        DFS(_graph,bestLength);
    }else{
        return;
        }
}
TWork::TWork(const TGraph& _graph, int _begin, int _end, TPath& _path,double& _length){
    _path.Reinitialize(0);
    bestLength = 0 ;
    
    
    beginvalue = _begin;
    endvalue = _end;
    
    
    list<int> lists ={_begin};
    
    
    
    //initialisation des Parametre du DFS
    integer_stack.push(pair(lists,_begin));//push the start node in stack and also the list that contain this node
    
    
    
   // _length a été initialisé à 0 dans le constructeur de TWork donc _path.Lengtht() =0 pour l'instant
    _path[_path.Length()]=_begin;//put begin node in path array (pNodes) 
  
    
    tarray= new bool[_graph.Dim()];//create array for checking if node has been visited
    for(int i =0 ; i<_graph.Dim();i++){
        tarray[i]=false;
    }
   
    
    
    
    //DFS
    DFS(_graph,bestLength);
    
   
    
    
    //*********INSERT to _path (pNodes)***********
    
    //si cette liste qui contient le chemin le plus court n'est pas vide
    if(!listcheckoutLength.empty()){
       bestLength= listcheckoutLength.size();
       //insérer les elements dans le path 
       for(int n=0 ; n< listcheckoutLength.size();n++){
                  //auto
                     auto l_front = listcheckoutLength.begin();   
                     std::advance(l_front, n);
                     cout<<"->"<< *l_front << endl;
                    
                    int z =*l_front;
                    //on ajoute l'element dans le path
                    _path.Add(z);
        }
    }else{
        bestLength=INFINITY;
        }
        
        
       listcheckoutLength.clear();
       delete [] tarray;
       lists.clear();
       for(int n=0 ; n< integer_stack.size();n++){
            integer_stack.pop();
        }
        
            
            
}
