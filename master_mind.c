#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "master_mind.h"
#define NB_COULEUR 5
#define TAILLE_CODE 4
#define TENTATIVE_MAX 3

int verifSaisie (const char*, char*, int,int);
void afficherCode(char*, int );


void masterMind()
{
    printf("\t\n\n------ MASTERMIND ------\n\n");



//variables
    const char COULEUR[] = {'R','B','J','V','O'};

    char saisie_ut[TAILLE_CODE] = {0};
    char code[TAILLE_CODE] = {0};

    int tentative = 0 ;
    int rejouer = 0;

do
{

//generation aleatoire du code
    srand(time(NULL));

    for (int i=0; i<TAILLE_CODE; i++)
   {
       int id_couleur = rand () % NB_COULEUR;

            int cmpt_presance = 0;
//Cas ou la couleur est deja presente dans le code
            for (int j=0; j<TAILLE_CODE; j++)
            {
                if (COULEUR[id_couleur ]== code[j])
                    cmpt_presance ++;
            }

        if (cmpt_presance == 0)
        {
            code[i] = COULEUR[id_couleur];

        }

        else i--;
   }

//saisie utilisateur
    printf("\nTrouver le code de %d couleurs\n ",TAILLE_CODE);
    printf("COULEUR [ rouge(R) - bleu(B) - jaune(J) - vert(V) - orange(O) ]\n\n");

    tentative = 0;
   do
    {
        int verif = 0;
        do
        {
            printf(">");
            fflush(stdin);
            scanf("%c%c%c%c",saisie_ut, saisie_ut+1, saisie_ut+2, saisie_ut+3);

//Controle saisie

        verif = 0;
        if (verifSaisie(COULEUR,saisie_ut,NB_COULEUR,TAILLE_CODE)!=0){
              printf("\n\t< ERREUR > un ou plusieurs caracteres ne sont pas conformes\n\n");
            verif++;
            }
        }while(verif != 0);
        tentative++;

// boucle pour comparer la saisie et le code secret
    int c_bp = 0, c_presente = 0;//c_bp = couleur bien place

    for(int i = 0; i<TAILLE_CODE; i++)
    {
        //Cas couleur bp
        if (saisie_ut[i] == code[i])
            c_bp ++;

        //Cas couleur presente
        for(int j = 0; j<TAILLE_CODE;j++)
        {
            if (code[j] == saisie_ut[i] )
                c_presente ++;
        }
    }


    if(c_bp == TAILLE_CODE)
    {
        printf("\nBravo vouis avez trouve le code couleur\n");
        printf("Vous etes le MASTERMIND\n");
        break;
    }
    else
    {
        printf("\ntentative %d/%d\n",tentative,TENTATIVE_MAX);
        printf("Couleurs bien placees : %d\n",c_bp);
        printf("Couleurs presentes : %d\n\n",c_presente);
    }

    //Message defaite
    if(tentative == TENTATIVE_MAX)
    {
        printf("\nPERDU ! Le code couleur etait: ");
        afficherCode(code,TAILLE_CODE);
    }


    }while(tentative < TENTATIVE_MAX);




   //rejouer ?
        do
        {
        printf("\nRejouer?\n Oui(1)\tNon(2) :");
        scanf("%d",&rejouer);

        if(rejouer != 2 && rejouer != 1){
            printf("\nERREUR saisie\n");
        }

        }while(rejouer != 2 && rejouer != 1);


} while(rejouer == 1);

    //return 0;
}

void afficherCode(char code[], int essai_max)
{
    for(int i = 0; i<essai_max; i++)
    {
        printf("%c",code[i]);
    }
    printf("\n");
}

int verifSaisie (const char COULEUR[], char saisie_ut [], int nombre_couleur,int taille_code)
{
    int c_presente = 0;

        for(int i = 0; i<nombre_couleur; i++)
    {
        for(int j = 0; j<taille_code;j++)
        {
            if (COULEUR[i] == saisie_ut[j] )
                c_presente ++;
        }

    }
    if (c_presente == taille_code)
            return 0;

        else
        {return -1;}
}
