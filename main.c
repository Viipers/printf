/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:00:25 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/24 14:46:22 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	ft_printf("Bonjour j%c fais un %% %i %s numero %d !\n",'e',54,"test",1);
	printf("Bonjour j%c fais un %% %i %s numero %d !\n",'e',54,"test",1);

	char ab;
	ab = 42;
	printf("%p\n",&ab);
	ft_printf("%p\n",&ab);

	printf("%s%s%s\n", "1", "2", "3");
	ft_printf("%s%s%s\n", "1", "2", "3");

	printf("memory address = %u\n", -85);
	ft_printf("memory address = %u\n", -85);

	printf("memory address = %x\n", 8920);
	ft_printf("memory address = %x\n", 8920);

	printf("%5d\n",3669);
	ft_printf("%5d\n",3669);

	printf("%10s\n","JeTest");
	ft_printf("%10s\n","JeTest");

	printf("%10c\n",'l');
	ft_printf("%10c\n",'l');

	printf("%5%\n");
	ft_printf("%5%\n");

	printf("%20p\n",&ab);
	ft_printf("%20p\n",&ab);

	printf("memory address = %20x\n", 128);
	ft_printf("memory address = %20x\n", 128);
	printf("memory address = %20u\n", 128);
	ft_printf("memory address = %20u\n", 128);

	/*printf("%-10syo000|\n", "1");
	ft_printf("%-10syo000|\n", "1");

	printf("%-i|\n",42);
	ft_printf("%-i|\n",42);

	printf("%.2s\n", "yolo");
	ft_printf("%.2s\n", "yolo");

	printf("%5.2s|\n", "yolo");
	ft_printf("%5.2s|\n", "yolo");

	printf("%3.7s%7.7s", "hello", "world\n");
	ft_printf("%3.7s%7.7s", "hello", "world\n");

	printf("hello, %s.\n", NULL);
	ft_printf("hello, %s.\n", NULL);

	printf("%32s\n", NULL);
	ft_printf("%32s\n", NULL);

	printf("|%3.s\n", NULL);
	ft_printf("|%3.s\n", NULL);

	printf("%.5d\n", 2);
	ft_printf("%.5d\n", 2);

	printf("%.2d\n", 2350);
	ft_printf("%.2d\n", 2350);

	printf("%.6d\n", -3);
	ft_printf("%.6d\n", -3);

	printf("%6d\n", -3);
	ft_printf("%6d\n", -3);

	printf("%06d\n", -3);
	ft_printf("%06d\n\n", -3);

	printf("%8.5d\n", 34);
	ft_printf("%8.5d\n\n", 34);

	printf("%10.5d\n", -216);
	ft_printf("%10.5d\n\n", -216);

	printf("%10.5d\n", -2168);
	ft_printf("%10.5d\n\n", -2168);

	printf("%10.5d\n", -21685);
	ft_printf("%10.5d\n\n", -21685);

	printf("%10.5d\n", -216858);
	ft_printf("%10.5d\n\n", -216858);

	printf("%10.5d\n", -21685885);
	ft_printf("%10.5d\n\n", -21685885);

	printf("vrai|%8.5d|\n", 0);
	ft_printf("mien|%8.5d|\n\n", 0);

	printf("%-5%|\n");
	ft_printf("%-5%|\n\n");

	printf("%08.5d\n", 34);
	ft_printf("%08.5d\n\n", 34);

	printf("%010.5d\n", -216);
	ft_printf("%010.5d\n", -216);

	printf("%.0d\n", 0);
	ft_printf("%.0d\n", 0);

	printf("vrai|%8.5d|\n", 34);
	ft_printf("mien|%8.5d|\n\n", 34);

	printf("vrai|%08.5d|\n", 34);
	ft_printf("mien|%08.5d|\n\n", 34);

	printf("v%%-8.5d = ||%-8.5d||\n", 34);
	ft_printf("m%%-8.5d = ||%-8.5d||\n", 34);

	printf("%8.5d\n", 0);
	ft_printf("%8.5d\n", 0);

	printf("%.5u\n", 2);
	ft_printf("%.5u\n", 2);

	printf("%.5u\n", 2892564);
	ft_printf("%.5u\n", 2892564);

	printf("%8.5u\n", 34);
	ft_printf("%8.5u\n", 34);

	printf("|%.p|\n", NULL);
	ft_printf("|%.p|\n", NULL);

	printf("|%p|\n", NULL);
	ft_printf("|%p|\n\n", NULL);

	printf("1 : %2.p|\n", NULL);
	ft_printf("2 : %2.p|\n\n", NULL);

	printf("%.5p\n", 0);
	ft_printf("%.5p\n\n\n", 0);

	printf("%2.9p\n", 1234);
	ft_printf("%2.9p\n\n\n", 1234);

	printf("%.9p\n", 2892564);
	ft_printf("%.9p\n\n\n", 2892564);

	printf("%9.4p\n", 1234);
	ft_printf("%9.4p\n\n\n", 1234);

	printf("%9.7p\n", 1234);
	ft_printf("%9.7p\n\n\n", 1234);

	printf("%9.2p\n", 1234);
	ft_printf("%9.2p\n\n\n", 1234);

	printf("%p\n", 1234);
	ft_printf("%p\n\n\n", 1234);

	ft_printf("m|%012.9s|\n", "hi low");
 	printf("r|%012.9s|\n\n", "hi low");

	printf("hello%*s\n", 12, "world");
	ft_printf("hello%*s\n\n", 12, "world");

	printf("%.*s\n", 3, "hello");
	ft_printf("%.*s\n\n", 3, "hello");

	printf("|%*s| \n", -32, "abc");
	ft_printf("|%*s| \n\n", -32, "abc");

	printf("%0*i\n", 7, -54);
	ft_printf("%0*i\n\n", 7, -54);

	printf("%--32s|\n", "abc");
	ft_printf("%--32s|\n", "abc");
	printf("%----*s|\n", -32, "abc");
	ft_printf("%----*s|\n\n", -32, "abc");

	printf("\n\n\n--------\n");

	printf("%.*s|\n", -3, "hello");
	ft_printf("%.*s|\n", -1, "hello");

	printf("%000000s\n", "hi low");
	ft_printf("%000000s\n", "hi low");
	printf("%00000015s\n", "hi low");
	ft_printf("%00000015s\n", "hi low");
	printf("%0*i|\n", -7, -54);
	ft_printf("%0*i|\n", -7, -54);

	printf("%.-3s|\n", "hello");
	ft_printf("%.-3s|\n\n", "hello");

	printf("%.-6i|\n", -3);
	ft_printf("%.-6i|\n", -3);
	printf("%.*i|\n", -6, -3);
	ft_printf("%.*i|\n\n", -6, -3);

	printf("%.-1i|\n", -5);
	printf("%.-1i|\n", -5);*/

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
	ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n\n", i, j, k, l, m, n, c, c, j, j, j);

	printf("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d\n", i, j, k, l, m, c, e, d);
	ft_printf("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d\n\n", i, j, k, l, m, c, e, d);

	printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n", i, j, k, l, m, c, e, d);
	ft_printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n\n", i, j, k, l, m, c, e, d);

	printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d\n", i, j, k, l, m, c, e, d);
	ft_printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d\n\n", i, j, k, l, m, c, e, d);

		while (a < 5)
	{
		ft_printf("a = %d\n", a);
		printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		a++;
	}
	printf("\n--------------------------------------\n");

	a = -2;
	b = 0;
	printf("a = %d | b = %d\n\n",a,b);

	printf("%*.*d, %*.*d|\n",a, b, k, a, b, l);
	ft_printf("%*.*d, %*.*d|\n\n",a, b, k, a, b, l);

	a = 4;
	b = -2;
	printf("\na = %d | b = %d | d = %d | %%0*.*d\n\n",a,b,j);
	printf("%0*.*d|\n",a, b, j);
	ft_printf("%0*.*d|\n\n",a, b, j);

/*	a = 15;
	b = -2;
	printf("\na = %d | b = %d | d = %d | %%0*.*d\n\n",a,b,f);
	printf("%0*.*p|\n",a, b, f);
	ft_printf("%0*.*p|\n\n",a, b, f);
*/
	a = 8;
	b = -2;
	printf("\na = %d | b = %d | %%*.*s\n\n",a,b);
	printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
	ft_printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s\n\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);

	a = 8;
	b = -2;
	printf("\na = %d | b = %d | %%*.*s\n\n",a,b);
	printf("%*.*s|\n",a, b, q);
	ft_printf("%*.*s|\n\n",a, b, q);



	return 0;
}
