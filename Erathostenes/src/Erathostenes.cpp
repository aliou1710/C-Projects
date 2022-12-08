//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <math.h>
#include "inout.h"
#include <stdio.h>
#include <stdlib.h>

//-------------------

//--------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const int MAX = 2147483647; // (2^31-1)
//1111111111111111111111111111111

/* typedef short int bool; */

#define false 0
#define true 1

typedef unsigned int uint32;
#define setbitarray(pba, i) (pba[i >> 5] |= (0x00000001 << (i & 0x0000001F)))
#define unsetbitarray(pba, i) (pba[i >> 5] &= ~(0x00000001 << (i & 0x0000001F)))
#define issetbitarray(pba, i) (pba[i >> 5] & (0x00000001 << (i & 0x0000001F)))


struct TListPrimes {
    int maximum;
    int* pPrimes;
    int cPrimes;
};

//---------------------------------------------------------------------------
//  ...

void InitializeTListPrimes( TListPrimes& list){

	list.maximum = 0 ;
	/*cprimes est un entier, et correspond au nombre de nombre premier qu'on aura */
	list.cPrimes=0;
	/* pPrimes est un tableau  pPrimes est un pointeut , on peut le mettre à null contrairement à une reference*/
	list.pPrimes=NULL;
	
	}
	

void Erathostenes(TListPrimes& listPrimes){
	//LOGIQUE INVERSE
		
	uint32* ui;
        int max;
        int i;
        int j;
        
        int count = 1;
        max = (listPrimes).maximum;
        ui = new uint32[((max-1)/32)+1]();
        //   Tout les éléments mis à 0. divisé par 32 car on ne touche qu'au bit (codé sur 32 bit)
        setbitarray(ui,0);
        setbitarray(ui,1);                              
        int racine = (int)sqrt(max);
        if(max >= 2)
        {
        i=2;
        (listPrimes).cPrimes++;
        for (j=i*i; j <= max && j>0; j += i)              
        //On met à 0 tous les bits correspondant au multiple de 2  
        {
            setbitarray(ui, j);
        }
        //pour tous les nombres impaire, on met le bit correspondant à leurs multiples à 0
        for (i=3; i <= racine; i+=2)  {
            if(!issetbitarray(ui, i))                   
            //si le chiffre est considéré premier et donc qu'il n'est pas mis à 1 (d'ou le ! pour dire qu'il n'est pas set à 1) 
            {
                for (j=i*i; j <= max && j>0; j += i*2)  {
                    setbitarray(ui, j);                 
                    }
            }
        }
        //quand i vaut MAX et que l'on fait i+2 ça donne une val négative (cyclique) et ça provoque une erreur
   
        for( i=3; i <= max && i>0; i+=2) {
            if(!issetbitarray(ui, i))
            {
                //on incrémente le compte pour chaque nombres premier 
                (listPrimes).cPrimes++;                  
            }

        }
        
       //Je créé une liste dont la taille correspond au nombre de  nombres premier 
        (listPrimes).pPrimes = new int[listPrimes.cPrimes]; 
        (listPrimes).pPrimes[0] = 2;                        
        for(i=3; i <= max && i>0; i+=2)
        {
            if(!issetbitarray(ui, i))
            {
            (listPrimes).pPrimes[count] = i; 
            count++;
            }
        }
        }
            
        delete[] ui;
	
}	
  


void ShowPrimes(TListPrimes& listPrime){
	int i;
	
	cout<<"Il y a "<<listPrime.cPrimes<<" nombre premiers inferieurs à "<<listPrime.maximum<<": "<<endl;
		
		
		if(listPrime.cPrimes <= 20){
			for( i =0 ; i< listPrime.cPrimes ;i++){
		
			
				cout<<"	Nombre premier n     "<<(i+1)<<" :    "<<listPrime.pPrimes[i]<<"  "<<endl;
		
			}
		
		
		}else if(listPrime.cPrimes > 20){
			
			for( i =0 ; i< 10 ;i++){
				cout<<"	Nombre premier n     "<<(i+1)<<" :    "<<listPrime.pPrimes[i+1]<<"  "<<endl;
			}
			printf("...\n");
			for( i =listPrime.cPrimes-10 ; i< listPrime.cPrimes ;i++){
		
			
				cout<<"	Nombre premier n     "<<(i+1)<<" :    "<<listPrime.pPrimes[i]<<"  "<<endl;

			}
			
			}
	}
	

void DestroyTListPrimes(TListPrimes& listPrime){
	if (listPrime.pPrimes != NULL){
		delete[] listPrime.pPrimes;
        
		
    listPrime.maximum = 0 ;
	listPrime.cPrimes=0;
	}
	
	}	
//---------------------------------------------------------------------------



        
int main(int argc, char* argv[]) {
    
  
    clock_t ct1, ct2;
    TListPrimes listPrimes;
    do {
        InitializeTListPrimes(listPrimes);
        listPrimes.maximum = ReadInt("\nVotre naturel maximum ? ", 0, MAX);
        ct1 = clock();
        Erathostenes(listPrimes);
        ct2 = clock();
        cout << "Duree calculs : " << setprecision(4) << ((double)(ct2 - ct1) / CLOCKS_PER_SEC) << endl;
        ShowPrimes(listPrimes);
        DestroyTListPrimes(listPrimes);
    } while(!Stop());
    return 0;
    
}

//---------------------------------------------------------------------------
// ...
//---------------------------------------------------------------------------

