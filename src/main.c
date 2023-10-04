
#include "inc/cub3D.h"

t_global	*g(void)
{
	static t_global	global;

	return (&global);
}

void	step(void *param)
{
	static double	frame;

	(void)param;
	g()->delta_time = g()->mlx->delta_time * 30;
	if (frame >= 1)
	{
		set_background(g()->image, 0x615445FF, 0x3b3a3aFF);
		raycast(g()->player, g()->image);
		setPlayerDir(&g()->player, 'W');
		player_rotation();
		player_movement();
	}
	frame += g()->delta_time;
}

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	int tempMap[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	int i, j;
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			g()->map[i][j] = tempMap[i][j];
		}
	}

	g()->player.posX = 1.5;
	g()->player.posY = 1.5;
	g()->player.planeX = 0;
	g()->player.planeY = 0.66;
	g()->player.dirX = -1;
	g()->player.dirY = 0;
	g()->player.move_speed = 0.03;


	g()->mlx = mlx_init(VIEW_WIDTH, VIEW_HEIGHT, "Merci Chat", false);
	g()->image = mlx_new_image(g()->mlx, VIEW_WIDTH, VIEW_HEIGHT);
	mlx_image_to_window(g()->mlx, g()->image, 0, 0);
	load_init_texture();

	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (EXIT_SUCCESS);
}