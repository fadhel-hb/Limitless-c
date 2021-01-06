#include <gtk/gtk.h>

typedef struct {
	char id[30];
	char race[30];
	char poids[30];
	char sexe[30];
	char date[30];
 }troupeaux;
troupeaux t,m;


int ajouter_troupeaux(troupeaux t);
void supprimer_troupeaux(char id[30]);
void modifier_troupeaux(troupeaux t);
void  afficher_troupeaux(GtkWidget *treeview);
