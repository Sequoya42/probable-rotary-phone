/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:30:22 by rbaum             #+#    #+#             */
/*   Updated: 2016/03/14 14:30:29 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <time.h>
# include "../libft/inc/libft.h"
# include <fcntl.h>

# define SQUARE(x) x * x
# define MIN(a, b) (((a) < (b)) ? (a) : (b))

# define RED	MIN(sc->color.red*255.0f, 255.0f)
# define BLUE 	MIN(sc->color.blue*255.0f, 255.0f)
# define GREEN	MIN(sc->color.green*255.0f, 255.0f)

# define WIN_X 800
# define WIN_Y 600

# define MK_UP	126
# define MK_DW	125
# define MK_LT	123
# define MK_RT	124

# define MK_Z	6
# define MK_C 	8
# define MK_F	3
# define MK_D 	2
# define MK_H	4
# define MK_R  	15
# define MK_B	11
# define MK_N	45

# define MK_ESC	53
# define MK_PL	69
# define MK_MI	78

# define MB_L	1
# define MB_R	2
# define MB_M	3
# define MB_UP	5
# define MB_DW	4

# define MOTION_NOTIFY			6
# define PTR_MOTION_MASK		(1L << 6)

#endif
