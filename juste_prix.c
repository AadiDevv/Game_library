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
    int result = 0;
do
{
    //generation nb aleatoire
    srand(time(NULL));
    nb_aleatoire = (rand() % (NB_MAX-NB_MIN +1)) + NB_MIN;

    // saisie ut
    printf ("\nLe prix est un nombre entier compris entre %d et %d\n",NB_MIN,NB_MAX);


    do
    {
        //saisie ut et gestion des erreurs
        do {
            printf("> ");
            result = scanf("%d", &nb_ut);

            // Vider le buffer d'entr�e si l'entr�e n'est pas un nombre valide
            if (result != 1 || nb_ut<0 || nb_ut>100) {
                while (getchar() != '\n'); // Ignore tous les caract�res jusqu'� la fin de la ligne
                printf("\nErreur, veuillez saisir un nombre entier compris entre [0-100]\n\n");
            }
        } while (result != 1);


        int distance = nb_ut-nb_aleatoire;

        //Cas +
        if (nb_ut < nb_aleatoire){
             if((distance) > -5)
                printf("\n%d.Tu brule! c'est un peu plus que %d\n\n", tentative,nb_ut);
            else if((distance) >= -10)
                printf("\n%d.Tu te rappronches... c'est plus que %d\n\n", tentative,nb_ut);
            else
                printf("\n%d.C'est plus que %d\n\n", tentative,nb_ut);
        }


        //Cas -
        if (nb_ut > nb_aleatoire){
            if((distance) < 5)
                printf("\n%d.Tu brules! c'est un peu moin que %d\n\n", tentative,nb_ut);
            else if(distance <= 10)
                printf("\n%d.Tu te rappronches... c'est moin que %d\n\n", tentative,nb_ut);
            else
                printf("\n%d.C'est moin que %d\n\n", tentative,nb_ut);
        }


        //Cas victoire
        if (nb_ut == nb_aleatoire)
           {
            printf("\nBRAVO! Victoire en %d essaies! Le juste prix etait bien %d\n",tentative,nb_aleatoire);
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
