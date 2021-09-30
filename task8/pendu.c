#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include <ctype.h>

#include "../task4/string.c"
#include "func.c"


int main(int nargs, char** args) {
  // initlalize the random generator
  srand(clock());

  while (1){
      // initlalize the variables
    char *mot_a_trouver = get_mot_a_trouver();
    printf("Le mot a trouver est : %s\n", mot_a_trouver);
    int longueur_mot = strlen(mot_a_trouver);
    char lettre = 0;
    int *lettre_trouver = malloc(longueur_mot*sizeof(int));
    int nb_essais = 2*longueur_mot;
    printf("Nombre d'essais : %d\n", nb_essais);

    // initlalize array of boolean (1 if the letter is in the word, 0 otherwise)
    for(int i = 0; i < longueur_mot; i++) {
      *(lettre_trouver + i) = 0;
    }

    //Game loop

    while (nb_essais > 0 && !gagne(lettre_trouver,longueur_mot)) {

        //print array of boolean
      printf("{");
      for(int i = 0; i < longueur_mot; i++) {
        (i != longueur_mot - 1) ? printf(" %d ,", *(lettre_trouver + i)) : printf(" %d", *(lettre_trouver + i));
      }
      printf("}\n");

        printf("Vous avez %d coups pour deviner le mot : \n", nb_essais);
        
        //display the word with the letters already found
        for(int i = 0; i < longueur_mot; i++) {
        (*(lettre_trouver + i)== 1) ? printf("%c", mot_a_trouver[i]) : printf("_ ");
      }

      printf("\n");
      printf("?");

      //get the letter
      lettre = get_char();
      
      if(!is_in_mot(lettre, mot_a_trouver,lettre_trouver,longueur_mot)){
        nb_essais--;
      }
      
      printf("\n");

    }

    gagne(lettre_trouver,longueur_mot) ? printf("Vous avez gagne. ") : printf("Vous avez perdu ! Le mot était : %s\n",mot_a_trouver);

    //ask if the player want to continue
    printf("Voulez-vous continuer ? (y/n)");
    char reponse = get_char();
    if(reponse == 'n'){
      break;
    }
    free(lettre_trouver);
  }

  printf("Bye.\n");
}
