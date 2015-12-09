//
//  Placement_bateau.c
//
//
//  Created by Zerbane Mehdi on 27/11/2015.
//
//


int bStringtonum(char *v,int *res){
    int bNum=1;
    int i;
    *res=0;
    for(i=0;i<strlen(v);i++)
        bNum=bNum && isdigit(v[i]);
    if(bNum==1){
        *res=atoi(v);
    }
    return bNum;
}

int verif_presence(t_bateau bateau,int i,int j,int choix_sens,int num_grille){
    int compteur=0,resultat_b=0,resultat_o=0,resultat_t=0;
    if(choix_sens==1){
	    while(compteur<bateau){
		Grille_lire_bateau(i,j+compteur,num_grille,&resultat_b);
		Grille_lire_obstacle(i,j+compteur,num_grille,&resultat_o);
		Grille_lire_torpilleur(i,j+compteur,num_grille,&resultat_t);
		if(resultat_b!=0 || resultat_o!=0 || resultat_t!=0)return 0;
	        compteur++;
	   }
   }
    else if(choix_sens==2){
	while(compteur<bateau){
		Grille_lire_bateau(compteur+i,j,num_grille,&resultat_b);
		Grille_lire_obstacle(compteur+i,j,num_grille,&resultat_o);
		Grille_lire_torpilleur(i,j+compteur,num_grille,&resultat_t);
		if(resultat_b!=0 || resultat_o!=0 || resultat_t!=0)return 0;
	        compteur++;
	   }

   }
	return 1;
}

int Assez_de_place(t_bateau bateau, int i,int j,int choix_sens,int num_grille){
	if(choix_sens==1){
		return (j+bateau-1<N);
	}
	else if(choix_sens==2){
		return (i+bateau-1<M);
	}
	return 0;
}

void Placer_grillebateau(t_bateau bateau, int i,int j,int num_grille,int choix_sens){
	int compteur=0;
	if(choix_sens==1){
		while(compteur<bateau){
			Grille_ecrire_bateau(i,j+compteur,num_grille,bateau);
			compteur++;
		}
	}else if(choix_sens==2){
		while(compteur<bateau){
			Grille_ecrire_bateau(i+compteur,j,num_grille,bateau);
			compteur++;
		}
	}
}
void Enlever_grillebateau(t_bateau bateau, int i,int j,int num_grille,int choix_sens){
	int compteur=0,bat,obs;
	if(choix_sens==1){
		while(compteur<bateau){
			Grille_lire_bateau(i,j+compteur,num_grille,&bat);
 			Grille_lire_obstacle(i,j+compteur,num_grille,&obs);
			if(bat==bateau && obs==0)Grille_ecrire_bateau(i,j+compteur,num_grille,Aucun_b);
			printf("%i %i \n",i,j+compteur);
			compteur++;
		}
	}else if(choix_sens==2){
		while(compteur<bateau){
			Grille_lire_bateau(i+compteur,j,num_grille,&bat);
 			Grille_lire_obstacle(i+compteur,j,num_grille,&obs);
			if(bat==bateau && obs==0)Grille_ecrire_bateau(i+compteur,j,num_grille,Aucun_b);
						printf("%i %i \n",i+compteur,j);
			compteur++;
		}
	}
}

void Enlever_grillebateau2(int num_grille){
	int i,j,obs;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			Grille_lire_obstacle(i,j,num_grille,&obs);
			if((grille[i][j].bateau==Sous_Marin || grille[i][j].bateau==Destroyer || grille[i][j].bateau==Porte_Avion || grille[i][j].torpilleur==Present) && !obs){
		 grille[i][j].bateau=Aucun_b; 
			grille[i][j].torpilleur=0;
			}

		}
	}
}
void Placer_bateau_auto(int num_grille,int nb_torpilleur){
	int compteur=0,choix_sens,i,j,ok=0,nb=0,valide=0,Choix;
	char sC[20];
	do{
	srand(time(NULL));
    for(compteur=0;compteur!=1;compteur++){
	//Sous_Marin
        do{
	    ok=0;
		i=uHasard(N);
		j=uHasard(M);
                 if(bCroit(0,i,N) && bCroit(0,j,M)){
                  
			choix_sens=uHasard(2);
			if(verif_presence(Sous_Marin,i,j,choix_sens,num_grille) && Assez_de_place(Sous_Marin,i,j,choix_sens,num_grille)){
				Placer_grillebateau(Sous_Marin, i,j,num_grille,choix_sens);
				ok=1;
			}
                    
            	}
         
        }while(!ok);
       
 	 ok=0;
	//Destroyer
        do{
	    ok=0;
		i=uHasard(N);
		j=uHasard(M);
                 if(bCroit(0,i,N) && bCroit(0,j,M)){
                  
                           			choix_sens=uHasard(2);
			if(verif_presence(Destroyer,i,j,choix_sens,num_grille) && Assez_de_place(Destroyer,i,j,choix_sens,num_grille)){
				Placer_grillebateau(Destroyer, i,j,num_grille,choix_sens);
				ok=1;
			}
                    
            	}
         
        }while(!ok);
                
        ok=0;
	 //Porte_Avion
        do{
	    ok=0;
		i=uHasard(N);
		j=uHasard(M);
                 if(bCroit(0,i,N) && bCroit(0,j,M)){
                  
                           			choix_sens=uHasard(2);
			if(verif_presence(Porte_Avion,i,j,choix_sens,num_grille) && Assez_de_place(Porte_Avion,i,j,choix_sens,num_grille)){
				Placer_grillebateau(Porte_Avion, i,j,num_grille,choix_sens);
				ok=1;
			}
                    
            	}
         
        }while(!ok);
	ok=0;
	nb=0;
	//Torpilleur(s)
	while(nb!=nb_torpilleur){
		do{
	    ok=0;
		i=uHasard(N);
		j=uHasard(M);
                 if(bCroit(0,i,N) && bCroit(0,j,M)){
                  
                           			choix_sens=uHasard(2);
			if(verif_presence(Present,i,j,choix_sens,num_grille) && Assez_de_place(Present,i,j,choix_sens,num_grille)){
					Grille_ecrire_torpilleur(i,j,num_grille,Present);
				ok=1;
			}
                    
            	}
         
        }while(!ok);
     
		nb++;	
	}
    }
	for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                printf("%i  ",grille[i][j].bateau);
            }
            printf("\n");
        }
            printf("\n");
        printf("\n");
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%i  ",grille[i][j].torpilleur);
        }
        printf("\n");
    }
	printf("Etes vous satisfait de vos bateaux ?? Oui:1 Non:0");
            scanf("%s",sC);
            if(bStringtonum(sC,&Choix)){
                if(Choix==1)valide=1; 
		else{
			valide=0;
Enlever_grillebateau2(num_grille);


		}
            }else  Enlever_grillebateau2(num_grille);
	}while(!valide);
}

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

void Placer_bateau_manuelle(int num_grille,int nb_torpilleur){
    int compteur=0,choix_sens,i,j,ok=0,Choix=0,valide=0,nb=0;
    char sI[20];
    char sJ[20];
    char sC[20];
    for(compteur=0;compteur!=1;compteur++){
	printf("Vous allez rentrer le Sous_Marin\n");
        do{
	    ok=0;
	    Choix=0;
            printf("Veuillez rentrer les coordonnées i et j de depart pour placer le bateau : ");
            scanf("%s",sI);
            scanf("%s",sJ);
             if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
                 if(bCroit(0,i,N) && bCroit(0,j,M)){
                    printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical\t : ");
                    scanf("%i",&choix_sens);
                    if(bCroit(1,choix_sens,2)){         
			if(verif_presence(Sous_Marin,i,j,choix_sens,num_grille) && Assez_de_place(Sous_Marin,i,j,choix_sens,num_grille)){
				Placer_grillebateau(Sous_Marin, i,j,num_grille,choix_sens);
				ok=1;
			}
                    }
            	}
             }
            printf("Etes vous satisfait de votre choix ? Oui:1 \t Non:0 \n");
            scanf("%s",sC);
            if(bStringtonum(sC,&Choix)){
                if(Choix==1 && ok==1)valide=1; //dfswgsgdudsygfdhsffhdjsdsfhjdfsjhfdshj CORRECT
		else{
			valide=0;
			Enlever_grillebateau(Sous_Marin, i,j,num_grille,choix_sens);
			printf("gsfgfdsgdfg");
		}
            }else  Enlever_grillebateau(Sous_Marin, i,j,num_grille,choix_sens);
	printf("ok :%i Choix: %i\n",ok,Choix);
        }while(!valide);
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                printf("%i  ",grille[i][j].bateau);
            }
            printf("\n");
        }
 	 ok=0;
	printf("Vous allez placer le Destroyer\n");
        do{
            printf("Veuillez rentrer les coordonnées i et j pour placer le bateau : ");
            scanf("%s",sI);
            scanf("%s",sJ);
            if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
                if(bCroit(0,i,N) && bCroit(0,j,M)){
                    printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical\t : ");
                    scanf("%i",&choix_sens);
                    if(bCroit(1,choix_sens,2)){
				if(verif_presence(Destroyer,i,j,choix_sens,num_grille)&& Assez_de_place(Destroyer,i,j,choix_sens,num_grille)){
		                        Placer_grillebateau(Destroyer, i,j,num_grille,choix_sens);
					ok=1;
				}
		    }
		}
	    }  
	printf("Etes vous satisfait de votre choix ? Oui:1 \t Non:0 \n");
            scanf("%s",sC);
            if(bStringtonum(sC,&Choix)){
                if(Choix==1 && ok==1)valide=1; //dfswgsgdudsygfdhsffhdjsdsfhjdfsjhfdshj CORRECT
		else{
			valide=0;
			Enlever_grillebateau(Destroyer, i,j,num_grille,choix_sens);
		}
            }else  Enlever_grillebateau(Destroyer, i,j,num_grille,choix_sens);
	printf("ok :%i Choix: %i\n",ok,Choix);
        }while(!valide);
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                printf("%i  ",grille[i][j].bateau);
            }
            printf("\n");
        }                  
        ok=0;
        do{
            printf("Vous allez placer le Porte_Avion\n");
            printf("Veuillez rentrer les coordonnées i et j pour placer le bateau : ");
            scanf("%s",sI);
            scanf("%s",sJ);
            if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
                if(bCroit(0,i,N) && bCroit(0,j,M)){
                    printf("Dans quelle sens souhaitez vous le placé ? 1 Horizontal , 2 Vertical\t : ");
                    scanf("%i",&choix_sens);
                    if(bCroit(1,choix_sens,2)){
				if(verif_presence(Porte_Avion,i,j,choix_sens,num_grille)&& Assez_de_place(Porte_Avion,i,j,choix_sens,num_grille)){
		                        Placer_grillebateau(Porte_Avion, i,j,num_grille,choix_sens);
					ok=1;
				}
                     }
                }
            }
	printf("Etes vous satisfait de votre choix ? Oui:1 \t Non:0 \n");
            scanf("%s",sC);
            if(bStringtonum(sC,&Choix)){
                if(Choix==1 && ok==1)valide=1; //dfswgsgdudsygfdhsffhdjsdsfhjdfsjhfdshj CORRECT
		else{
			valide=0;
			Enlever_grillebateau(Porte_Avion, i,j,num_grille,choix_sens);
		}
            }else  Enlever_grillebateau(Porte_Avion, i,j,num_grille,choix_sens);
	printf("ok :%i Choix: %i\n",ok,Choix);
        }while(!valide);
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                printf("%i  ",grille[i][j].bateau);
            }
            printf("\n");
        }
       
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
		    printf("%i  ",grille[i][j].bateau);
		}
        printf("\n");
    	}
	ok=0;
	printf("Vous allez rentrer le torpilleur\n");
	while(nb!=nb_torpilleur){
		do{
		    printf("Veuillez rentrer les coordonnées i et j de depart pour placer le bateau : ");
		    scanf("%s",sI);
		    scanf("%s",sJ);
		    if(bStringtonum(sI,&i) && bStringtonum(sJ,&j)){
		        if(bCroit(0,i,N) && bCroit(0,j,M)){
				if(verif_presence(Present,i,j,choix_sens,num_grille)){
					Grille_ecrire_torpilleur(i,j,num_grille,Present);

					ok=1;
				}
		        }
		    }
		printf("Etes vous satisfait de votre choix ? Oui:1 \t Non:0 \n");
            scanf("%s",sC);
            if(bStringtonum(sC,&Choix)){
                if(Choix==1 && ok==1)valide=1; //dfswgsgdudsygfdhsffhdjsdsfhjdfsjhfdshj CORRECT
		else{
			valide=0;
			Enlever_grillebateau(Present, i,j,num_grille,choix_sens);
		}
            }else  Enlever_grillebateau(Present, i,j,num_grille,choix_sens);
	printf("ok :%i Choix: %i\n",ok,Choix);
        }while(!valide);
        
		
		nb++;	
	}
    }
	for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                printf("%i  ",grille[i][j].bateau);
            }
            printf("\n");
        }
            printf("\n");
        printf("\n");
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%i  ",grille[i][j].torpilleur);
        }
        printf("\n");
    }
    
}
