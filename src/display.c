//
// Created by lush on 8/1/17.
//

#include "lem-in.h"

void	display_path(t_path *path)
{
	t_elem *elem;

	elem = path->list;
	ft_putstr("( ");
	while(elem)
	{
		ft_putstr(elem->room->name);
		ft_putstr(", ");
		elem = elem->next;
	}
	ft_putstr(")\n");
}

void	display_paths(t_path *path)
{
	while(path)
	{
		display_path(path);
		path = path->next;
	}
}

void	display_groups(t_group *group)
{
	while(group)
	{
		display_paths(group->paths);
		ft_putchar('\n');
		group = group->next;
	}
}

void	display_steps(t_step *step)
{
	t_move *move;

	ft_putchar('\n');
	while(step)
	{
		move = step->move;
		while(move)
		{
			ft_putchar('L');
			ft_putnbr(move->ant);
			ft_putchar('-');
			ft_putstr(move->room);
			ft_putchar(' ');
			move = move->next;
		}
		ft_putchar('\n');
		step = step->next;
	}
}