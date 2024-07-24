#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pendu.h"
#define POINT_DE_VIE 10

void pendue()
{
    printf("\t\n\n------ LE PENDU ------\n\n");
//var
    char mot_secret[]="LOL";

    int taille_ms = strlen(mot_secret), rejouer;

    char saisie_ut [taille_ms];
    char saisie_lettre=' ';
    char mot_trouver [taille_ms+1];

//Initialisation contenue mot_trouver
    for(int i=0; i<taille_ms; i++)
    mot_trouver[i] = '-';
    mot_trouver[taille_ms]='\0';

//Instruction
    printf("Intructions => Le mot ne comporte pas d'espace, et est en majuscule\n");
    printf("Trouver le mot %s\n",mot_trouver);
    int pv = POINT_DE_VIE;
    int lt_trv;
//DEBUT DU JEUX
do
{
  do{
    //saisie ut
    printf("\nProposez une lettre ou un mot >");
    fflush(stdin);
    fgets(saisie_ut,taille_ms+1,stdin);

    //nb de lettres trouver
    lt_trv = 0;

    //pour savoir si il a rentrer un mot ou une lettre
    int taille_saisie = strlen(saisie_ut);

        // taille - espace saisie
    if ((taille_saisie-1)<= 1)
    {
           for(int i=0; i<taille_ms;i++)
            {
             if(saisie_lettre == mot_secret[i])
               {    mot_trouver[i]= saisie_lettre;
                    lt_trv++;
               }

            }
            if(strcmp(mot_secret,mot_trouver)== 0)
            {
                printf("%s | Bravo ! Vous avez trouver le mot\n",mot_secret);
                break;
            }

            if (lt_trv != 0)
            {
                printf("%s | Oui! ! Lettre %c presente | pv : %d\n",mot_trouver,saisie_lettre,pv);
            }
            if(lt_trv == 0)
            {    pv--;
                 printf("%s | Dommage ! Lettre %c non presente | pv : %d\n",mot_trouver,saisie_lettre,pv);

            }
    }

    if ((taille_saisie - 1) > 1)
    {

        if ( strcmp(saisie_ut,mot_secret) == 0)
        {
            printf("%s | Bravo ! Le mot a etait touver | pv : %d\n",mot_secret,pv);
            break;
        }


        else
        {
            pv--;
            printf("Dommage %s n'est pas le mot | pv : %d\n",saisie_ut,pv);

        }
    }

}while(pv != 0);

    if (pv == 0)
    {
        printf("pv %d | Vous avez perdu!\n",pv);
    }
    do
    {
        printf("\nRejouer ? Oui(1) Non(2)");
        scanf("%d",&rejouer);
        if(rejouer != 1 && rejouer != 2)
            printf("Je n'ai pas compris votre saisie\n");
    }while(rejouer != 1 && rejouer != 2);

}while(rejouer == 1);

    printf("A bientot...");



   // return 0;
}
