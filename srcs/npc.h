/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:46:28 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/31 20:48:08 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPC_H
# define NPC_H

# define BRETON_WOMAN 0

# define IDLE 0
# define WALK 1
# define TALK 2
# define DEATH 3

typedef struct s_npc {
	Texture		*texture;
	Vector3		pos;
	Vector3		dir;
	double		size;
	double		health;
	double		cycle;
	int			state;
	int			id;
}				t_npc;

#endif