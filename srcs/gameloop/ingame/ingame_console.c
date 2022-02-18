/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_console.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:22:01 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/18 17:18:43 by khirsig          ###   ########.fr       */
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
		add_item_to_inventory(data, ft_atoi(split_cmd[1]), ft_atoi(split_cmd[2]));
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
