
#ifndef STRUCTURES_H
#define STRUCTURES_H

#define SIZE_NAMES 100
#define MAX_BAG_SIZE 8
#define SIZE_LINE 10000
#define MAX_CHOICE 10
#define SIZE 100000

typedef struct
{
	char name[SIZE_NAMES];
	char sname[SIZE_NAMES];
	int fame;
	int health;                    
	int power;
	int intellect;
	int wellness;
	int dodge;
	int defence;
} Stdt; // Main character

typedef enum
{
  //intellect stuff
  Pencil, Book, Computer,
  //power stuff
  Knife, Knuckles, 
  //fame stuff
  Sunglasses, Jacket,
  //wellness stuff
  Girlfriend,
  //empty
  Vide  
} Bag; // Items

typedef struct
{
	char *text;
	char *nextChapter;
} Choice;

typedef struct
{
    int type_event;
    int n_fighter;
    int type_stat;
    int n_stat;
	char *id_object;
	char *add_or_remove_bag;
    char *positive_or_negative;
}Event;

typedef struct
{
    char *description;
    Event *event;
    Choice *choices;
    int choice_count;
	char *after_description;
} chapter;

typedef struct 
{
    Stdt a;
    Bag b;
    int selected_choice;//stocke l'option de choix sélectionnée par l'utilisateur
} SaveData;


#endif
