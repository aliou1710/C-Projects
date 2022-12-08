//---------------------------------------------------------------------------
// file ListTemplateTest.cpp
//---------------------------------------------------------------------------
#include <cstring>
#include <iostream>
#include <iomanip>
#include "list.h"
#include "inout.h"
#include "algo.h"

//-----------------------------------------------------------------------------
const int LONG_MAX_NAME = 80;
//---------------------------------------------------------------------------
// ... Definition de la classe LenEqual

class LenEqual  {
   
private:
         int lenghtstring;  
         
public:
      int lengthlist=0;
     
      bool operator()(const std::string& name) const;  
      LenEqual(int lenght); 

};
//---------------------------------------------------------------------------
struct TTest1 {
	TTest1(int _a =0, int _b=0) :
		a(_a), b(_b) {
	}
	int a;
	int b;
};
//---------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ws;
using std::setw;
using std::left;
using std::string;
using namespace StructInfoList;
using namespace StructInfoAlgo;
//---------------------------------------------------------------------------
void Erreur();
char Menu();
void AfficherListes(const list<string>& l1,
                    const list<string>* pl2,
                    list<string>::const_iterator i1,  // !!!
                    list<string>::const_iterator i2,  // !!!
                    list<string>::const_iterator i3); // !!!
// ... Declaration des fonctions LenCompare et LexicoCompare
int LenCompare(const string& valuestring1,const string& valuestring2);
int LexicoCompare(const string& valuestring1,const string& valuestring2);
//---------------------------------------------------------------------------
int main()
{
    char choix;
    list<string> l1;
    list<string>* pl2 = NULL;
    list<string>::iterator i1(l1.begin()), i2(l1.end()), i3;
    list<string>::value_type e1; // !!!

    //---------------------------------------------------------------------------
    // !!!
    list<TTest1> lt1;
    list<TTest1>::value_type vt1(1, 2);
    list<TTest1>::reference rt1(vt1);
    cout << "rt1.a : " << rt1.a << " rt1.b : " << rt1.b << endl;
    list<TTest1>::const_reference crt1(vt1);
    cout << "crt1.a : " << crt1.a << " crt1.b : " << crt1.b << endl;
    lt1.insert(lt1.begin(), vt1);
    list<TTest1>::const_iterator cit = lt1.begin();
    cout << "a : " << cit->a << " b : " << cit->b << endl;
    //---------------------------------------------------------------------------

    while((choix = Menu()) != '0') {
        switch(choix) {
        case '1':
            ShowTitle("Definition de la position p1 dans liste1", '-');
            cout << "Nom ? ";
            cin >> ws >> e1;
            i1 = find(l1.begin(), l1.end(), e1);
            break;
        case '2':
            ShowTitle("Definition de la position p2 dans liste1", '-');
            cout << "Nom ? ";
            cin >> ws >> e1;
            i2 = find(i1, l1.end(), e1);
            break;
        case '3':
            ShowTitle("Insertion d'un nom devant la position p2 dans liste1", '-');
            cout << "Nom ? ";
            cin >> ws >> e1;
            l1.insert(i2, e1);
            break;
        case '4':
            ShowTitle("Inversion des elements de p1 et p2 dans liste1", '-');
            reverse(i1, i2);
            i1 = l1.begin();
            break;
        case '5':
            ShowTitle("Suppression de l'element a la position p1 dans liste1", '-');
            if(i1 == i2)
                i2 = l1.end();
            if(i1 != l1.end())
                i1 = l1.erase(i1); // !!!
            // i1=l1.begin();
            break;
        case '6':
            ShowTitle("Suppression des elements de p1 a p2 dans liste1", '-');
            if(i1 != l1.end())
                i1 = l1.erase(i1, i2); // !!!
            // i1=l1.begin();
            break;
        case '7':
            ShowTitle("Tri alphabetique des elements de p1 a p2 dans liste1", '-');
            bubbelSort(i1, i2, LexicoCompare);
            break;
        case '8':
            ShowTitle("Tri par longueur de nom des elements de p1 a p2 dans liste1", '-');
            bubbelSort(i1, i2, LenCompare);
            break;
        case 'A':
            ShowTitle("Creation de liste2, copie de liste1", '-');
            delete pl2;
            pl2 = new list<string>(l1);
            i3 = pl2->end();
            break;
        case 'B':
            ShowTitle("Destruction de liste2", '-');
            if(pl2 != NULL) {
                delete pl2;
                pl2 = NULL;
            } else
                Erreur();
            break;
        case 'C':
            ShowTitle("Definition de la position p3 dans liste2", '-');
            if(pl2 != NULL) {
                cout << "Nom ? ";
                cin >> ws >> e1;
                i3 = find(pl2->begin(), pl2->end(), e1);
            } else
                Erreur();
            break;
        case 'D':
            ShowTitle("Insertion des elements de p1 a p2 devant p3 dans liste2", '-');
            if(pl2 != NULL)
                pl2->insert(i3, i1, i2);
            else
                Erreur();
            break;
        case 'E':
            ShowTitle("Affectation de liste1 a liste2", '-');
            if(pl2 != NULL) {
                *pl2 = l1;
                i3 = pl2->end();
            } else
                Erreur();
            break;
        case 'F':
            ShowTitle("Insertion des noms de longueur donnee de liste1 devant p3 dans liste2", '-');
            int l = ReadInt("Longueur ? ", 0, LONG_MAX_NAME);
            cout << endl;
            list<string>::iterator i(l1.begin());
            while((i = find_if(i, l1.end(), LenEqual(l))) != l1.end()) {
                pl2->insert(i3, *i);
                ++i;
            }
            break;
        }
        AfficherListes(l1, pl2, i1, i2, i3);
    }
    return 0;
}
//---------------------------------------------------------------------------
char Menu()
{
    cout << left;
    ShowTitle("MENU", '=');
    cout << endl;
    cout << setw(40) << "  <1> Determiner p1";
    cout << setw(39) << "  <2> Determiner p2" << endl;
    cout << setw(40) << "  <3> Inserer devant p2";
    cout << setw(39) << "  <4> Inverser p1 -> p2" << endl;
    cout << setw(40) << "  <5> Supprimer p1";
    cout << setw(39) << "  <6> Supprimer p1 -> p2" << endl;
    cout << setw(40) << "  <7> Trier ordre alphabetique p1 -> p2";
    cout << setw(39) << "  <8> Trier longueurs nom p1 -> p2" << endl;
    cout << endl;
    cout << setw(40) << "  <A> Creer copie liste1";
    cout << setw(39) << "  <B> Detruire liste2" << endl;
    cout << setw(40) << "  <C> Determiner p3";
    cout << setw(39) << "  <D> Inserer p1 -> p2 devant p3" << endl;
    cout << setw(40) << "  <E> Affecter liste1 a liste2";
    cout << setw(39) << "  <F> Inserer noms longueur donnee" << endl;
    cout << endl;
    cout << setw(40) << "  <0> Arreter";
    char c = ReadChar("  Votre Choix ? ", "012345678ABCDEF");
    cout << endl;
    return c;
}

void AfficherListes(const list<string>& l1,
                    const list<string>* pl2,
                    list<string>::const_iterator i1,
                    list<string>::const_iterator i2,
                    list<string>::const_iterator i3)
{
    ShowTitle("Listes", '-');
    list<string>::const_iterator i; // !!!
    cout << "Liste1 (" << setw(3) << l1.size() << " el.)" << endl;
    for(i = l1.begin(); i != l1.end(); ++i) {
        cout << *i;
        if(i == i1)
            cout << "(p1)";
        if(i == i2)
            cout << "(p2)";
        cout << " \t";
    }
    cout << "END";
    if(i == i1)
        cout << "(p1)";
    if(i == i2)
        cout << "(p2)";
    cout << endl;
    if(!pl2)
        cout << "Liste2 INDEFINIE" << endl;
    else {
        cout << "Liste2 (" << setw(3) << pl2->size() << " el.)" << endl;
        for(i = pl2->begin(); i != pl2->end(); ++i) {
            cout << *i;
            if(i == i3)
                cout << "(p3)";
            cout << " \t";
        }
        cout << "END";
        if(i == i3)
            cout << "(p3)";
        cout << endl;
    }
}

void Erreur()
{
    cerr << "Erreur : liste2 non existante" << endl;
}

// ... Definitions des fonctions LenCompare et LexicoCompare
LenEqual::LenEqual(int lenght){
    lenghtstring = lenght;
}
// ... Definitions des fonctions LenCompare et LexicoCompare
bool LenEqual::operator()(const string& name) const {
	if (strlen(name.c_str()) != lenghtstring) {
		return false;
	}
	else{
    return true;
    }
 
}
//strcmp compare chaque caractere  entre valustring1 et valuestring2 et return une valeur final
//exple "zfg" et "gfg" =>il return 19 car (z = 26 lettre alphabet et g =7 ==> 26-7 =19) return une valeur positive cvd z>g les autres sont les mêmes
//a travers ça , on peut savoir trier nos element. donc si lexicoCompare return une valeur negative, cvd valuestring1<valuestring2
int LexicoCompare(const string& valuestring1, const string& valuestring2) {
	return strcmp(valuestring1.c_str(), valuestring2.c_str());
}
//strlen() compare la longueur des deux valeurs c_str() met valuestring sous format tableau pour pouvoir comparer chaque caractere
int LenCompare(const string& valuestring1, const string& valuestring2) {
	 if (strlen(valuestring1.c_str()) > strlen(valuestring2.c_str())) {
		return 1;
	}
    else if(strlen(valuestring1.c_str()) <strlen(valuestring2.c_str())){
        return -1;
        }
	else {return 0;}
}


//---------------------------------------------------------------------------

