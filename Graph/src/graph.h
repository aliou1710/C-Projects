#ifndef GRAPH_H_
#define GRAPH_H_
//---------------------------------------------------------------------------
const double INFINITY = 1000;
//10e100
//---------------------------------------------------------------------------
class TGraph;
//-----------------------------moi----------------------------------------------
class TDest {
	//TODO
   //but final c'est d'avoir le crochet de matrix et le crochet de row
public:
        //là on cree un operateur pour retourner le tableau correspond  à cette ligne.cad une classe qui represente une rangé
	
    int& operator[](int i);
    
	const int& operator[](int i) const;  
	private:
		inline TDest() :
			pValues(0) {
		}
		inline ~TDest() {
			delete[] pValues;
		}
        
		int* pValues;
		friend class TGraph;
        
};
//---------------------------moi------------------------------------------------
class TGraph {
public:
	//TODO
    TGraph(int dim);
    int Dim() const;
    ~TGraph();
    TDest& operator[](int i);
    
	const TDest& operator[](int i) const;  
    

    void allocateGraph(); 
    TGraph& Zero();
    
private:
//---------------prof---------------------------------------------
	int dim; //nombre de sommets
	TDest* ppDest;//poiteur vers un tableau de sommets.

};
//------------------------------prof---------------------------------------------
//TPath permet de mémoriser un chemin, c’est-à-dire une suite de sommets. pNodes est un pointeur vers un tableau de length max entiers. Dans ce tableau les length premiers éléments correspondent au chemin mémorisé.
class TPath {
public:
	TPath(int _lengthMax);
	TPath(const TPath& _path);
	~TPath();
	TPath& operator=(const TPath& _path);
	int LengthMax() const;
	int Length() const;
	void Erase();
	bool Add(int _s);
	bool Remove();
	int Last() const;
	int& operator[](int _i);
	const int& operator[](int _i) const;
    
    void Reinitialize(int _s);
    
private:
	
	int lengthMax;
	int length;
     int* pNodes;
};
//---------------------------------------------------------------------------
bool ComputeShortestPath(const TGraph& _graph, int _start, int _end, TPath& _path,
		double& _length);
//---------------------------------------------------------------------------
#endif /*GRAPH_H_*/
