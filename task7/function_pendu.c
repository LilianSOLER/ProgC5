//array of words
char *words[] = {
    "alligator",
    "ant",
    "bear",
    "bee",
    "bird",
    "cat",
    "chicken",
    "cow",
    "crocodile",
    "deer",
    "dog",
    "dolphin",
    "duck",
    "elephant",
    "fish",
    "fly",
    "fox",
    "frog",
    "giraffe",
    "goat",
    "goose",
    "gorilla",
    "hamster",
    "horse",
    "kangaroo",
    "kitten",
    "lion",
    "lobster",
    "monkey",
    "mouse",
    "octopus",
    "owl",
    "panda",
    "penguin",
    "pig",
    "rabbit",
    "rat",
    "rhinoceros",
    "sheep",
    "sloth",
    "snake",
    "spider",
    "squirrel",
    "tiger",
    "turtle",
    "whale",
    "zebra"
};


char *get_mot_a_trouver(){
    int i = rand() % (sizeof(words) / sizeof(char *));
    return words[i];
};

char get_char(){
    char c = 0;
    c = getchar();
    while (getchar() != '\n'){
      c = getchar();
    }
    return c;
}

int is_in_mot(char lettre, char *mot_a_trouver,int *lettre_trouver,int longueur_mot){
  int lettre_in_mot = 0;
  printf("La lettre est '%c' \n",lettre);
  for(int i = 0; i < longueur_mot; i++){
    printf("%c \n", mot_a_trouver[i]);
    if(mot_a_trouver[i] == lettre){
      lettre_in_mot = 1 ;
      lettre_trouver[i] = 1;
    }      
  }
  return lettre_in_mot;
}

int gagne(int *lettre_trouver,int longueur_mot){
  int gagne = 1;
  for(int i = 0; i < longueur_mot; i++){
    if(lettre_trouver[i] == 0){
      gagne = 0;
    }
  }
  return gagne;
}