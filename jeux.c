#include <stdio.h>
#include <stdlib.h>
#include "jeux.h"
#include "morpion.h"
#include "outils.h"
#include "master_mind.h"
#include "pendu.h"
#include "juste_prix.h"




void afficherBibliotheque()
{
    printf("\nMes jeux disponible (%d)\n",NB_JEUX);
    printf("%s\n",INDEX_JEUX);
}

void selectionJeux (int saisie)
{
    switch (saisie)
   {
    case 1 : printf("\nDemarage de MORPION...\n\n");
            morpion();
    break;

    case 2 : printf("\nDemarage de MASTERMIND...\n");
            masterMind();
    break;

    case 3 : printf("\nDemarage du PENDU...\n");
            pendu();
    break;

    case 4 : printf("\nDemarage du JUSTE PRIX...\n");
            juste_prix();
    break;

    case 0 : printf("A bientot !");
    break;

    default : printf("Selection invalide");
    break;
   }



}

