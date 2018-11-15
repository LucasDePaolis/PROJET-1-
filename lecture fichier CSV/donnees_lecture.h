#ifndef DONNEES_LECTURE_H_INCLUDED
#define DONNEES_LECTURE_H_INCLUDED


typedef struct
{
   int  poul;
   char *   jours;
/*   char *   mois;
   char *   heures;
   char *   minutes;
   char *   secondes; */
   int millis;
}contact_infos;

typedef enum
{
   POUL,
  /* JOURS,
   MOIS,
   HEURES,
   MINUTES,
   SECONDES, */
   MILLIS,
   NB_TYPE
}infos_type;

 char * str_dup (const char * str);
contact_infos * get_contact (const char * nomcontact);

#endif // DONNEES_LECTURE_H_INCLUDED
