int i=3,j=5;
int *p, *q;	// *p = 3 *q = 5
p = &i;
q = &j;
p == &i;	// Retorna true
*p - *q;
**&p;		// 3
3 - *p/(*q) + 7;	3 - (3/5) +7 => 3/5 inteiros retorna 0 => 3+7

// Resultado final: 10
