#include <gtk/gtk.h>

typedef struct 
{
char marque[50] ;
char couleur[2000]; 
char carburant[2000]; 
char matricule[2000]; 
char cheveaux[2000]; 
char prix[200];  
}loc ; 

typedef struct 
{
char marque[50] ; 
char date[50] ;
char cin[50];
int nbj ;
int prix; 
}reserv; 


void ajouterlocation (loc l) ;
void afficherlocation(GtkTreeView *liste) ; 
int verifierdest (char marque[][50]) ;
void afficherresevloc (reserv rl); 
void supprimerlocation(char marque[]) ; 
void modifierlocation(char marque[] ,char newprix[]);

void ajouterlocation4 (loc l) ;
void afficherlocation4(GtkTreeView *liste) ;
int verifierdest4 (char marque[][50]) ;
void afficherresevloc4 (reserv rl);  
void supprimerlocation4(char marque[]) ; 
void modifierlocation4(char marque[] ,char newprix[]);

void ajouterlocationcom (loc l) ;
void afficherlocationcom(GtkTreeView *liste) ; 
int verifierdestcom (char marque[][50]) ;
void afficherresevloccom (reserv rl); 
void supprimerlocationcom(char marque[]) ; 
void modifierlocationcom(char marque[] ,char newprix[]);



