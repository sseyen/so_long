/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:20:21 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/04 16:59:29 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>

char	**ft_load_map(char *fd);
int		ft_validate_map(char **map);
char	**ft_freemap(char **map, int count_lines);

#endif