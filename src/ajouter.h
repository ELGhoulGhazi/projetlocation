#include <gtk/gtk.h>

typedef struct 
{
char marque[50] ;
char prix[50];  
}loc ; 

typedef struct 
{
char marque[50] ; 
int jd ;
int md ;
int ad ;
int jj ;
int mj ;
int aj ;
char cin[50]; 
int prix; 
}reserv; 


void ajouterlocation (loc l) ;
void afficherlocation(GtkTreeView *liste) ; 
int verifierdest (char marque[][50]) ;
void afficherresevloc (reserv rl); 
void supprimerlocation(char marque[]) ; 
void modifierlocation(char marque[] ,char newprix[]);
