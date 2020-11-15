#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  char m[128];
  char k[128];
  time_t t;/*abilito il generatore di numero casuali usando il tempo attuale*/
  int a;
  char c[128];
  char m_cifr[128];
  printf("Inserisci manualmente una stinga M di testo lunga al massimo 128 caratteri\n");
  fgets (m, 128, stdin); /*controllo che la lunghezza massima della stringa non superi i 128 caratteri*/
  printf("La stringa inserita è %s\n", m);
  int opzione;
  printf("Scegli come vuoi agire digitando 1 oppure 2\n");
  scanf("%d",&opzione);
  getchar();//pulisco il buffer
  if (opzione==1)
  {
    printf("Ora inserisci manualmente una stringa K di testo di lunghezza maggiore o uguale alla stringa M\n");
    fgets (k, 128, stdin);
    if(strlen(k)<strlen(m))
    {
      printf("La stringa K deve essere maggiore o uguale di M\nRiesegui il programma\n");
    }
    else
    {
      printf("La tua stringa K è %s\n", k);
      for (a=0; a<strlen(m); a++)//faccio cifrare tutte le caselle della stringa
      {
        c[a]=m[a]^k[a];
      }
      printf("La stringa cifrata C è %x\n", c[(unsigned char)a]);
      for (a=0; a<strlen(m); a++)
      {
        m_cifr[a]=c[a]^k[a];
      }
      printf("la stringa M è %s\n", m_cifr);
    }
  }
  else if (opzione==2)
  {
    printf("La stringa K verrà generata casualmente\n");
    srand((unsigned)time(&t));
    for (a=0;a<strlen(m);a++)
    {
      k[a]=33+rand()%96;//genero un numero random togliendo i caratteri speciali
    }
    printf("La chiave k è %s\n",k);
    for (a=0; a<strlen(m); a++)
    {
      c[a]=m[a]^k[a];
    }
    printf("La stringa cifrata C è %x\n", c[(unsigned char)a]);
    for (a=0; a<strlen(m); a++)
    {
      m_cifr[a]=c[a]^k[a];
    }
    printf("la stringa M è %s\n", m_cifr);
  }
  else
    {
      printf("Devi rieseguire il programma\n");
    }

return 0;
}
