#include "Robust.h"
//Renvoie la lettre en majuscule
char toUpper(char c){
    return c-32;
}
//Renvoie la lettre en minuscule
char toLower(char c){
    return c+32;
}

char *Remove_carriage_return(char *value) {
    //ROBUST
	if (value == NULL) {
		printf("quelque chose ne vas pas avec value(Remove_carriage_return/Robust.c)\n");
		exit(345);
	}
    //supprime les retours à la ligne (\n)
	for (int i = 0; i <strlen(value) ; i++) {
		char carriage = value[i]; // Correction : retirer l'opérateur * ici
		if (carriage == '\n' || carriage == '\r') { // Correction : utiliser des simples quotes pour les caractères
			value[i] = '\0';
			break;
		}
	}
	return value;
	
}

//vérifie si toutes les valeurs de la chaine sont des lettres
int is_char(char* chaine) {
    for(int i=0; i < strlen(chaine);i++){
        if(chaine[i] < 65 || (chaine[i]>90 && chaine[i]<97) || chaine[i]>122){
            return 0; //il y a un caractère special
        }
    }
    return 1;
}

//sert à supprimer la mémoire tampon
void getWord(char* buffer){
    int ret = 0;
    //ROBUST
    if(buffer == NULL){
        printf("getWord buffer is NULL \n");
        exit(10);
    }
    
    do{
        ret = scanf("%s", buffer);
        scanf("%*[^\n]"); // Vider le flux d'entrée
		scanf("%*c");
    } while (ret != 1);

}
//vérifie que les réponses rendues sont compatibles avec les choix
int robust(int integer)
{
	int choice;
	do {
        printf("\nChoix : ");
		if (scanf("%d", &choice) != 1 || choice < 1 || choice > integer) {
			printf("Saisie incorrecte ! Saisir à nouveau :\n");
			scanf("%*[^\n]"); // Vider le flux d'entrée
			scanf("%*c");
			choice = -1;
		}
	} while (choice == -1);

	return choice;

}
//vérifie si le fichier de sauvegarde est vide ou non
long is_save_txt_null()
{
    char *path = (char *)malloc((strlen("Save/save") + strlen(".txt")) * sizeof(char) + 1);
	//~~> contien le chemin d'accès au fichier txt que nous voulons ouvrir

	strcpy(path, "Save/save"); // suivie de 'chapter_name'(concaténation)
	strcat(path, ".txt");		// et de '.txt'

    FILE *fp = fopen(path, "r");
    //ROBUST
    if(fp == NULL)
    {
        printf("erreur fopen (file2)\n");
        exit(125);
    }

    fseek(fp, 0, SEEK_END);

    long result = ftell(fp);

    fclose(fp);

return result;
}

