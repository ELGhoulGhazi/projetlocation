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

reserv rl ;   
 
GtkWidget *marquecom ,*id ,*jourd ,*jourj ,*moisd ,*moisj ,*annd ,*annj ;

marquecom=lookup_widget(objet_graphique,"comboboxm");
id=lookup_widget(objet_graphique,"entrycin");
jourd=lookup_widget(objet_graphique,"spinbuttonjour");
moisd=lookup_widget(objet_graphique,"spinbuttonmois");
annd=lookup_widget(objet_graphique,"spinbuttonann");
jourj=lookup_widget(objet_graphique,"spinbutton1jour");
moisj=lookup_widget(objet_graphique,"spinbutton1mois");
annj=lookup_widget(objet_graphique,"spinbutton1ann");


rl.jd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourd));
rl.md=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisd));
rl.ad=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annd));
rl.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourj));
rl.mj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisj));
rl.aj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annj));

strcpy(rl.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(marquecom)));
strcpy(rl.cin,gtk_entry_get_text(GTK_ENTRY(id)));

afficherresevloc(rl);



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
GtkWidget *inputmarque , *inputprix ;
GtkWidget *emp ,*ajout ;

ajout=lookup_widget(objet_graphique,"ajouterloc");
emp=create_locationEmp();
gtk_widget_show(emp);
gtk_widget_hide(ajout); 

inputmarque=lookup_widget(objet_graphique,"entrymarque"); 
inputprix=lookup_widget(objet_graphique,"entryprix"); 

strcpy(l.marque,gtk_entry_get_text(GTK_ENTRY(inputmarque)));
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

