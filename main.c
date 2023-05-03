#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "Process.h"
#include "Stdtcreate.h"
#include "DisplayTXT.h"
#include "statPlayer.h"
#include "Game.h"
#include "Robust.h"


#define SIZE 100000

int main()
{
//VALUES
    srand(time(NULL));
    int choice1;
    int verif = 1;
    int pourcentage;
    Stdt mainCharacter, fighter1, fighter2, fighter3, fighter4;
    Bag myBag[] = {Pencil, Book, Computer, Knife, Knuckles, Sunglasses, Jacket, Girlfriend};
    int numItems = sizeof(myBag) / sizeof(myBag[0]);
    int start = 0;
    //CREATION DE FICHIER
    FILE* fp1 = fopen("../txt/DebutJeu.txt", "r");
    char intro[SIZE];
    if(fp1 == NULL){
        printf("Erreur on fopen\n");
        exit(1);
    }
    //PRE-GAME
    system("clear");
    printf("Webtoon MI5\n");
    sleep(1);
    char* txt = "Produit par\n-> Louaye SAGHIR\n-> Clement PRIMOLI\n-> Roman BOULLIER\n\n";
    int size = strlen(txt);
    displayTxt(size, txt);  
    sleep(1);
    system("clear");
    //Choix de partie
    printf("=== MENU ===\n");//ASCI ART
    printf("1 - Nouvelle Partie\n");//ASCI ART
    printf("2 - Reprendre Partie\n");//ASCI ART
    printf("3 - Quitter le Jeu\n\n");//ASCI ART
    while(start >= 1 && start <= 3){
        printf("Entrez votre choix : ");
        scanf("%d", &start);
    }
    sleep(1);
    system("clear");

    //affichage de %tage en temps réelle
    for(pourcentage = 0; pourcentage <= 100; pourcentage+=20) {
        printf("LANCEMENT DU JEU... %d%%\r", pourcentage); // \r permet de revenir en début de ligne
        fflush(stdout); // force l'affichage immédiat du texte
        usleep(100000); // suspend l'exécution du programme pendant 100000 microsecondes (0,1 seconde)
    }
    printf("Chargement fini !\n");
    sleep(1);
    system("clear");

    //Choix d'une "Nouvelle Partie"
    if(start == 1)
    {
        while(fgets(intro, SIZE, fp1) != NULL){ 
            int size1 = strlen(intro);
            displayTxt(size1, intro);
        }
        WaitPress();
        fclose(fp1);
        system("clear");
        //CREATE STUDENTS
        char* txt1 = "Avant de commencer a jouer, vous allez saisir votre personnage principal\n\n";
        int size2 = strlen(txt1);
        displayTxt(size2, txt1);//Affichage de Txt1   

        mainCharacter = createStudent();
        system("clear");
        displayStat(mainCharacter);
        sleep(2);
        system("clear");

        char* txt2 = "Commençons...\n";
        int size3 = strlen(txt2);
        displayTxt(size3, txt2);
        sleep(2);
        system("clear");
        //VARIABLES 
        int game = 1;
        char* next_chap;
        chapter ch = create_chapter("Event1");

        //GAME
        while (game == 1)
        {
            next_chap= displayChapter(ch);
            ch = create_chapter(next_chap);
        }
        }//ferme boucle de start == 1
    else if(start == 2){ //"Reprendre partie"
        //affichage de %tage en temps réelle
        for(pourcentage = 0; pourcentage <= 100; pourcentage+=20) {
            printf("CHARGEMENT DE PARTIE... %d%%\r", pourcentage); // \r permet de revenir en début de ligne
            fflush(stdout); // force l'affichage immédiat du texte
            usleep(100000); // suspend l'exécution du programme pendant 100000 microsecondes (0,1 seconde)
        }

        if(loadGame(&mainCharacter, &myBag)){
            printf("Sauvegarde chargée avec succès !\n");
            sleep(1);
            system("clear");
            //VARIABLES 
            char* next_chap;
            chapter ch = create_chapter("Event1");
            next_chap= displayChapter(ch);
            ch = create_chapter(next_chap);

        } else {
            printf("Impossible de charger la sauvegarde!\n\n");
            printf("1 - Nouvelle Partie\n");
            printf("2 - quitter le Jeu\n");
                int start = 0;
            while(start != 1 || start != 2){
                printf("Entrez votre choix : ");
                scanf("%d", &start);
            }
            if(start == 1){ //"Nouvelle Partie"
                system("clear");
                //affichage de %tage en temps réelle
                for(pourcentage = 0; pourcentage <= 100; pourcentage+=20) {
                    printf("LANCEMENT DU JEU... %d%%\r", pourcentage); // \r permet de revenir en début de ligne
                    fflush(stdout); // force l'affichage immédiat du texte
                    usleep(100000); // suspend l'exécution du programme pendant 100000 microsecondes (0,1 seconde)
                }
                printf("Chargement fini !\n");
                sleep(1);
                system("clear");
                //GAME
                int game = 1;
                char* next_chap;
                chapter ch = create_chapter("Event1");
                //GAME
                while (game == 1)
                {
                    //strcpy(next_chap, displayChapter(ch));
                    next_chap= displayChapter(ch);
                    ch = create_chapter(next_chap);

                }
            return 0;
            } else{ //"Quitter le Jeu"
                system("clear");
                return 0;
            }
        }
    }
    else {//"Quitter le Jeu"
        system("clear");
        return 0;
    }
return 0;
}





