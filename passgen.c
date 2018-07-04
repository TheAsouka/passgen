#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//usage : ./passgen <passwordlenght>

int main(int argc, char const *argv[]) {
  //printf("%d\n",argc); Nombre d'arguments
  //printf("%s\n",argv[1]); //Valeur de l'arguments
  if(argv[1]==NULL){
    printf("%s\n","usage : ./passgen <passwordlenght>");
    exit(0);
  }

  int passlenght=strtol(argv[1],NULL,10); // string to long(string, endptr, base)
  char passwd[passlenght]; //déclaration du tableau qui va contenir les chars

  //printf("%lu\n",sizeof(passwd)); // print la taille en octet du tableau , == 15 , car 1 char = 1 octet

  srand(time(NULL)); //initialise le generateur de random number avec le nbr de secondes écoulées depuis 01/01/1970 , donc avec un nbr different a chaque exec

  //ASCII 127 chars mais seulement entre 33 et 127 sont imprimables
  //127 == del , donc on l'exclu

  printf("%s\n","Votre mot de passe : " );
  for(int i=1;i<=passlenght;++i)
  {
    int superandom_numb=rand(); // genere un grand nombre pseudo-aleatoire
    int rand_numb=superandom_numb%93; // modulo pour qu'il soit compris entre 0 et 93
    rand_numb=rand_numb+33; // compris entre 33 et 126 donc que des chars imprimables
    //printf("%d\n",rand_numb);
    //printf("%c\n",rand_numb);
    passwd[i]=printf("%c",rand_numb); //append le tableau du char géneré
    printf("%c",passwd[i]);// print le password
  }
  printf("\n");
  return 0;
}
