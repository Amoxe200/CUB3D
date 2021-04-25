#include "header.h"

void	text_init(t_struct *g)
{
	int	w;
	int	h;

	g->nt.img = mlx_xpm_file_to_image(g->img.mlx_ptr, g->map_conf.north_texture, &w, &h);
	g->st.img = mlx_xpm_file_to_image(g->img.mlx_ptr, g->map_conf.south_texture, &w, &h);
	g->wt.img = mlx_xpm_file_to_image(g->img.mlx_ptr, g->map_conf.west_texture, &w, &h);
	g->et.img = mlx_xpm_file_to_image(g->img.mlx_ptr, g->map_conf.east_texture, &w, &h);
	g->sp.img = mlx_xpm_file_to_image(g->img.mlx_ptr, g->map_conf.sprite, &w, &h);
	text_checker(g);
}

void	text_checker(t_struct *g)
{
	if (!(g->nt.img))
		ft_error("Error\nNO texture");
	g->nt.addr = (int *)mlx_get_data_addr(g->nt.img, &(g->nt.bits_per_pixel),
			&(g->nt.line_lenght), &(g->nt.endian));
	if (!(g->st.img))
		ft_error("Error\nSO texture");
	g->st.addr = (int *)mlx_get_data_addr(g->st.img, &(g->st.bits_per_pixel),
			&(g->st.line_lenght), &(g->st.endian));
	if (!(g->wt.img))
		ft_error("Error\nWE texture");
	g->wt.addr = (int *)mlx_get_data_addr(g->wt.img, &(g->wt.bits_per_pixel),
			&(g->wt.line_lenght), &(g->wt.endian));
	if (!(g->et.img))
		ft_error("Error\nEA texture");
	g->et.addr = (int *)mlx_get_data_addr(g->et.img, &(g->et.bits_per_pixel),
			&(g->et.line_lenght), &(g->et.endian));
	if (!(g->sp.img))
		ft_error("Error\nS texture");
	g->sp.addr = (int *)mlx_get_data_addr(g->sp.img, &(g->sp.bits_per_pixel),
			&(g->sp.line_lenght), &(g->sp.endian));
}

int	assign_text(int i, ray_struct *rays, t_struct *g)

{
	int	*data[5];
	int	dst;

	data[0] = g->nt.addr;
	data[1] = g->st.addr;
	data[2] = g->wt.addr;
	data[3] = g->et.addr;
	if (rays[i].isRayFacingUp && !rays[i].wasHitVertical)
		dst = data[1][64 * g->dtx.offY + g->dtx.offX];
	if (rays[i].isRayFacingLeft && rays[i].wasHitVertical)
		dst = data[0][64 * g->dtx.offY + g->dtx.offX];
	if (rays[i].isRayFacingDown && !rays[i].wasHitVertical)
		dst = data[3][64 * g->dtx.offY + g->dtx.offX];
	if (rays[i].isRayFacingRight && rays[i].wasHitVertical)
		dst = data[2][64 * g->dtx.offY + g->dtx.offX];
	return (dst);
}
