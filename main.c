#include <stdio.h>
#include <stdlib.h>
#include "jeux.h"
#include "morpion.h"
#include "outils.h"



int main()

{   A_PROPOS("Bibliotheque de Jeux\n");
    int choix = 0;
    do
    {
    afficherBibliotheque();
    choix = 0;

     printf("\nA quel jeu voulez-vous jouer? >   \t");
     fflush(stdin);
     scanf("%d", &choix);


     selectionJeux(choix);


    }while(choix != 0);
return 0;
}
