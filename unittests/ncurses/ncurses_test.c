/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chang-pa <changgyu@yonsei.ac.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:42:21 by chang-pa          #+#    #+#             */
/*   Updated: 2024/04/29 16:20:00 by chang-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../unittests.h"

const char				*g_cm;
const char				*g_ce;
const char				*g_dc;

static bool	init_term(struct termios *t)
{
	if (tcgetattr(STDIN_FILENO, t) == ERROR)
		return (false);
	t->c_lflag &= ~(ICANON | ECHO);
	t->c_cc[VMIN] = 1;
	t->c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, t) == ERROR)
		return (false);
	return (true);
}

static bool	init_query(void)
{
	if (tgetent(NULL, "xterm") == ERROR)
		return (false);
	g_cm = tgetstr("cm", NULL);
	g_ce = tgetstr("ce", NULL);
	g_dc = tgetstr("dc", NULL);
	if (!g_cm || !g_ce)
		return (false);
	return (true);
}

static int	ft_putchar(int c)
{
	if (write(STDOUT_FILENO, &c, 1) == ERROR)
		return (0);
	return (1);
}

static bool	get_position(int *col, int *row)
{
	int					i;
	int					ret;
	char				buf[1024];

	if (write(STDOUT_FILENO, CURPOS, strlen(CURPOS)) == ERROR)
		return (false);
	ret = read(STDIN_FILENO, buf, 1024);
	if (ret == ERROR)
		return (false);
	buf[ret] = '\0';
	i = 0;
	while (!isdigit(buf[i]))
		++i;
	*row = atoi(&buf[i]) - 1;
	while (isdigit(buf[i]))
		++i;
	while (!isdigit(buf[i]))
		++i;
	*col = atoi(&buf[i]) - 1;
	return (true);
}

static bool	cur_left(int *col, int *row)
{
	if (*col)
	{
		--(*col);
		if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar) == ERROR)
			return (false);
	}
	return (true);
}

static bool	cur_right(int *col, int *row)
{
	++(*col);
	if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar) == ERROR)
		return (false);
	return (true);
}

static bool	cur_up(int *col, int *row)
{
	if (*row)
	{
		--(*row);
		if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar) == ERROR)
			return (false);
	}
	return (true);
}

static bool	cur_down(int *col, int *row)
{
	++(*row);
	if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar) == ERROR)
		return (false);
	return (true);
}

static bool	cur_backspace(int *col, int *row)
{
	if (*col)
	{
		--(*col);
		if (tputs(tgoto(g_cm, *col, *row), 1, ft_putchar) == ERROR)
			return (false);
	}
	if (tputs(g_dc, 1, ft_putchar) == ERROR)
		return (false);
	return (true);
}

static bool	key_handle(int ch, int *col, int *row)
{
	if (ch == KEY_LEFT)
	{
		if (!cur_left(col, row))
			return (false);
	}
	else if (ch == KEY_RIGHT)
	{
		if (!cur_right(col, row))
			return (false);
	}
	else if (ch == KEY_UP)
	{
		if (!cur_up(col, row))
			return (false);
	}
	else if (ch == KEY_DOWN)
	{
		if (!cur_down(col, row))
			return (false);
	}
	else if (ch == KEY_BACKSPACE)
	{
		if (!cur_backspace(col, row))
			return (false);
	}
	else
	{
		++(*col);
		if (!ft_putchar(ch))
			return (false);
	}
	return (true);
}


bool	read_char(void)
{
	int					ch;
	int					ret;
	int					col;
	int					row;

	while (true)
	{
		if (!get_position(&col, &row))
			return (false);
		ret = read(STDIN_FILENO, &ch, sizeof(ch));
		if (ret == ERROR)
			return (false);
		if (!ret)
			return (true);
		if (!key_handle(ch, &col, &row))
			return (false);
		ch = 0;
	}
}

void	readline_test(void)
{
	struct termios		t;

	if (!init_term(&t) || !init_query() || !read_char())
		return ;
}
