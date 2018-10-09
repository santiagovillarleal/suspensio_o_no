Hi ha suspensió? Potser si, o potser no. Programa feito en C que mostra o estado actual dos diputados do Parlament que foron procesados polo Tribunal Supremo. 

A versión 1.3 pódese compilar de dous xeitos diferentes, en función de se se recoñece o marco xurídico español ou non.
Se se recoñece haino que compilar así:

$ gcc -Wall suspensio.c -o suspensio

En caso contrario, compílase así:

$ gcc -Wall -DEL_PARLAMENT_ES_SOBIRA suspensio.c -o suspensio
