//PRACTICA 10:

double AvalLegendre(int n, double x) {
	P0(x) = 1
	P1(x) = x
	int i;
	for (i=1; i<n-1; i++) {
		P[i+1] = ((2*i+1)/(i+1))*x*P[i] - (i/i+1)*P[i-1]
	}
		 
	pertot i >= 0 , P_i+1(x) = ((2i+1)/x*P_i(x) - (i)/P_i-1(x))/(i+1)
		--> vigila amb divisió sencera
n, x => Ha de retornar Pn(x)
	Aixo es pot fer amb 3 variables
	p0 = 1
	p1 = x
	for (...):
		p2 = ...
		p0 = p1
		p1 = p2
	retornar p2 (o p1)

double biseccio(int n, double a, double b, double prec)
	fa = AvalLegendre(n,a)
	fb = AvalLegendre(n,b)
	while ((b-a)>prec)
		c = (a+b)/2
		fc = AvalLegendre(n,c);
		if (fabs(fc) < prec) {
			return c;
		}
		if (fa*fc < 0) {
			b = c;
		} else {
			a = c;
		}
	
	retornar (a+b)/2

Per les arrels:           P1(x)
	|\          |      /    / |
	|_\_________|_____/____/__| P0(x)
	|  \        |    /    /   |
	|   \       |	/    /    |
	|    \      |  /    /     |
	|     \     | /    /	  |
	|      \____|/____/ P2(x) |
	|           |             |

alfa? | Pn(alfa) = 0  (busquem arrels)
n, prec
P1 => alfa = 0

tindrem un vector de la forma:
	z = [-1 , alfa1, alfa2, alfa3 ... alfa_i-1, 1]
		-> cada cop que avancem, tindrem una arrel mes a la llista, pero els uns s'han de quedar... s'ha de vigilar amb aixó
