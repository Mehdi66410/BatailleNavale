#include "jouer/jouer.h"

int main(void){
	Grille_init();
	Placer_bateau_auto(1,2);
	Placer_bateau_auto(2,2);
	placer_obstacle(1);
	placer_obstacle(2);
	Jouer_Partie();
	return 1;
}