/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:00:25 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/18 10:03:44 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	ft_printf("Bonjour j%c fais un %% %i %s numero %d !\n",'e',54,"test",1);
	printf("Bonjour j%c fais un %% %i %s numero %d !\n",'e',54,"test",1);

	char a;
	a = 42;
	printf("%p\n",&a);
	ft_printf("%p\n",&a);

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

	printf("%20p\n",&a);
	ft_printf("%20p\n",&a);

	printf("memory address = %20x\n", 128);
	ft_printf("memory address = %20x\n", 128);
	printf("memory address = %20u\n", 128);
	ft_printf("memory address = %20u\n", 128);

	printf("%-10syo000|\n", "1");
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

	//ft_printf("m|%012.9s|\n", "hi low");
	//printf("r|%012.9s|\n\n", "hi low");

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

	printf("%9.5p\n", 1234);
	ft_printf("%9.5p\n\n\n", 1234);

	printf("%9.2p\n", 1234);
	ft_printf("%9.2p\n\n\n", 1234);

	return 0;
}
