#ifndef EVENT1WE_H
#define EVENT1WE_H

#include<ctype.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int Event1(int choix1){
    //affiche le premier choix entre aller au WE ou pas
    while(fgets(weekend, SIZE, fp2) != NULL){
        int size4 = strlen(weekend);
        displayTxt(size4, weekend);   
    }  
    //on ferme le fichier pour libérer la mémoire tampon
    fclose(fp1);
    printf("Veux-tu y aller ?\n Oui(1) ou Non(2)");
    switch(choice(2)){
        case 1:
            //Choix d'aller au weekend d'inté accepté
    		while(fgets(we1, SIZE, fp3) != NULL){
        	    int size5 = strlen(we1);
        	    displayTxt(size5, we1);   
	        }
            //ferme le fichier pour libérer mémoire tampon
            fclose(fp3);
            //attend une réponse physique de l'utilisateur pour continuer
            WaitPress();

            // afficher message de fin d'event de weekend d'intégration :
            //envoie vers le prochain Event
        case 2:
            //Choix d'aller au weekend d'inté refusé
            while(fgets(we2, SIZE, fp4) != NULL){
        		int size6 = strlen(we2);
        		displayTxt(size6, we2);
            }
            //ferme le fichier pour libérer la mémoire tampon
            fclose(fp4);
            //attend une rep de l'utilisateur pour continuer
            Waitpress();

            // afficher message de fin d'event de weekend d'intégration :
            //Envoie vers le prochain Event

}
}
#endif 