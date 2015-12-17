#include "jouer/jouer.h"
#include "Placer/Placement_bateau.h"
#include "Affichage/include/afficher.h"
#include <curses.h>
#include <menu.h>
#define WIDTH 50
#define HEIGHT 200

int main(void){
	WINDOW *win;
    FILE*fic1;
	char sChoixmenu[20];
	int eChoixmenu=0;
	int N_Deplacement, N_Torpilleur, Taille_Portee;
	initscr();
	clear();
	noecho();
	cbreak();	//Line buffering disabled. pass on everything 
	win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(win, TRUE);
	refresh();
	printw("*************************************************************************************************************\n");
	printw("******************************** Bienvenue sur le jeu de la Bataille Navale *********************************\n");
	printw("*************************************************************************************************************\n");
	printw("\n\n\nMenu :\n\t1 : Nouvelle Partie\n\t2: Charger\n\t3: Quitter\n");
	refresh();
	do{
		printw("Choix : ");
		echo();
		scanw("%s",sChoixmenu);
		noecho();
	}while(!bStringtonum(sChoixmenu,&eChoixmenu) || eChoixmenu <1 || eChoixmenu >3); //Tant que on a pas un entier compris entre 1 et 2
	if(eChoixmenu==1){
		clear();
		Jouer_Init_Torpilleur(&N_Torpilleur,&N_Deplacement, &Taille_Portee);
		Commencer_jeu_placement_bateau(N_Torpilleur);
		Jouer_Partie(N_Torpilleur, N_Deplacement, Taille_Portee);
    }else if(eChoixmenu==2){
        /*fic1=fopen("Joueur1.txt","r");
        fread(&grille,sizeof(grille),1,fic1);*/
    }else if(eChoixmenu==3)endwin(); //Si le joueur veut quitter
    endwin();
	return 1;
}

