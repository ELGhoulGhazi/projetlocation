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
COLUMNS
}; 


void ajouterlocation(loc l) 
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/location.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s \n",l.marque,l.prix);
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
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/location.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/location.txt","a+") ;
 while(fscanf(f," %s %s \n" ,l.marque,l.prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,MARQUE,l.marque,PRIX,l.prix,-1) ; 
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

int c=0 ; 


FILE *f ; 
f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/location.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s \n",marque1,prix1)!=EOF)
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
int prix1; 

f=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/location.txt","r");
if(f!=NULL)
{while(fscanf(f," %s %d \n" ,marque1,&prix1)!=EOF) 
  { if (strcmp(rl.marque,marque1)==0) 
       { 
         rl.prix=(prix1*(rl.jj-rl.jd)) ; 
f1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/clietnlocation.txt","a+");
if(f!=NULL)
{fprintf(f1,"%s %s %d/%d/%d %d/%d/%d %d \n",rl.cin,rl.marque,rl.jd,rl.md,rl.ad,rl.jj,rl.mj,rl.aj,rl.prix);
}
fclose(f);
       }
  }
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
f_h=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/location.txt","r");
f_h1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/location1.txt","w");
if (f_h!=NULL){
    if(f_h1!=NULL){
while(fscanf(f_h,"%s %s ",l.marque,l.prix)!=EOF ) {
    if(strcmp(marque,l.marque)!=0){
        fprintf(f_h1,"%s %s \n",l.marque,l.prix);
        r=1;
    }
}
    }
    fclose(f_h1);
}

fclose(f_h);
if (r){
	remove ("/home/ggmghoul/Desktop/projetlocation/location/src/location.txt");
	rename ("/home/ggmghoul/Desktop/projetlocation/location/src/location1.txt","/home/ggmghoul/Desktop/projetlocation/location/src/location.txt");
	}
}



void modifierlocation(char marque[] ,char newprix[]){
int n=0;
loc l ;




FILE *f_h;
FILE *f_h1;
 
int r;

f_h=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/location.txt","r");
f_h1=fopen("/home/ggmghoul/Desktop/projetlocation/location/src/location1.txt","w");
if (f_h!=NULL)
{
    if(f_h1!=NULL)
     {
while(fscanf(f_h,"%s %s ",l.marque,l.prix)!=EOF ) 
{
    if(strcmp(marque,l.marque)==0)
            {
        fprintf(f_h1,"%s %s \n",marque,newprix);
            }
     else 
          {fprintf(f_h1,"%s %s \n",l.marque,l.prix);} 
}
}
}
fclose(f_h1);
fclose(f_h);

	remove ("/home/ggmghoul/Desktop/projetlocation/location/src/location.txt");
	rename ("/home/ggmghoul/Desktop/projetlocation/location/src/location1.txt","/home/ggmghoul/Desktop/projetlocation/location/src/location.txt");
	
}

