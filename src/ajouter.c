#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ajouter.h"
#include <gtk/gtk.h>
#include <string.h> 

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

enum 
{
MARQUE,
PRIX,
COLUMNS, 
COULEUR, 
CARBURANT,
MATRICULE,
CHEVEAUX
}; 

/*---------------------------------Familiales----------------------------------------------------*/
void ajouterlocation(loc l) 
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix);
}
fclose(f);
}

void afficherlocation(GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

loc l ;

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Marque",render,"text",MARQUE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Couleur",render,"text",COULEUR,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Carburant",render,"text",CARBURANT,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Matricule",render,"text",MATRICULE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Cheveaux",render,"text",CHEVEAUX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt","a+") ;
 while(fscanf(f,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,MARQUE,l.marque,COULEUR,l.couleur,CARBURANT,l.carburant,MATRICULE,l.matricule,CHEVEAUX,l.cheveaux,PRIX,l.prix,-1) ; 
}
fclose(f) ; 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}
}

int verifierdest (char marque[][50]) 
{
char marque1[50]; 
char prix1[50]; 
loc l ; 
int c=0 ; 


FILE *f ; 
f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s \n",marque1,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF)
{

strcpy(marque[c],marque1) ; 
c++ ;
} 
}

fclose(f); 
return c ; 

}


void afficherresevloc (reserv rl)
{
FILE *f;
FILE *f1;
char marque1[50]; 
char couleur[50];  
char carburant[50]; 
char matricule[50]; 
char cheveaux[50]; 
int prix1; 
loc l; 

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt","r");
f1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/clientlocfamiliale.txt","a+");
if(f!=NULL)
{  if(f1!=NULL)
   {
         while(fscanf(f,"%s %s %s %s %s %d \n",marque1,couleur,carburant,matricule,cheveaux,&prix1)!=EOF) 
         { 
                 if (strcmp(rl.marque,marque1)==0) 
       			{ 
           rl.prix=prix1*rl.nbj ; 
          fprintf(f1,"%s %s %s %s %s %s %s %d %d \n",rl.cin,rl.marque,rl.date,couleur,carburant,matricule,cheveaux,rl.nbj,rl.prix);
                        }
         }
    }

fclose(f1);
    }
fclose(f) ;
} 



void supprimerlocation(char marque[]) 
{
FILE *f_h;
FILE *f_h1;
loc l ; 
int r;
int n;
f_h=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt","r");
f_h1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/familiales1.txt","w");
if (f_h!=NULL){
    if(f_h1!=NULL){
while(fscanf(f_h,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF ) {
    if(strcmp(marque,l.marque)!=0){
        fprintf(f_h1,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix);
        r=1;
    }
}
    }
    fclose(f_h1);
}

fclose(f_h);
if (r){
	remove ("/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt");
	rename ("/home/ggmghoul/Desktop/projetlocation/location/src/familiales1.txt","/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt");
	}
}



void modifierlocation(char marque[] ,char newprix[]){
int n=0;
loc l ;




FILE *f_h;
FILE *f_h1;
 
int r;

f_h=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt","r");
f_h1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/familiales1.txt","w");
if (f_h!=NULL)
{
    if(f_h1!=NULL)
     {
while(fscanf(f_h,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF ) 
{
    if(strcmp(marque,l.marque)==0)
            {
        fprintf(f_h1,"%s %s %s %s %s %s \n",marque,l.couleur,l.carburant,l.matricule,l.cheveaux,newprix);
            }
     else 
          {fprintf(f_h1,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix);} 
}
}
}
fclose(f_h1);
fclose(f_h);

	remove ("/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt");
	rename ("/home/ggmghoul/Desktop/projetlocation/location/src/familiales1.txt","/home/ggmghoul/Desktop/projetlocation/location/src/familiales.txt");
	
}


/*---------------------------------------4x4-----------------------------------------------------------*/




void ajouterlocation4(loc l) 
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix);
}
fclose(f);
}

void afficherlocation4(GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

loc l ;

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Marque",render,"text",MARQUE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Couleur",render,"text",COULEUR,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Carburant",render,"text",CARBURANT,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Matricule",render,"text",MATRICULE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Cheveaux",render,"text",CHEVEAUX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt","a+") ;
 while(fscanf(f,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,MARQUE,l.marque,COULEUR,l.couleur,CARBURANT,l.carburant,MATRICULE,l.matricule,CHEVEAUX,l.cheveaux,PRIX,l.prix,-1) ; 
}
fclose(f) ; 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}
}

int verifierdest4 (char marque[][50]) 
{
char marque1[50]; 
char prix1[50]; 
loc l ; 

int c=0 ; 


FILE *f ; 
f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s \n",marque1,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF)
{

strcpy(marque[c],marque1) ; 
c++ ;
} 
}

fclose(f); 
return c ; 

}


void afficherresevloc4 (reserv rl)
{
FILE *f;
FILE *f1;
char marque1[50]; 
char couleur[50];  
char carburant[50]; 
char matricule[50]; 
char cheveaux[50]; 
int prix1; 
loc l; 

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt","r");
f1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/clientloc4x4.txt","a+");
if(f!=NULL)
{  if(f1!=NULL)
   {
         while(fscanf(f,"%s %s %s %s %s %d \n",marque1,couleur,carburant,matricule,cheveaux,&prix1)!=EOF) 
         { 
                 if (strcmp(rl.marque,marque1)==0) 
       			{ 
           rl.prix=prix1*rl.nbj ; 
          fprintf(f1,"%s %s %s %s %s %s %s %d %d \n",rl.cin,rl.marque,rl.date,couleur,carburant,matricule,cheveaux,rl.nbj,rl.prix);
                        }
         }
    }

fclose(f1);
    }
fclose(f) ;
} 



void supprimerlocation4(char marque[]) 
{
FILE *f_h;
FILE *f_h1;
loc l ; 
int r;
int n;
f_h=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt","r");
f_h1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/4x41.txt","w");
if (f_h!=NULL){
    if(f_h1!=NULL){
while(fscanf(f_h,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF ) {
    if(strcmp(marque,l.marque)!=0){
        fprintf(f_h1,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix);
        r=1;
    }
}
    }
    fclose(f_h1);
}

fclose(f_h);
if (r){
	remove ("/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt");
	rename ("/home/ggmghoul/Desktop/projetlocation/location/src/4x41.txt","/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt");
	}
}



void modifierlocation4(char marque[] ,char newprix[]){
int n=0;
loc l ;




FILE *f_h;
FILE *f_h1;
 
int r;

f_h=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt","r");
f_h1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/4x41.txt","w");
if (f_h!=NULL)
{
    if(f_h1!=NULL)
     {
while(fscanf(f_h,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF ) 
{
    if(strcmp(marque,l.marque)==0)
            {
        fprintf(f_h1,"%s %s %s %s %s %s \n",marque,l.couleur,l.carburant,l.matricule,l.cheveaux,newprix);
            }
     else 
          {fprintf(f_h1,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix);} 
}
}
}
fclose(f_h1);
fclose(f_h);

	remove ("/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt");
	rename ("/home/ggmghoul/Desktop/projetlocation/location/src/4x41.txt","/home/ggmghoul/Desktop/projetlocation/location/src/4x4.txt");
	
}

/*----------------------------------------Commerciales------------------------------------------*/



void ajouterlocationcom(loc l) 
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix);
}
fclose(f);
}

void afficherlocationcom(GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

loc l ;

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Marque",render,"text",MARQUE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Couleur",render,"text",COULEUR,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Carburant",render,"text",CARBURANT,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Matricule",render,"text",MATRICULE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Cheveaux",render,"text",CHEVEAUX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt","a+") ;
 while(fscanf(f,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,MARQUE,l.marque,COULEUR,l.couleur,CARBURANT,l.carburant,MATRICULE,l.matricule,CHEVEAUX,l.cheveaux,PRIX,l.prix,-1) ; 
}
fclose(f) ; 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}
}

int verifierdestcom (char marque[][50]) 
{
char marque1[50]; 
char prix1[50]; 
loc l ; 

int c=0 ; 


FILE *f ; 
f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s \n",marque1,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF)
{

strcpy(marque[c],marque1) ; 
c++ ;
} 
}

fclose(f); 
return c ; 

}


void afficherresevloccom (reserv rl)
{
FILE *f;
FILE *f1;
char marque1[50]; 
char couleur[50];  
char carburant[50]; 
char matricule[50]; 
char cheveaux[50]; 
int prix1; 
loc l; 

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt","r");
f1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/clientloccom.txt","a+");
if(f!=NULL)
{  if(f1!=NULL)
   {
         while(fscanf(f,"%s %s %s %s %s %d \n",marque1,couleur,carburant,matricule,cheveaux,&prix1)!=EOF) 
         { 
                 if (strcmp(rl.marque,marque1)==0) 
       			{ 
           rl.prix=prix1*rl.nbj ; 
          fprintf(f1,"%s %s %s %s %s %s %s %d %d \n",rl.cin,rl.marque,rl.date,couleur,carburant,matricule,cheveaux,rl.nbj,rl.prix);
                        }
         }
    }

fclose(f1);
    }
fclose(f) ;
} 



void supprimerlocationcom(char marque[]) 
{
FILE *f_h;
FILE *f_h1;
loc l ; 
int r;
int n;
f_h=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt","r");
f_h1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales1.txt","w");
if (f_h!=NULL){
    if(f_h1!=NULL){
while(fscanf(f_h,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF ) {
    if(strcmp(marque,l.marque)!=0){
        fprintf(f_h1,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix);
        r=1;
    }
}
    }
    fclose(f_h1);
}

fclose(f_h);
if (r){
	remove ("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt");
	rename ("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales1.txt","/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt");
	}
}



void modifierlocationcom(char marque[] ,char newprix[]){
int n=0;
loc l ;




FILE *f_h;
FILE *f_h1;
 
int r;

f_h=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt","r");
f_h1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales1.txt","w");
if (f_h!=NULL)
{
    if(f_h1!=NULL)
     {
while(fscanf(f_h,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix)!=EOF ) 
{
    if(strcmp(marque,l.marque)==0)
            {
        fprintf(f_h1,"%s %s %s %s %s %s \n",marque,l.couleur,l.carburant,l.matricule,l.cheveaux,newprix);
            }
     else 
          {fprintf(f_h1,"%s %s %s %s %s %s \n",l.marque,l.couleur,l.carburant,l.matricule,l.cheveaux,l.prix);} 
}
}
}
fclose(f_h1);
fclose(f_h);

	remove ("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt");
	rename ("/home/ggmghoul/Desktop/projetlocation/location/src/commerciales1.txt","/home/ggmghoul/Desktop/projetlocation/location/src/commerciales.txt");
	
}

