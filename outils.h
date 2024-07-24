#include <stdio.h>
#include <stdlib.h>
//#define DEBUG
//1
#define VERSION "V1"
#define AUTEUR "Aaditya <satyalaaditya@hotmail.fr>"
//2
#define A_PROPOS(titre) printf("\n%s\n",titre);\
                        printf("\tVersion : %s (%s,%s)\n",VERSION,__DATE__,__TIME__);\
                        printf("\tAuteur : %s\n",AUTEUR);
//4
#define LOG_CRITIC "CRITIC"
#define LOG_ERROR "ERROR"
#define LOG_DEBUG "DEBUG"

#ifdef DEBUG
#define DEBUG_LOG(niveau,message) printf("\n[%s] : %s \n(%s ; LIGNE :%d)\n",niveau,message,__FILE__,__LINE__);
#else
#define DEBUG_LOG(niveau,message)//sans actions, pour ne pas avoir d'erreurs
#endif


