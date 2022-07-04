#include "mlx.h"
#include <math.h>

typedef struct s_data {
	int		bits_per_pixel;
	int		size_line;
	int 	endian;
	void	*img;
	char	*addr;
} t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

int main()
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, ":)");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
	x = 0;
	y = 500;
	while (x < 1000)
	{
		my_mlx_pixel_put(&img, x, y, 0xFFFFFF);
		x++;
	}
	my_mlx_pixel_put(&img, 400, 600, 0xAAFF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);	
	mlx_loop(mlx);
}
