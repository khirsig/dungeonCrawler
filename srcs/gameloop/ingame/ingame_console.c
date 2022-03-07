/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_console.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:22:01 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/07 16:53:33 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_ingame.h"

void	open_console(t_data *data)
{
	if (data->console.status == 0 && IsKeyPressed(KEY_MINUS))
		data->console.status = 1;
	else if (data->console.status == 1 && IsKeyPressed(KEY_MINUS))
		data->console.status = 0;
}

static void	add_to_history(t_data *data, char *str)
{
	if (str == NULL || (data->console.history != NULL && TextIsEqual(data->console.history[data->console.history_count - 1], str)))
		return ;
	data->console.history_count++;
	data->console.history_save = data->console.history_count;
	data->console.history = realloc(data->console.history, sizeof(char *) * (data->console.history_count + 1));
	data->console.history[data->console.history_count - 1] = strdup(str);
	data->console.history[data->console.history_count] = NULL;
}

static void	get_history(t_data *data)
{
	if (data->console.history_save == 0)
		return ;
	if (data->console.prompt != NULL)
		free(data->console.prompt);
	data->console.prompt = strdup(data->console.history[data->console.history_save - 1]);
	data->console.history_save--;
}

static void	get_history_reverse(t_data *data)
{
	if (data->console.history_save == data->console.history_count)
		return ;
	if (data->console.prompt != NULL)
		free(data->console.prompt);
	data->console.prompt = strdup(data->console.history[data->console.history_save - 1]);
	data->console.history_save++;
}

static void	console_prompt_join(t_data *data, char c)
{
	char *temp;
	int len;

	if (data->console.prompt == NULL)
	{
		data->console.prompt = malloc(sizeof(char) * 2);
		data->console.prompt[0] = c;
		data->console.prompt[1] = '\0';
		return ;
	}
	else
	{
		temp = strdup(data->console.prompt);
		len = strlen(data->console.prompt);
		free(data->console.prompt);
		data->console.prompt = malloc(sizeof(char) * (len + 2));
		int x = 0;
		while (temp[x] != '\0')
		{
			data->console.prompt[x] = temp[x];
			x++;
		}
		data->console.prompt[x] = c;
		data->console.prompt[x + 1] = '\0';
	}
}

static void	console_prompt_del(t_data *data)
{
	char	*temp;
	int		len;

	data->console.history_save = data->console.history_count;
	len = strlen(data->console.prompt);
	if (len == 1)
	{
		free(data->console.prompt);
		data->console.prompt = NULL;
	}
	else
	{
		temp = strdup(data->console.prompt);
		len = strlen(data->console.prompt);
		free(data->console.prompt);
		data->console.prompt = malloc(sizeof(char) * (len));
		int x = 0;
		while (temp[x + 1] != '\0')
		{
			data->console.prompt[x] = temp[x];
			x++;
		}
		data->console.prompt[x] = '\0';
	}
}

static void	console_command(t_data *data, char *cmd)
{
	char **split_cmd;

	split_cmd = ft_split(cmd, ' ');
	if (TextIsEqual(split_cmd[0], "additem") && split_cmd[1] != NULL && split_cmd[2] != NULL)
	{
		add_item_to_inventory(data, ft_atoi(split_cmd[1]), ft_atoi(split_cmd[2]));
		add_to_history(data, cmd);
	}
	if (TextIsEqual(split_cmd[0], "addgold") && split_cmd[1] != NULL)
	{
		add_gold(data, ft_atoi(split_cmd[1]));
		add_to_history(data, cmd);
	}
	if (TextIsEqual(split_cmd[0], "addsoulgem") && split_cmd[1] != NULL)
	{
		add_soulgem(data, ft_atoi(split_cmd[1]));
		add_to_history(data, cmd);
	}
	if (TextIsEqual(split_cmd[0], "rmvgold") && split_cmd[1] != NULL)
	{
		remove_gold(data, ft_atoi(split_cmd[1]));
		add_to_history(data, cmd);
	}
	if (TextIsEqual(split_cmd[0], "rmvsoulgem") && split_cmd[1] != NULL)
	{
		remove_soulgem(data, ft_atoi(split_cmd[1]));
		add_to_history(data, cmd);
	}
	if (TextIsEqual(split_cmd[0], "setlevel") && split_cmd[1] != NULL && ft_isdigit(split_cmd[1][0]) == 1)
	{
		data->player.level = ft_atoi(split_cmd[1]);
		add_to_history(data, cmd);
	}
	if (TextIsEqual(split_cmd[0], "setmaxhp") && split_cmd[1] != NULL && ft_isdigit(split_cmd[1][0]) == 1)
	{
		double	temp = data->player.max_health;
		data->player.max_health = ft_atoi(split_cmd[1]);
		data->player.health += data->player.max_health - temp;
		if (data->player.health < 0.0)
			data->player.health = 0.0;
		add_to_history(data, cmd);
	}
	if (TextIsEqual(split_cmd[0], "setmaxstam") && split_cmd[1] != NULL && ft_isdigit(split_cmd[1][0]) == 1)
	{
		double	temp = data->player.max_stamina;
		data->player.max_stamina = ft_atoi(split_cmd[1]);
		data->player.stamina += data->player.max_stamina - temp;
		if (data->player.stamina < 0.0)
			data->player.stamina = 0.0;
		add_to_history(data, cmd);
	}
}

void	console_prompt(t_data *data)
{
	char	key;
	int		enter;
	int		promptWidth;

	DrawRectangle(5, 5, 500, 40, BLACK);
	DrawText(">>", 15, 15, 20, WHITE);
	key = GetCharPressed();
	enter = GetKeyPressed();
	if (data->console.prompt != NULL)
		promptWidth = MeasureText(data->console.prompt, 15);
	if (key != '-' && promptWidth < 450)
		console_prompt_join(data, key);
	if (enter == KEY_UP)
		get_history(data);
	if (enter == KEY_DOWN)
		get_history_reverse(data);
	if (enter == KEY_BACKSPACE && data->console.prompt != NULL)
		console_prompt_del(data);
	if (enter == KEY_ENTER)
	{
		console_command(data, data->console.prompt);
		free(data->console.prompt);
		data->console.prompt = NULL;
	}
	if (data->console.prompt != NULL)
		DrawText(data->console.prompt, 40, 17, 15, WHITE);
}
