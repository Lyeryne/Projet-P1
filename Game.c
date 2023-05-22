#include "Game.h"

int pre_game()
{
	int start, lu, count;
	system("clear");
	printf("X TECH - ADVENTURE\n");
	char *txt = "Produit par\n-> Louaye SAGHIR\n-> Clement PREMOLI\n-> Roman BOULLIER\n\n";
	int size = strlen(txt);
	displayTxt(size, txt);
	sleep(1);
	system("clear");
	// Choix de partie
	printf("========= MENU ========\n"); // ASCI ART
	printf(" 1 -> Nouvelle Partie\n");	 // ASCI ART
	printf(" 2 -> Reprendre Partie\n");	 // ASCI ART
	printf(" 3 -> Quitter le Jeu\n\n");	 // ASCI ART
	printf("Choix :\n");

	start = robust(3);

	return start;
}

int no_game()
{
	int start, lu;
	system("clear");
	printf("========= MENU ==========\n"); // ASCI ART
	printf("1 -> Nouvelle Partie\n");	   // ASCI ART
	printf("~~ ACCES NON-AUTORISER ~~\n"); // ASCI ART
	printf("2 -> Quitter le Jeu\n\n");	   // ASCI ART
	printf("Choix :");
	
	start = robust(2);

	return start;
}

char *set_text_tab(char *buf, char *value){
	int len = strlen(value) + 1;
	buf = (char *)malloc(len * sizeof(char));
	if(buf == NULL){
		printf("Quelque chose ne vas pas avec buf(text_tab)");
		exit(34647);
	}
	strcpy(buf, value);
	return buf;
}

char *set_text_property(char *buf, char *value)
//=>permet de remplir une propriété de type char * (%s) d'une structure de manière dynamique
{
	int length;
	if (buf == NULL) // propriété n'est pas initialisée
	{
		length = strlen(value) + 1;
		buf = (char *)malloc(length * sizeof(char)); // allocation pour stocker 'value' et copie cette valeur dans 'buf'
		if (buf == NULL)
		{
			exit(1);
		}
		strcpy(buf, value); // copier la %s 'value' dans le tampon 'buf'
	}
	else
	{ // propriété est déjà initialisée
		length = strlen(buf) + strlen(value) + 1;
		char *temp = (char *)realloc(buf, length * sizeof(char));
		// allocation pour stocker la valeur déjà présente dans 'buf' et la valeur à ajouter (value)
		if (temp != NULL)
		{
			buf = temp; // affecte le * 'temp' à 'buf'
		}
		strcat(buf, value); // concatenation de 'value' à la propriété 'buf'
	}

	return buf;
}

void ProcessDescription(chapter *chap, char *value)
{
	// ROBUST
	if (chap == NULL)
	{
		printf("Quelque chose ne vas pas avec chap(ProcessDescription)\n");
		exit(6);
	}
	// ROBUST
	if (value == NULL)
	{
		printf("Quelque chose ne vas pas avec value(ProcessDescription)\n");
		exit(7);
	}
	chap->description = set_text_property(chap->description, value);
	// remplit une chaîne de caractères tout en s'assurant que la mémoire allouée est suffisante
	//=> assigner une description(avec la valeur de 'value') à un chapitre
}

void ProcessAfterDescription(chapter *chap, char *value)
{
	// ROBUST
	if (chap == NULL)
	{
		printf("Quelque chose ne vas pas avec chap(ProcessAfterDescription)\n");
		exit(8);
	}
	// ROBUST
	if (value == NULL)
	{
		printf("Quelque chose ne vas pas avec value(ProcessAfterDescription)\n");
		exit(9);
	}
	chap->after_description = set_text_property(chap->after_description, value);
}
void ProcessEvent(chapter *chap, char *value, int counter)
{
	// ROBUST
	if (chap == NULL)
	{
		printf("Quelque chose ne vas pas avec chap(ProcessEvent)\n");
		exit(10);
	}
	// ROBUST
	if (value == NULL)
	{
		printf("Quelque chose ne vas pas avec value(ProcessEvent)\n");
		exit(11);
	}
	int a;
	if (counter == 1)
	{
		chap->event = malloc(2 * sizeof(Event));
	}
	// utiiser la fonction de louaye qui transforme un char en int et faire le switch avec
	switch (counter)
	{
	case 1:
		a = atoi(value);
		chap->event->type_event = a;
		break;
	case 2:
		a = atoi(value);
		chap->event->id_object = a;
		break;
	case 3:
		a = atoi(value);
		chap->event->n_fighter = a;
		break;
	case 4:
		a = atoi(value);
		chap->event->type_stat = a;
		break;
	case 5:
		a = atoi(value);
		chap->event->n_stat = a;
		break;
	case 6:
		a = atoi(value);
		chap->event->add_or_remove_bag = a;
		break;
	case 7:
		a = atoi(value);
		chap->event->positive_or_negative = a;
	}
	// remplit event de la struct chapter avec la %s 'value' en utilisant 'fill_text_property'
	//=> ajouter des événements
}

char *Corrigation_de_ProcessChoice(char *value) {
	if (value == NULL) {
		printf("ca va pas dans corrigaiton de process choice");
		exit(345);
	}
	for (int i = strlen(value) - 1; i >= 0; i--) {
		char bonjour = value[i]; // Correction : retirer l'opérateur * ici
		if (bonjour == '\n' || bonjour == '\r') { // Correction : utiliser des simples quotes pour les caractères
			value[i] = '\0';
			break;
		}
	}
	return value;
}
void ProcessChoice(chapter *chap, char *value)
// =>Ce code est une fonction qui ajoute une option de choix à un chapitre d'une histoire interactive
{
	// ROBUST
	if (chap == NULL)
	{
		printf("Quelque chose ne vas pas avec chap(ProcessChoice)\n");
		exit(12);
	}
	// ROBUST
	if (value == NULL)
	{
		printf("Quelque chose ne vas pas avec value(ProcessChoice)\n");
		exit(13);
	}
	// ROBUST
	if (chap->choices == NULL)
	{ // gère la mémoire allouée pour stocker les choix dans la structure chapter
		// Si la liste des choix est vide (== NULL)
		chap->choices = (Choice *)malloc(1 * sizeof(Choice)); // alors un choix est alloué
		if (chap->choices == NULL)
		{
			printf("pb la ca va pas");
			exit(456);
		}
		chap->choice_count = 0;
	}
	else
	{
		Choice *temp = (Choice *)realloc(chap->choices, (chap->choice_count + 1) * sizeof(Choice));
		// ROBUST
		if (temp == NULL)
		{
			printf("Quelque chose ne vas pas avec temp(ProcessChoice)\n");
			exit(346);
		}
		// Sinon, un choix supplémentaire est alloué avec 'realloc' pour augmenter la taille de la liste des choix.
		if (temp != NULL)
		{
			chap->choices = temp;
		}
	}
	Choice ch = {0};
	if (ch.nextChapter != NULL)
	{
		printf("Y'a un truc qi va pas dans create_chapter");
		exit(45);
	}
	if (ch.text != NULL)
	{
		printf("Y'a un truc qui va pas encore dans create_chapter");
		exit(67);
	}
	// analyse la chaîne de caractères value en utilisant le délimiteur '_' et extrait chaque partie de la %s
	char delim[] = "_";
	char *cutteds = strtok(value, delim); // séparer la chaîne value en sous-chaînes en utilisant ces délimiteurs
	int i = 0;
	while (cutteds != NULL)
	// parcourt toutes les sous-chaînes et pour chaque sous-chaîne, elle fait une action différente en fonction de son index 'i'
	{
		if (i == 0) // nous remplissons la propriété text de notre choix avec la première sous-chaîne
		{
			ch.text = set_text_property(ch.text, cutteds);
			printf("\n");
		}
		else
		{ // nous créons un nouveau chapitre en utilisant la sous-chaîne courante
			cutteds = Corrigation_de_ProcessChoice(cutteds);
			ch.nextChapter = set_text_property(ch.nextChapter, cutteds);
			// ch.nextChapter = create_chapter(cutteds);
		}
		cutteds = strtok(NULL, delim);
		i++;
	}

	// ajoutons le choix 'ch' à la liste des choix dans le chapter actuel 'chap' en l'ajoutant à l'ind 'chap->choice_count' de la liste
	chap->choices[chap->choice_count] = ch; // incrémenter la valeur de 'chap->choice_count'
	chap->choice_count++;
}

chapter create_chapter(char *chapter_name)
{
	//ROBUST
	if(chapter_name == NULL)
	{
		printf("Quelque chose ne vas pas avec chapter_name(create_chapter)\n");
		exit(14);
	}
	// VARIABLES
	char line[SIZE_LINE];
	int current_line_event = 1;
	int currentPart = 0;

	char *path = NULL;
	//ROBUST
	if(path != NULL)
	{
		printf("Quelque chose ne vas pas avec path(create_chapter)\n");
		exit(15);
	}	
	path = (char *)malloc((strlen("txt/") + strlen(chapter_name) + strlen(".txt")) * sizeof(char) + 1);
	//~~> contien le chemin d'accès au fichier txt que nous voulons ouvrir
	strcpy(path, "txt/");
	strcat(path, chapter_name); // suivie de 'chapter_name'(concaténation)
	strcat(path, ".txt");		// et de '.txt'

	FILE *file = fopen(path, "r");
	// crée un chemin vers le fichier txt à partir du nom du chapitre et stocke dans 'path'
	if (file == NULL)
	{
		printf("\nErreur fopen (file 1)\n");
		exit(1111);
	}

	// char buf[10] = "";
	chapter chap = {}; // {malloc(1), malloc(0), malloc(0)};
	char first_line_chars[4];


	// GAME

	while (fgets(line, SIZE_LINE, file) != NULL)
	{
		*first_line_chars = '\0';
		strncat(first_line_chars, line, 3); // extrait les 3 premiers caractères en les stockant dans 'first_line_chars'
		if (strcmp(first_line_chars, "###") == 0)
		// Si ces 3 premiers caractères correspondent à 'part_seperator'
		{
			// Alors currentPart est incrémentée
			currentPart++;
		}
		else // Sinon utilisé pour traiter la ligne en fonction de la valeur de 'currentPart'
		{
			switch (currentPart)
			{
			// on est dans la part 1 : décrit la description du chapitre
			case 0:
				ProcessDescription(&chap, line);
				break;
			case 1:
				ProcessEvent(&chap, line, current_line_event);
				current_line_event++;

				break;

			// on est dans la part 2 : décrit l'événement du chapitre
			case 2:
				ProcessChoice(&chap, line);
				//~~> affiche l'événement en cours et les choix disponibles.

				break;

			case 3:

				ProcessAfterDescription(&chap, line);
				break;
			}
		}
	}
	fclose(file);

	return chap;
}


char *displayChapter(chapter chap, Stdt main_character)
{
	// fighter1
	char name1[SIZE_NAMES] = "Boris";
	char sname1[SIZE_NAMES] = "Jackson";
	Stdt fighter1 = createFighter(name1, sname1);
	// fighter2
	char name2[SIZE_NAMES] = "Adama";
	char sname2[SIZE_NAMES] = "Younga";
	Stdt fighter2 = createFighter(name2, sname2);
	// fighter3
	char name3[SIZE_NAMES] = "Etienne";
	char sname3[SIZE_NAMES] = "Wojdilot";
	Stdt fighter3 = createFighter(name3, sname3);
	// fighter4
	char name4[SIZE_NAMES] = "Lucas";
	char sname4[SIZE_NAMES] = "Traoré";
	Stdt fighter4 = createFighter(name4, sname4);
	Stdt tab_fighter[4] = {fighter1, fighter2, fighter3, fighter4};
	int lu;
	int user_choice = 0, count = 0;
	// printf("%s", chap.description);
	displayTxt(strlen(chap.description), chap.description);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~XTECH DVENTURE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n");
	// EVENT DU JEU
	switch (chap.event->type_event)
	{
	case 0:
		break;
	case 1:
		// combat contre un monstre
		displayBeforeFight(tab_fighter[chap.event->n_fighter], main_character);
		fight(main_character, tab_fighter[chap.event->n_fighter]);
		break;

	case 2:
		// modification de stat
		switch (chap.event->type_stat)
		{
		case 1:
			// fame
			if (chap.event->positive_or_negative == 1)
			{
				// c'est un malus de stat
				main_character.fame -= chap.event->n_stat;
				// Si une Stat inf à 0 alors remit à 0
				if (main_character.fame < 0)
				{
					main_character.fame = 0;
				}
				printf("Vous avez perdu %d de fame !\n", chap.event->n_stat);
			}
			else
			{
				// c'est un bonus de stat
				main_character.fame += chap.event->n_stat;
				// Si une Stat sup à 100 alors remit à 100
				if (main_character.fame > 100)
				{
					main_character.fame = 100;
				}
				printf("Vous avez gagné %d de fame !\n", chap.event->n_stat);
			}
			break;

		case 2:
			// intellect
			if (chap.event->positive_or_negative == 1)
			{
				// c'est un malus de stat
				main_character.intellect -= chap.event->n_stat;
				// Si une Stat inf à 0 alors remit à 0
				if (main_character.intellect < 0)
				{
					main_character.intellect = 0;
				}
				printf("Vous avez perdu %d d'intelligence !\n", chap.event->n_stat);
			}
			else
			{
				// c'est un bonus de stat
				main_character.intellect += chap.event->n_stat;
				// Si une Stat sup à 100 alors remit à 100
				if (main_character.intellect > 100)
				{
					main_character.intellect = 100;
				}
				printf("Vous avez gagné %d d'intelligence !\n", chap.event->n_stat);
			}
			break;
		case 3:
			// power
			if (chap.event->positive_or_negative == 1)
			{
				// c'est un malus de stat
				main_character.power -= chap.event->n_stat;
				// Si une Stat inf à 0 alors remit à 0
				if (main_character.power < 0)
				{
					main_character.power = 0;
				}
				printf("Vous avez perdu %d de force !\n", chap.event->n_stat);
			}
			else
			{
				// c'est un bonus de stat
				main_character.power += chap.event->n_stat;
				// Si une Stat sup à 100 alors remit à 100
				if (main_character.fame > 100)
				{
					main_character.fame = 100;
				}
				printf("Vous avez gagné %d de force !\n", chap.event->n_stat);
			}
			break;
		case 4:
			if (chap.event->positive_or_negative == 1)
			{
				// c'est un malus de stat
				main_character.wellness -= chap.event->n_stat;
				// Si une Stat inf à 0 alors remit à 0
				if (main_character.wellness < 0)
				{
					main_character.wellness = 0;
				}
				printf("Vous avez perdu %d de mental !\n", chap.event->n_stat);
			}
			else
			{
				// c'est un bonus de stat
				main_character.wellness += chap.event->n_stat;
				// Si une Stat sup à 100 alors remit à 100
				if (main_character.wellness > 100)
				{
					main_character.wellness = 100;
				}
				printf("Vous avez gagné %d de mental !\n", chap.event->n_stat);
			}
		}
	case 3:

		// modification inventaire
		if (chap.event->add_or_remove_bag == 1)
		{
			// c'est un malus de stat
			removeItem(&main_character, chap.event->id_object);
			displayBag(&main_character);
		}
		else
		{
			// c'est un ajout d'objet dans l'inventaire
			addItem(&main_character, chap.event->id_object);
			displayBag(&main_character);
		}
		break;
	}

	displayStat(main_character);

	if (chap.choice_count != 1)
	{
		for (int i = 0; i < chap.choice_count; i++)
		{
			printf("\n%s", chap.choices[i].text);
		}
		// CHOIX DU JEU
		do
		{
			printf("Choix : \n");
			lu = scanf("%d", &user_choice);
			fflush(stdin);
			if (user_choice < 1 || user_choice > chap.choice_count)
			{
				printf("Veuillez saisir une reponse valide : ");
			}
			else
			{
				count = 1;
			}
		} while (lu == 0 || count == 0);

		system("clear");
		displayTxt(strlen(chap.after_description), chap.after_description);
		return chap.choices[user_choice - 1].nextChapter;
	}
	else
	{
		return chap.choices[0].nextChapter;
	}
}
