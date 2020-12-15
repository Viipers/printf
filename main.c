/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:00:25 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/15 18:18:55 by tsannie          ###   ########.fr       */
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

	return 0;
}
