/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:56:52 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/03/07 00:27:36 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int main ()
{
    int     fd;
    char    *line;

    fd = open("my_file.txt", O_RDONLY);
    //check if the file is not going to be opened
    if (fd < 0)     //if fd is -1(for errors) or 0(if empty)
        return (-1);
        //if the file is successfuly open
    while (get_next_line(fd, &line) == 1)    //using & because we have a pointer *line | ==1 means if we have at least 1 character in out file
    {
        ft_putendl(line);      //print the line till end of the line(before \n)
    }
	close(fd);
	return (0);	
}
