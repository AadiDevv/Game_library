#include <stdio.h>
#include <stdlib.h>
#include "jeux.h"
#include "morpion.h"
#include "outils.h"



int main()

{   A_PROPOS("|---< GAME LIBRARY >---|\n");
    int choix = 0;
    do
    {
    afficherBibliotheque();
    choix = 0;

     printf("\nA quel jeu voulez-vous jouer?   > ");
     fflush(stdin);
     scanf("%d", &choix);


     selectionJeux(choix);


    }while(choix != 0);
return 0;
}
