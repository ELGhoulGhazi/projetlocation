#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"ajouter.h"


#include <string.h>


void
on_buttonmarque_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *marquecom ;
char marque[50][50]; 
int n=0,i; 
marquecom=lookup_widget(objet_graphique,"comboboxm");

n=verifierdest(marque);
 if (n!=0) 
  {
    for (i=0 ;i<n ;i++)
       {
         gtk_combo_box_append_text (GTK_COMBO_BOX (marquecom),_(marque[i]));
         
       }
  }
}


void
on_buttonreserver_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{



}


void
on_buttonajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"locationEmp");
ajout=create_ajouterloc();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}

char marque[50]; 
void
on_buttonmodifer_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*modif ,*recherche;

recherche=lookup_widget(objet_graphique,"entryrecherche");

emp=lookup_widget(objet_graphique,"locationEmp");
modif=create_Modifierlocation();
gtk_widget_show(modif);
gtk_widget_hide(emp);

strcpy(marque,gtk_entry_get_text(GTK_ENTRY(recherche)));

}


void
on_buttonsupprimer_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

char marque[2000];
GtkWidget *recherche ;

recherche=lookup_widget(objet_graphique,"entryrecherche");


strcpy(marque,gtk_entry_get_text(GTK_ENTRY(recherche)));

supprimerlocation(marque);
}


void
on_buttonvaliderloc_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
loc l ; 
GtkWidget *inputmarque ,*inputcouleur ,*inputcarburant ,*inputmatricule ,*inputcheveau , *inputprix ;
GtkWidget *emp ,*ajout ;

ajout=lookup_widget(objet_graphique,"ajouterloc");
emp=create_locationEmp();
gtk_widget_show(emp);
gtk_widget_hide(ajout); 

inputmarque=lookup_widget(objet_graphique,"entrymarque"); 
inputcouleur=lookup_widget(objet_graphique,"entrycouleurfam"); 
inputcarburant=lookup_widget(objet_graphique,"entrycarfam"); 
inputmatricule=lookup_widget(objet_graphique,"entrymatfam"); 
inputcheveau=lookup_widget(objet_graphique,"entrychfam");
inputprix=lookup_widget(objet_graphique,"entryprix"); 

strcpy(l.marque,gtk_entry_get_text(GTK_ENTRY(inputmarque)));
strcpy(l.couleur,gtk_entry_get_text(GTK_ENTRY(inputcouleur)));
strcpy(l.carburant,gtk_entry_get_text(GTK_ENTRY(inputcarburant)));
strcpy(l.matricule,gtk_entry_get_text(GTK_ENTRY(inputmatricule)));
strcpy(l.cheveaux,gtk_entry_get_text(GTK_ENTRY(inputcheveau)));
strcpy(l.prix,gtk_entry_get_text(GTK_ENTRY(inputprix)));
ajouterlocation(l) ; 



}


void
on_buttonaffichage_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emploc,*treeview;

emploc=lookup_widget(objet_graphique,"locationEmp");



treeview=lookup_widget(emploc,"treeviewloc");
afficherlocation(treeview) ; 
}


void
on_buttonvaliderprix_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

char nouveau[50];
GtkWidget *nprix;
GtkWidget *emp ,*modif ;

modif=lookup_widget(objet_graphique,"Modifierlocation");
emp=create_locationEmp();
gtk_widget_show(emp);
gtk_widget_hide(modif);
nprix=lookup_widget(objet_graphique,"entrynouveauprix");

strcpy(nouveau,gtk_entry_get_text(GTK_ENTRY(nprix)));
modifierlocation(marque,nouveau);
}


/*-------------------------------------------------------1-----------------------------------------*/

void
on_4x4_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*quat ;

emp=lookup_widget(objet_graphique,"Emp");
quat=create_v4x4();
gtk_widget_show(quat);
gtk_widget_hide(emp);
}


void
on_commerciales_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*comm ;

emp=lookup_widget(objet_graphique,"Emp");
comm=create_vcommercial();
gtk_widget_show(comm);
gtk_widget_hide(emp);
}


void
on_voituresfamiliales_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*fami ;

emp=lookup_widget(objet_graphique,"Emp");
fami=create_locationEmp();
gtk_widget_show(fami);
gtk_widget_hide(emp);
}


void
on_buttonretourfamgestion_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*fami ;

fami=lookup_widget(objet_graphique,"locationEmp");
emp=create_Emp();
gtk_widget_show(emp);
gtk_widget_hide(fami);
}


void
on_buttonretourajoutfam_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajout ,*fami ;

ajout=lookup_widget(objet_graphique,"ajouterloc");
fami=create_locationEmp();
gtk_widget_show(fami);
gtk_widget_hide(ajout);
}


void
on_buttonvalidercomm_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
loc l ; 
GtkWidget *inputmarque ,*inputcouleur ,*inputcarburant ,*inputmatricule ,*inputcheveau , *inputprix ;
GtkWidget *emp ,*ajout ;

ajout=lookup_widget(objet_graphique,"ajoutcomm");
emp=create_vcommercial();
gtk_widget_show(emp);
gtk_widget_hide(ajout); 

inputmarque=lookup_widget(objet_graphique,"entrymarquecom"); 
inputcouleur=lookup_widget(objet_graphique,"entrycouleurcom"); 
inputcarburant=lookup_widget(objet_graphique,"entrycarbcom"); 
inputmatricule=lookup_widget(objet_graphique,"entrymatcom"); 
inputcheveau=lookup_widget(objet_graphique,"entrychcom");
inputprix=lookup_widget(objet_graphique,"entryprixcom"); 

strcpy(l.marque,gtk_entry_get_text(GTK_ENTRY(inputmarque)));
strcpy(l.couleur,gtk_entry_get_text(GTK_ENTRY(inputcouleur)));
strcpy(l.carburant,gtk_entry_get_text(GTK_ENTRY(inputcarburant)));
strcpy(l.matricule,gtk_entry_get_text(GTK_ENTRY(inputmatricule)));
strcpy(l.cheveaux,gtk_entry_get_text(GTK_ENTRY(inputcheveau)));
strcpy(l.prix,gtk_entry_get_text(GTK_ENTRY(inputprix)));
ajouterlocationcom(l) ; 
}


void
on_buttonretourtogestioncom_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajout ,*fami ;

ajout=lookup_widget(objet_graphique,"ajoutcomm");
fami=create_vcommercial();
gtk_widget_show(fami);
gtk_widget_hide(ajout);
}


void
on_buttonvalider4x4_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
loc l ; 
GtkWidget *inputmarque ,*inputcouleur ,*inputcarburant ,*inputmatricule ,*inputcheveau , *inputprix ;
GtkWidget *emp ,*ajout ;

ajout=lookup_widget(objet_graphique,"ajout4x4");
emp=create_v4x4();
gtk_widget_show(emp);
gtk_widget_hide(ajout); 

inputmarque=lookup_widget(objet_graphique,"entrymarque4x4"); 
inputcouleur=lookup_widget(objet_graphique,"entrycouleur4x4"); 
inputcarburant=lookup_widget(objet_graphique,"entrycarb4x4"); 
inputmatricule=lookup_widget(objet_graphique,"entrymat4x4"); 
inputcheveau=lookup_widget(objet_graphique,"entrych4x4");
inputprix=lookup_widget(objet_graphique,"entryprix4x4"); 

strcpy(l.marque,gtk_entry_get_text(GTK_ENTRY(inputmarque)));
strcpy(l.couleur,gtk_entry_get_text(GTK_ENTRY(inputcouleur)));
strcpy(l.carburant,gtk_entry_get_text(GTK_ENTRY(inputcarburant)));
strcpy(l.matricule,gtk_entry_get_text(GTK_ENTRY(inputmatricule)));
strcpy(l.cheveaux,gtk_entry_get_text(GTK_ENTRY(inputcheveau)));
strcpy(l.prix,gtk_entry_get_text(GTK_ENTRY(inputprix)));
ajouterlocation4(l) ; 
}


void
on_buttonretourtogestion4x4_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajout ,*fami ;

ajout=lookup_widget(objet_graphique,"ajout4x4");
fami=create_v4x4();
gtk_widget_show(fami);
gtk_widget_hide(ajout);
}





void
on_buttonajout4x4_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"v4x4");
ajout=create_ajout4x4();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}

char marque4x4[50];
void
on_buttonmodif4x4_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *emp ,*modif ,*recherche;

recherche=lookup_widget(objet_graphique,"entry4x4");

emp=lookup_widget(objet_graphique,"v4x4");
modif=create_modif4x4();
gtk_widget_show(modif);
gtk_widget_hide(emp);

strcpy(marque4x4,gtk_entry_get_text(GTK_ENTRY(recherche)));

}

void
on_buttonvaliderprix4x4_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char nouveau[50];
GtkWidget *nprix;
GtkWidget *emp ,*modif ;

modif=lookup_widget(objet_graphique,"modif4x4");
emp=create_v4x4();
gtk_widget_show(emp);
gtk_widget_hide(modif);
nprix=lookup_widget(objet_graphique,"entrynprix4x4");

strcpy(nouveau,gtk_entry_get_text(GTK_ENTRY(nprix)));
modifierlocation4(marque4x4,nouveau);
}

void
on_buttonaff4x4_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emploc,*treeview;

emploc=lookup_widget(objet_graphique,"v4x4");



treeview=lookup_widget(emploc,"treeview4x4");
afficherlocation4(treeview) ; 
}


void
on_buttonretour4x4emp_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"v4x4");
ajout=create_Emp();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonsupp4x4_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
char marque[2000];
GtkWidget *recherche ;

recherche=lookup_widget(objet_graphique,"entry4x4");


strcpy(marque,gtk_entry_get_text(GTK_ENTRY(recherche)));

supprimerlocation4(marque);
}


/*------------------------------------end1-------------------------------------*/


void
on_buttonretourcommemp_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"vcomemercial");
ajout=create_Emp();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonsuppcomm_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char marque[2000];
GtkWidget *recherche ;

recherche=lookup_widget(objet_graphique,"entryrecherchecomm");


strcpy(marque,gtk_entry_get_text(GTK_ENTRY(recherche)));

supprimerlocationcom(marque);
}

char marquecom[50]; 
void
on_buttonmodifcomm_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*modif ,*recherche;

recherche=lookup_widget(objet_graphique,"entryrecherchecomm");

emp=lookup_widget(objet_graphique,"vcommercial");
modif=create_modifcomm();
gtk_widget_show(modif);
gtk_widget_hide(emp);

strcpy(marquecom,gtk_entry_get_text(GTK_ENTRY(recherche)));

}


void
on_buttonajoutercomm_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"vcommercial");
ajout=create_ajoutcomm();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonaffichercom_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emploc,*treeview;

emploc=lookup_widget(objet_graphique,"vcommercial");



treeview=lookup_widget(emploc,"treeviewcomm");
afficherlocationcom(treeview) ; 
}


void
on_buttonvaliderprixcomm_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char nouveau[50];
GtkWidget *nprix;
GtkWidget *emp ,*modif ;

modif=lookup_widget(objet_graphique,"modifcomm");
emp=create_vcommercial();
gtk_widget_show(emp);
gtk_widget_hide(modif);
nprix=lookup_widget(objet_graphique,"entrynprixcomm");

strcpy(nouveau,gtk_entry_get_text(GTK_ENTRY(nprix)));
modifierlocationcom(marquecom,nouveau);
}

/*--------------------------------------------------------------------------------------------------*/


void
on_buttonv44_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"menuclientloc");
ajout=create_c4x4();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonvf_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"menuclientloc");
ajout=create_familiale();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonvcom_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"menuclientloc");
ajout=create_commercial();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}




 
void
on_buttonreserverfamtor_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;



emp=lookup_widget(objet_graphique,"familiale");
ajout=create_reservfamiliale();
gtk_widget_show(ajout);
gtk_widget_hide(emp);




}



void
on_buttonfamdispo_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *emploc,*treeview;

emploc=lookup_widget(objet_graphique,"familiale");



treeview=lookup_widget(emploc,"treeviewclientfam");
afficherlocation(treeview) ; 




}

void
on_buttonretourvfclient_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"familiale");
ajout=create_menuclientloc();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonvaliderfamili_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
reserv rl ;   
 
GtkWidget *cin ,*date ,*nbjs, *combo  ;

cin=lookup_widget(objet_graphique,"entrycinfam");
date=lookup_widget(objet_graphique,"entrydatefam");
nbjs=lookup_widget(objet_graphique,"entrynbjourfam");
combo=lookup_widget(objet_graphique,"comboboxmarquefam");



strcpy(rl.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
strcpy(rl.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(rl.date,gtk_entry_get_text(GTK_ENTRY(date)));
rl.nbj=gtk_entry_get_text(GTK_ENTRY(nbjs));

afficherresevloc(rl);

GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"reservfamiliale");
ajout=create_menuclientloc();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonretourreserverfamtofam_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"reservfamiliale");
ajout=create_familiale();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonvoiturefamdisporecherche_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *marquecom ;
char marque[50][50]; 
int n=0,i; 
marquecom=lookup_widget(objet_graphique,"comboboxmarquefam");

n=verifierdest(marque);
 if (n!=0) 
  {
    for (i=0 ;i<n ;i++)
       {
         gtk_combo_box_append_text (GTK_COMBO_BOX (marquecom),_(marque[i]));
         
       }
  }
}


void
on_buttonreserver4x4r_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;



emp=lookup_widget(objet_graphique,"c4x4");
ajout=create_reserv4x4();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}



void
on_buttonretour4x4menu_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"c4x4");
ajout=create_menuclientloc();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonrechercher4x4_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *marquecom ;
char marque[50][50]; 
int n=0,i; 
marquecom=lookup_widget(objet_graphique,"combobox4x4444444");

n=verifierdest4(marque);
 if (n!=0) 
  {
    for (i=0 ;i<n ;i++)
       {
         gtk_combo_box_append_text (GTK_COMBO_BOX (marquecom),_(marque[i]));
         
       }
  }
}


void
on_buttonretourr4x4lil4x4_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"reserv4x4");
ajout=create_c4x4();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonreserv4x4_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
reserv rl ;   
 
GtkWidget *cin ,*date ,*nbjs, *combo  ;

cin=lookup_widget(objet_graphique,"entrycin4x4");
date=lookup_widget(objet_graphique,"entrydate4x4");
nbjs=lookup_widget(objet_graphique,"entrynbx4x4");
combo=lookup_widget(objet_graphique,"combobox4x4444444");



strcpy(rl.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
strcpy(rl.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(rl.date,gtk_entry_get_text(GTK_ENTRY(date)));
rl.nbj=gtk_entry_get_text(GTK_ENTRY(nbjs));

afficherresevloc4(rl);

GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"reserv4x4");
ajout=create_menuclientloc();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonretourcommercialmenu_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"commercial");
ajout=create_menuclientloc();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttoncommercialdispoo_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emploc,*treeview;

emploc=lookup_widget(objet_graphique,"commercial");



treeview=lookup_widget(emploc,"treeviewcommercialllll");
afficherlocationcom(treeview) ; 
}


void
on_buttonreserverrcomm_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;



emp=lookup_widget(objet_graphique,"commercial");
ajout=create_reservcomm();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonretourcommlilcomm_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"reservcomm");
ajout=create_commercial();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonrecherchecommm_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *marquecom ;
char marque[50][50]; 
int n=0,i; 
marquecom=lookup_widget(objet_graphique,"comboboxmarquecommmmmmm");

n=verifierdestcom(marque);
 if (n!=0) 
  {
    for (i=0 ;i<n ;i++)
       {
         gtk_combo_box_append_text (GTK_COMBO_BOX (marquecom),_(marque[i]));
         
       }
  }
}


void
on_buttonreservcomm_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
reserv rl ;   
 
GtkWidget *cin ,*date ,*nbjs, *combo  ;

cin=lookup_widget(objet_graphique,"entrycincommmmm");
date=lookup_widget(objet_graphique,"entrydatecommmmm");
nbjs=lookup_widget(objet_graphique,"entrynbcommmmm");
combo=lookup_widget(objet_graphique,"comboboxmarquecommmmmmm");



strcpy(rl.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
strcpy(rl.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(rl.date,gtk_entry_get_text(GTK_ENTRY(date)));
rl.nbj=gtk_entry_get_text(GTK_ENTRY(nbjs));

afficherresevloccom(rl);

GtkWidget *emp ,*ajout ;

emp=lookup_widget(objet_graphique,"reservcomm");
ajout=create_menuclientloc();
gtk_widget_show(ajout);
gtk_widget_hide(emp);
}


void
on_buttonaff4x444_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *emploc,*treeview;

emploc=lookup_widget(objet_graphique,"c4x4");



treeview=lookup_widget(emploc,"treeviewr4x4");
afficherlocation4(treeview) ; 
}

