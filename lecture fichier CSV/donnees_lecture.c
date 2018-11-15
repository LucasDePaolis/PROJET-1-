#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees_lecture.h"

#define DELIM        ";"
#define BUFF_SIZE    128

char * str_dup (const char * str)
{
   char * dup = NULL;


   if (str != NULL)
   {
      size_t size = strlen (str) + 1;
      dup = malloc (size);

      if (dup != NULL)
      {
         memcpy (dup, str, size);
      }
   }
   return dup;
}



void free_contact_infos (contact_infos ** p)
{
   if (p != NULL && *p != NULL)
   {
      free ((*p)->poul);
   /* free ((*p)->jours);
      free ((*p)->mois);
      free ((*p)->heures);
      free ((*p)->minutes);
      free ((*p)->secondes); */
      free ((*p)->millis);

      free (*p);
      *p = NULL;
   }
}


contact_infos * get_contact (const char * nomcontact)
{
   contact_infos  *  infos = NULL;
   FILE           *  file  = NULL;
   char           *  token = NULL;
   char              buff [BUFF_SIZE];
   int tableau[10];
   int j=0;
   int  UserChoice; // A ENLEVER


   file = fopen ("nomcontact.csv", "r");
   printf("choisir le mode");
   scanf("%d",&UserChoice);// A ENLEVER



   if (file != NULL)
   {
      while((fgets (buff, BUFF_SIZE, file)) != NULL)
      {
         char *   p = buff;
         int      i = 0;


         infos = malloc (sizeof (* infos));

         if (infos != NULL)
         {

            while ((token = strtok (p, DELIM)) != NULL)
            {
               if (i == 0)
                p = NULL;

               switch (i)
               {
                  case POUL:
                      {
                     int poul = strtol (token, NULL, 10);
                     infos->poul = poul;
                     if (UserChoice == 1 || UserChoice == 3){
                        tableau[j]= infos->poul;
                        j++;
                     }

                      }

                    printf("Nombre de pulsations par minutes (poul):%d \n",infos->poul);
                     break;

 /*                 case JOURS:
                     infos->jours = str_dup (token);
                     printf("Date : %s/",infos->jours);
                     break;

                  case MOIS:
                     infos->mois = str_dup (token);
                     printf("%s\n",infos->mois);
                     break;

                  case HEURES:
                     infos->heures = str_dup (token);
                     printf("%s:",infos->heures);
                     break;

                  case MINUTES:
                     infos->minutes = str_dup (token);
                     printf("%s:",infos->minutes);
                     break;

                  case SECONDES:
                     infos->secondes = str_dup (token);
                     printf("%s \n\n",infos->secondes);
                     break;
*/
                  case MILLIS:
                      {
                     int millis = strtol (token, NULL, 10);
                     infos->millis = millis;
                     if (UserChoice == 2 || UserChoice == 4){
                        tableau[j]= infos->millis;
                        j++;
                     }

                      }
                      break;


                  default:
                    break;

               }
               i++;
            }
         }
      }
    int valeurtemporaire, x, w;
    int tailletableau=j;

     for (x=0; x<tailletableau; x++)
     {
        for(w=x; w<tailletableau; w++)
        {
            if (UserChoice ==3 || UserChoice ==4)
            {
                if(tableau[w]>tableau[x])  /* si on inverse le signe d'inégalité
                                            on aura le trie croissant */
                {
                    valeurtemporaire = tableau[x];
                    tableau[x] = tableau[w];
                    tableau[w] = valeurtemporaire;
                }

            }
            else if (UserChoice ==1|| UserChoice ==2)
            {
                if(tableau[w]<tableau[x])  // DECROISSANT
                {
                    valeurtemporaire = tableau[x];
                    tableau[x] = tableau[w];
                    tableau[w] = valeurtemporaire;
                }
            }
        }
     }

      for (int k = 0 ; k < j ; k++) //mettre j pour le poul k<j
    {
        printf("%d bpm/ ", tableau[k]);
    }
      fclose (file);
   }
   return infos;
}
