#include <stdio.h>

#define TRUE 1
#define FALSE 0

char sus_130 = FALSE;
char bloqueo_ambito_sup = FALSE;

void consultar_susp()
{
  printf("Está suspés el MHP 130? %s\n", (sus_130)?"Si":"No");
}

void aplicar_efectos_interlocutoria()
{
  sus_130 = TRUE;
  bloqueo_ambito_sup = TRUE;
}

void aplicar_efectos_resolucio()
{
  if (!bloqueo_ambito_sup)
  {
    sus_130 = FALSE;
  }
}

int main()
{
  printf("ANTES DA INTERLOCUTORIA\n");
  consultar_susp();

  aplicar_efectos_interlocutoria();
  printf("DESPOIS DA INTERLOCUTORIA, ANTES DE RESOLUCIÓ PARLAMENT 02/10/2018\n");
  consultar_susp();

  printf("DESPOIS DA INTERLOCUTORIA, DESPOIS DE RESOLUCIÓ PARLAMENT 02/10/2018\n");
  aplicar_efectos_resolucio();
  consultar_susp();

  return 0;
}

