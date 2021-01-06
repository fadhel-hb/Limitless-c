#include<stdio.h>
#include<string.h>
#include "troupeaux.h"

enum
{
	ID,
	RACE,
	POIDS,
	SEXE,
	DATE,
	COLUMNS,
};


//ajouter troupeaux

int ajouter_troupeaux(troupeaux t)
{

FILE *f;
f=fopen("troupeaux.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",t.id,t.race,t.poids,t.sexe,t.date);
fclose(f);
return 0;
}
}
//afficher troupeaux

void afficher_troupeaux(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;

	char id[30];
	char race[30];
	char poids[30];
	char sexe[30];
	char date[30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("RACE",renderer, "text",RACE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("POIDS",renderer, "text",POIDS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("SEXE",renderer, "text",SEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",DATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	

}
	store=gtk_list_store_new(5,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("troupeaux.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("troupeaux.txt","a+");
	while(fscanf(f,"%s %s %s %s %s \n",id,race,poids,sexe,date )!=EOF)
	{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,ID,id,RACE,race,POIDS,poids,SEXE,sexe,DATE,date,-1);
	}
	fclose(f);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

	
}

// supprimer troupeaux
void supprimer_troupeaux(char id[30])
{
FILE *f,*f1;
f=fopen("troupeaux.txt","r");
f1=fopen("troupeaux_tmp.txt","w");
 if ((f!=NULL) && (f1!=NULL))
{
while(fscanf(f,"%s %s %s %s %s\n",t.id,t.race,t.poids,t.sexe,t.date)!=EOF)
{
if(strcmp(id,t.id)!=0)
{
fprintf(f1,"%s %s %s %s %s\n",t.id,t.race,t.poids,t.sexe,t.date);
}
}
fclose(f) ;
fclose(f1);
remove("troupeaux.txt");
rename("troupeaux_tmp.txt","troupeaux.txt");
}
}


//modifier troupeaux
void modifier_troupeaux (troupeaux t)
{

{
FILE *f;
FILE *f2;
f=fopen("troupeaux.txt","r");
f2=fopen("troupeaux.txt.tmp","w");
 if ((f!=NULL) && (f2!=NULL))
{
while (fscanf(f,"%s %s %s %s  %s\n",m.id,m.race,m.poids,m.sexe,m.date)!=EOF)
    {
if (strcmp(t.id,m.id)==0){
   fprintf(f2," %s %s %s %s %s\n",t.id,t.race,t.poids,t.sexe,t.date );
}
else
{    fprintf(f2,"%s %s %s %s  %s\n",m.id,m.race,m.poids,m.sexe,m.date);
   }

}}
fclose(f2);
fclose(f);
remove("troupeaux.txt");
rename("troupeaux.txt.tmp","troupeaux.txt");
}
}






