#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define MAX_NOME 30

enum id_diputat { PUIGDEMONT=0, JUNQUERAS, SANCHEZ, TURULL, RULL, COMIN, ROMEVA };
#define ID_DIPUTAT_PRIMER PUIGDEMONT
#define ID_DIPUTAT_ULTIMO ROMEVA
#define NUM_DIPUTATS ID_DIPUTAT_ULTIMO-ID_DIPUTAT_PRIMER+1

struct estat_diputat
{
  enum id_diputat id;
  char *nome;
  char esta_suspes;
  char suspes_pel_ts;
  char suspes_pel_parlament;
};

void imprimir_estat_diputats(struct estat_diputat **estat_diputats)
{
  struct estat_diputat *dip_actual;
  for (int i=ID_DIPUTAT_PRIMER;i<NUM_DIPUTATS;i++)
  {
    dip_actual = estat_diputats[i];
    printf("Está suspés %s? %s\n", (*dip_actual).nome, ((*dip_actual).esta_suspes)?"Si":"No");
  }
}

void actualitzar_estat_diputats(struct estat_diputat **estat_diputats)
{
  struct estat_diputat *dip_actual = NULL;
  for (int i = ID_DIPUTAT_PRIMER; i<NUM_DIPUTATS; i++)
  {
    dip_actual = estat_diputats[i];
    (*dip_actual).esta_suspes = ((*dip_actual).suspes_pel_ts) || ((*dip_actual).suspes_pel_parlament);
  }
  imprimir_estat_diputats(estat_diputats);
}

char *id_diputat_to_str(enum id_diputat id)
{
  switch (id)
  {
    case PUIGDEMONT: return "el MHP 130 (aka Puchi)";
    case JUNQUERAS:  return "Oriol Junqueras";
    case SANCHEZ:    return "Jordi Sànchez";
    case TURULL:     return "Jordi Turull";
    case RULL:       return "Josep Rull";
    case COMIN:      return "Toni Comin";
    case ROMEVA:     return "Raül Romeva";
    default:         return "";
  }
}

void init_estat_diputats(struct estat_diputat **estat_diputats)
{
  struct estat_diputat *dip_actual;
  for (int i=ID_DIPUTAT_PRIMER;i<NUM_DIPUTATS;i++)
  {
    dip_actual = (struct estat_diputat *)malloc(sizeof(struct estat_diputat));
    (*dip_actual).id = (enum id_diputat)i;
    (*dip_actual).nome = (char *)malloc(sizeof(char) * MAX_NOME);
    strcpy((*dip_actual).nome, id_diputat_to_str(i));
    (*dip_actual).esta_suspes = FALSE;
    (*dip_actual).suspes_pel_ts = FALSE;
    (*dip_actual).suspes_pel_parlament = FALSE;
    estat_diputats[i] = dip_actual;
//    printf("id: %d, nome: %s, esta_suspés? %s\n", (*dip_actual).id, (*dip_actual).nome, ((*dip_actual).esta_suspes)?"Si":"No");
  }

}

void liberar_memoria(struct estat_diputat **estat_diputats)
{
  struct estat_diputat *dip_actual = NULL;
  for (int i=ID_DIPUTAT_PRIMER;i<NUM_DIPUTATS;i++)
  {
    dip_actual = estat_diputats[i];
    free((*dip_actual).nome);
    free(dip_actual);
  }
  free(estat_diputats);
}

void aplicar_efectes_interlocutoria(struct estat_diputat **estat_diputats)
{
  struct estat_diputat *dip_actual=NULL;
  for (int i=ID_DIPUTAT_PRIMER;i<NUM_DIPUTATS;i++)
  {
    dip_actual = estat_diputats[i];
    switch ((*dip_actual).id)
    {
      case PUIGDEMONT:
      case JUNQUERAS:
      case SANCHEZ:
      case TURULL:
      case RULL:
      case ROMEVA:
        (*dip_actual).suspes_pel_ts = TRUE;
        break;
      case COMIN:
      default: break;
    }
  }
  actualitzar_estat_diputats(estat_diputats);
}

void aplicar_efectes_resolucio(struct estat_diputat **estat_diputats)
{
  struct estat_diputat *dip_actual=NULL;

  for (int i=ID_DIPUTAT_PRIMER;i<NUM_DIPUTATS;i++)
  {
    dip_actual = estat_diputats[i];
    switch ((*dip_actual).id)
    {
      case PUIGDEMONT:
      case JUNQUERAS:
      case SANCHEZ:
      case TURULL:
      case RULL:
      case ROMEVA:
        (*dip_actual).suspes_pel_parlament = FALSE;
        break;
      case COMIN:
      default: break;
    }
  }
  actualitzar_estat_diputats(estat_diputats);
}

int main()
{
  struct estat_diputat **estat_diputats = NULL;
  estat_diputats = (struct estat_diputat **)malloc(sizeof(struct estat_diputat)*NUM_DIPUTATS);

  init_estat_diputats(estat_diputats);

  printf("ANTES DA INTERLOCUTORIA\n");
  actualitzar_estat_diputats(estat_diputats);

  printf("DESPOIS DA INTERLOCUTORIA, ANTES DE RESOLUCIÓ PARLAMENT 02/10/2018\n");
  aplicar_efectes_interlocutoria(estat_diputats);

  printf("DESPOIS DA INTERLOCUTORIA, DESPOIS DE RESOLUCIÓ PARLAMENT 02/10/2018\n");
  aplicar_efectes_resolucio(estat_diputats);

  liberar_memoria(estat_diputats);

  return 0;
}

