/**
* \file Placement_bateau.h
* \brief fichier qui contient l'ensemble des prototypes de Placement_bateau.c
* \author ZERBANE Mehdi
* \version 1.0
*/

#ifndef PLACEMENT_BATEAU
#define PLACEMENT_BATEAU

#include "Outil.h"
#include "Grille.h"
#include "Struct.h"
#include "Placement_obstacle.h"

t_case grille[N][M];

int bStringtonum(char *v,int *pRes);
int verif_presence(t_bateau bateau,int i,int j,int eChoix_sens,int eNum_grille);
int Assez_de_place(t_bateau bateau, int i,int j,int eChoix_sens,int eNum_grille);
void Placer_grillebateau(t_bateau bateau, int i,int j,int eNum_grille,int eChoix_sens);
void Enlever_grillebateau(t_bateau bateau, int i,int j,int eNum_grille,int eChoix_sens);
void Enlever_grilletousbateau(int eNum_grille);
int Changement_colonne(char * v,int *peRes);
void Placer_bateau_auto(int eNum_grille,int eNb_torpilleur);
void Placer_bateau_manuelle(int eNum_grille,int eNb_torpilleur);
void Commencer_jeu_placement_bateau(int eNb_torpilleurs);
#endif
