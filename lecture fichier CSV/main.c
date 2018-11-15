#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees_lecture.h"

#define DELIM        ";"
#define BUFF_SIZE    128



int main (void)
{
   contact_infos * infos = get_contact ("contacts.csv");
   free_contact_infos (& infos);
   return EXIT_SUCCESS;
}
