#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include "../task4/string.c"
#include "function_pendu.c"

int main(int nargs, char** args) {

  // initlalize the random generator
  srand(clock());
  do{
    int nombre_aleatoire = rand() % 49;
    int nombre_essai = nombre_essai_mot(nombre_aleatoire);
    char* mot_a_deviner = mot_a_deviner(nombre_aleatoire);
    char* mot_a_deviner_pour_afficher = creer_tiret(strlen(*mot_a_deviner);

    while (nombre_essai != 0) {
      printf("Vous avez %d coups pour deviner le mot :\n", nombre_essai);
      printf("%s\n", mot_a_deviner_pour_afficher);
      do{
        printf("?");
        char lettre = lire_lettre();
        printf("\n");
      }while(lettre == NULL);
      if(verif_lettre(lettre, *mot_a_deviner, *mot_a_deviner_pour_afficher)){
        printf("Bravo !\n");
        break;
      }     
    }
    if(nombre_essai == 0){
      printf("Vous avez perdu !\n");
      printf("Le mot était : %s\n", *mot_a_deviner);
    }
  }while(continuer_verif());
  printf("Bye.\n");
}
