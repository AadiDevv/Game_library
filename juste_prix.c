#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "juste_prix.h"

#define NB_MAX 100
#define NB_MIN 0
#define MAX_TENTATIVE 10



void juste_prix()
{
    printf("\t\n\n------ LE JUSTE PRIX ------\n\n");

//variables
    int nb_aleatoire = 0, nb_ut = 0;
    int tentative = 1;
    int rejouer = 0;

do
{
    //generation nb aleatoire
    srand(time(NULL));
    nb_aleatoire = (rand() % (NB_MAX-NB_MIN +1)) + NB_MIN;

    // saisie ut
    printf ("\nLe prix est un nombre entier compris entre %d et %d\n",NB_MIN,NB_MAX);


    do
    {   printf("> ");
        scanf("%d",&nb_ut);

        //Cas +
        if (nb_ut < nb_aleatoire)
            printf("\n%d.C'est plus que %d\n\n", tentative,nb_ut);

        //Cas -
        if (nb_ut > nb_aleatoire)
            printf("\n%d.C'est moin que %d\n\n", tentative,nb_ut);

        //Cas victoire
        if (nb_ut == nb_aleatoire)
           {
            printf("\nBRAVO! Victoire en %d essaie! Le juste prix etait %d\n",tentative,nb_aleatoire);
            break;
           }

        tentative++;

    }while (tentative < 10);

        //cas defaite
        if(nb_ut != nb_aleatoire)
        {
        printf("Vous avez echouez! Le juste prix etait %d\n",nb_aleatoire);
        }


        //rejouer ?
        do
        {
        printf("Rejouer?\n Oui(1)\tNon(2) :");
        scanf("%d",&rejouer);

        if(rejouer != 2 && rejouer != 1)
        printf("\nERREUR saisie\n");
        }while(rejouer != 2 && rejouer != 1);


} while(rejouer == 1);

   // return 0;
}
