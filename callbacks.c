#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "equipement.h"


void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	int a;
	equipement e;
	GtkWidget *input1, *input2,*input3,*input4,*input5;
        GtkWidget *output,*output1;
	input1=lookup_widget(objet_graphique,"type");
	input2=lookup_widget(objet_graphique,"marque");
	input3=lookup_widget(objet_graphique,"puissance");
	input4=lookup_widget(objet_graphique,"annee");
	input5=lookup_widget(objet_graphique,"matricule");
	output1=lookup_widget(objet_graphique,"label29");
	

	strcpy(e.type,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(e.puissance,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(e.annee,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(e.matricule,gtk_entry_get_text(GTK_ENTRY(input5)));

       if ((strlen(e.type)==0)||(strlen(e.marque)==0)||(strlen(e.puissance)==0)||(strlen(e.annee)==0) || (strlen(e.matricule)==0))
{

       gtk_label_set_text(GTK_LABEL(output1),"veuilez remplir toutes les cases");
}
else
{
        a=ajouter_equipement(e);
        if (a==0){
       
        gtk_label_set_text(GTK_LABEL(output1),"ajout avec succés");
       }
       else  
      {
       gtk_label_set_text(GTK_LABEL(output1),"membre deja existant");
       }
}

}


void
on_Ret_aj_aff_gp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"fenetre_ajout");
gtk_widget_hide(window1);
window2 = create_fenetre_afficher();
gtk_widget_show (window2);
}


void
on_ann_ajout_gp_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2,*input3,*input4,*input5;
        
	input1=lookup_widget(objet_graphique,"type");
	input2=lookup_widget(objet_graphique,"marque");
	input3=lookup_widget(objet_graphique,"puissance");
	input4=lookup_widget(objet_graphique,"annee");
	input5=lookup_widget(objet_graphique,"matricule");


    gtk_entry_set_text(GTK_ENTRY(input1),"");
    gtk_entry_set_text(GTK_ENTRY(input2),"");
    gtk_entry_set_text(GTK_ENTRY(input3),"");
    gtk_entry_set_text(GTK_ENTRY(input4),"");
    gtk_entry_set_text(GTK_ENTRY(input5),"");
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"fenetre_afficher");
gtk_widget_hide(window1);
window2 = create_fenetre_modifier();
gtk_widget_show (window2);
}


void
on_supprimer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	char type[30];
	char marque[30];
	char puissance[30];
	char annee[30];
	char matricule[30];
      
   
   GtkWidget *input;
   GtkWidget *output;
   input=lookup_widget(objet_graphique,"matricule_supprimer");
   strcpy(matricule,gtk_entry_get_text(GTK_ENTRY(input)));
   output=lookup_widget(objet_graphique,"label30");

 if ((strlen(matricule)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir la case");
}

else
{
    supprimer_equipement(matricule) ;
  gtk_label_set_text(GTK_LABEL(output),"membre supprimé"); 
}
}


void
on_Affich_gp_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *treeview;
        GtkWidget *window1;
        window1=lookup_widget(objet_graphique,"fenetre_afficher");
        treeview=lookup_widget(objet_graphique,"treeview1");
        
        afficher_equipement(treeview);
}


void
on_go_to_ajout_gp_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"fenetre_afficher");
gtk_widget_hide(window1);
window2 = create_fenetre_ajout();
gtk_widget_show (window2);
}


void
on_ann_modif_gp_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2,*input3,*input4,*input5;
        
	input1=lookup_widget(objet_graphique,"modifier_type");
	input2=lookup_widget(objet_graphique,"modifier_marque");
	input3=lookup_widget(objet_graphique,"modifier_puissance");
	input4=lookup_widget(objet_graphique,"modifier_annee");
	input5=lookup_widget(objet_graphique,"modifier_matri");


    gtk_entry_set_text(GTK_ENTRY(input1),"");
    gtk_entry_set_text(GTK_ENTRY(input2),"");
    gtk_entry_set_text(GTK_ENTRY(input3),"");
    gtk_entry_set_text(GTK_ENTRY(input4),"");
    gtk_entry_set_text(GTK_ENTRY(input5),"");
    
}



void
on_ret_aff_mod_gp_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"fenetre_modifier");
gtk_widget_hide(window1);
window2 = create_fenetre_afficher();
gtk_widget_show (window2);

}


void
on_ok_clicked                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	equipement e; 
        GtkWidget *input1, *input2,*input3,*input4,*input5;
        GtkWidget *output;
        
        input1=lookup_widget(objet_graphique,"modifier_type");
	input2=lookup_widget(objet_graphique,"modifier_marque");
	input3=lookup_widget(objet_graphique,"modifier_puissance");
	input4=lookup_widget(objet_graphique,"modifier_annee");
	input5=lookup_widget(objet_graphique,"modifier_matri");
	 
        
        strcpy(e.type,gtk_entry_get_text(GTK_ENTRY(input1)));
        strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
        strcpy(e.puissance,gtk_entry_get_text(GTK_ENTRY(input3)));
        strcpy(e.annee,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(e.matricule,gtk_entry_get_text(GTK_ENTRY(input5)));
        modifier_equipement (e);
        output=lookup_widget(objet_graphique,"label31");
    
    
         if ((strlen(e.matricule)==0)||(strlen(e.type)==0)||(strlen(e.marque)==0)||(strlen(e.puissance)==0) || (strlen(e.annee)==0))
        
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir toutes les cases");
}
else
{
     
     
     gtk_label_set_text(GTK_LABEL(output),"modifié avec succés");
}
}

