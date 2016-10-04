Aplicacions:
integral(0->1) e^x = e-1 = 1.7182818...
integral(0->0.8) sin(x) / x = 0.772095785...
integral(0->1) (x / 3rdroot(x^6 + (1-x^3)^2))^4 =


EXERCICI 1: Trapezis h = b-a, b-a)/2, (b-a)/4, (b-a)/8 ...
EXERCICI 2: Trapezis + Extrapolacio = Romberg

n=1,2,4,8,16...



Per exemple, n=4:

|----|----|----|----|
a=x0 x1   x2   x3  b=x4

	- T(h) = h[1/2*f(a)+f(x1)+f(x2)+f(x3)+ 1/2*f(b)

quan passem a n=8:
	h -> meitat de l'anterior
	hi ha el doble d'intervals:

|--|--|--|--|--|--|--|--|
x0 x1 x2 x3 x4 x5 x6 x7 x8

x0 = a
x8 = b
	- T(h) = h[1/2*f(x0) + f(x1) + f(x2) + f(x3) + f(x4) + f(x5) + f(x6) + f(x7) + 1/2*f(x8)]

	Â Els d'indexos parells ja s'han calculat, ja que corresponen als de a dalt. (x0 = x0, x2 = x1, x4 = x2 etc.) -> doncs fem que el programa no els torni a calcular



PROGRAMA:
	main
		h = b-a
		t0 = [f(a) + f(b)]* (b-a) /2
		
		bucle
			h/=2
			t_sub_(k) = 1/2 t_sub_(k-1) + h * trap(k)

	double trap(n):
		S'ENCARREGA DE SUMAR ELS TERMES NOUS, QUE ENCARA NO HAN SURTIT (x_sub_k AMB k IMPARELL) I MULTIPLICAR PER h



MAIN DEL PROFE:
	i = 0
	n = 1
	t0 = (b-a)/2*[f(a) + f(b)] {b-a es l'altura inicial}
	do {
		i++;
		n*=2
		h = (b-a)/n
		t1 = trap(n) + t0 / 2
		dif = fabs(t1-t0);
		t0 = t1;
	} while ( dif > prec && i < num );
