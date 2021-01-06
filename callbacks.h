#include <gtk/gtk.h>


void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Ret_aj_aff_gp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ann_ajout_gp_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Affich_gp_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_go_to_ajout_gp_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ann_modif_gp_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ret_aff_mod_gp_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ok_clicked                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
