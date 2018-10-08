#include <stdio.h>

#define TRUE 1
#define FALSE 0

void imprimir_susp(char sus_130)
{
  printf("Está suspés el MHP 130? %s\n", (sus_130)?"Si":"No");
}

void consultar_susp(char *sus_130, char ts_sus_130, char parlament_sus_130)
{
  *sus_130 = (ts_sus_130)||(parlament_sus_130);
}

void aplicar_efectos_interlocutoria(char *p_sus_130, char *p_ts_sus_130, char parlament_sus_130)
{
  *p_ts_sus_130 = TRUE;
  consultar_susp(p_sus_130, *p_ts_sus_130, parlament_sus_130);
  imprimir_susp(*p_sus_130);
}

void aplicar_efectos_resolucio(char *p_sus_130, char ts_sus_130, char *p_parlament_sus_130)
{
  *p_parlament_sus_130 = FALSE;
  consultar_susp(p_sus_130, ts_sus_130, *p_parlament_sus_130);
  imprimir_susp(*p_sus_130);
}

int main()
{
  char sus_130 = FALSE;
  char ts_sus_130 = FALSE;
  char parlament_sus_130 = FALSE;

  printf("ANTES DA INTERLOCUTORIA\n");
  consultar_susp(&sus_130, ts_sus_130, parlament_sus_130);
  imprimir_susp(sus_130);

  printf("DESPOIS DA INTERLOCUTORIA, ANTES DE RESOLUCIÓ PARLAMENT 02/10/2018\n");
  aplicar_efectos_interlocutoria(&sus_130, &ts_sus_130, parlament_sus_130);

  printf("DESPOIS DA INTERLOCUTORIA, DESPOIS DE RESOLUCIÓ PARLAMENT 02/10/2018\n");
  aplicar_efectos_resolucio(&sus_130, ts_sus_130, &parlament_sus_130);

  return 0;
}

