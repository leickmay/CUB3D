/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:19:13 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/10 11:15:53 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# define TEXTUREHEIGHT 64
# define TEXTUREWIDTH 64

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	unsigned int	color;
}					t_rgb;

typedef struct		s_sprite
{
	double		x;
	double		y;
	double		sprite_x;
	double		sprite_y;
	char		tex;
	double		distance;
}					t_sprite;

typedef struct		s_bits_img
{
	int		text_y;
	int		text_x;
	int		pixel;
	double	text_pos_y;
	double	text_pos_x;
	double	step_y;
	double	step_x;
}					t_bits_img;

typedef struct		s_data
{
	void		*ptr;
	void		*win;
	char		**map;
	double		dir_x;
	double		dir_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		camera_x;
	double		plane_x;
	double		plane_y;
	double		pos_x;
	double		pos_y;
	double		s_pos_x;
	double		s_pos_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			lineheight;
	int			draw_start;
	int			draw_end;
	int			side;
	int			map_x;
	int			map_y;
	double		wall_x;
	double		step;
	double		text_pos;
	int			text_x;
	int			res_x;
	int			res_y;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	t_rgb		f;
	t_rgb		c;
	int			rows;
	int			columns;
	char		s_pos_dir;
	int			nb_sprites;
	double		*z_buffer;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_y;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_end_x;
	int			life;
	t_sprite	*sprite;
	int			save;
}					t_data;

typedef struct		s_img
{
	void				*img;
	int					height;
	int					width;
	int					pixel_bits;
	int					line_bytes;
	int					endian;
	char				*buffer;
}					t_img;

void				ft_error(char c);
int					ft_exit(void);
void				ft_error_bis(char c);
void				empty_line(char *argv);
int					ft_check_empty_line(char *line);
int					ft_skip_spaces(char *str, int i);
int					ft_get_digit(char *str, int i, int *digit);
void				ft_get_str(char *str, int i, char **path);
void				ft_parse_map(char *argv, t_data *data);
void				get_path_texture(char *argv, char **path, char *dir);
void				get_sprite_path(char *argv, char **path);
void				ft_fill_rgb(t_rgb *f, char *line);
void				ft_check_rgb(t_rgb *f);
void				get_map(char *argv, t_data *data);
int					get_rows(char *argv);
char				**fill_map(char *argv, char **tmp_map);
void				check_nb_player(t_data *data);
void				get_player_start(t_data *data);
int					check_map_started(char *line);
int					check_space_line(char *line);
void				ft_check_map_error(t_data *data);
void				ft_check_map_char(char **map, t_data *data);
void				ft_check_elements(char *argv);
int					is_in_elements(char c);
void				ft_add_space(t_data *data, char **tmp_map);
void				ft_check_doubles_one_char(char *argv, char c);
void				ft_check_doubles_s(char *argv, char c);
void				ft_check_doubles_list(char *argv);
void				ft_check_char_list(char *argv);
void				write_sprites_back(t_data *data);
void				get_nb_sprites(t_data *data);
void				get_sprite_pos(t_data *data);
void				get_sprites(t_data *data);
void				ft_check_xpm_file(char	**path);
void				get_traps(t_data *data);
void				get_trap_pos(t_data *data);
void				get_nb_traps(t_data *data);
void				check_trap(t_data *data);
void				check_cub_ext(char *argv);
void				set_player_info(t_data *data, int y, int x);
void				set_sprite_info(t_data *data, int y, int x, int i);
void				init_camera_dir(t_data *data);
void				init_camera_plan(t_data *data);
int					deal_key_press(int key, void *param);
void				rotate_camera(int key, t_data *data);
void				move_side(int key, t_data *data);
void				move_forward(int key, t_data *data);
void				update_img(t_data *data, t_img *img);
void				draw_textures(t_data *data, t_img *img, t_img *texture, \
int x);
void				write_texture_bits(t_data *data, t_img *img, t_img \
*texture, int x);
void				set_texture_type(t_data *data, t_img *texture);
void				dda_algorithm(t_data *data);
void				set_wall_height(t_data *data);
void				set_side_dist(t_data *data);
void				set_ray(t_data *data, int x, t_img *img, t_img *sprite);
void				draw_floor_sky(t_data *data, t_img *img, int x);
void				set_sprites(t_data *data, t_img *img);
void				sort_sprite_distance(t_data *data);
void				restart_game(t_data *data);
void				game_over(t_data *data);
void				resize_img(t_data *data, t_img *game_over, t_img *resize);
void				display_life(t_data *data, t_img *img, int x);
void				trap_matrix(t_data *data, int i);
void				trap_find_draw(t_data *data);
void				write_trap_bits(t_img *trap, t_img *img, t_bits_img *bits);
void				write_sprite_bits(t_img *sprite, t_img *img, \
t_bits_img *bits);
void				draw_trap(t_data *data, t_img *img, t_img *trap, \
int stripe);
void				set_traps(t_data *data, t_img *img, t_img *trap);
void				get_nb_traps(t_data *data);
void				get_trap_pos(t_data *data);
void				get_traps(t_data *data);
void				check_trap(t_data *data);
void				create_bitmap_image(t_data *data, t_img *img);
void				create_bitmap_header(t_data *data, t_img *img, int fd);

#endif
