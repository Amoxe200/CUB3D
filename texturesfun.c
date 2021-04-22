#include "header.h"

void	text_init(void)
{
	int	w;
	int	h;

	nt.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.north_texture, &w, &h);
	st.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.south_texture, &w, &h);
	wt.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.west_texture, &w, &h);
	et.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.east_texture, &w, &h);
	sp.img = mlx_xpm_file_to_image(img.mlx_ptr, map_conf.sprite, &w, &h);
	text_checker();
}

void	text_checker(void)
{
	if (!(nt.img))
		ft_error("Error\nNO texture");
	nt.addr = (int *)mlx_get_data_addr(nt.img, &nt.bits_per_pixel,
			&nt.line_lenght, &nt.endian);
	if (!(st.img))
		ft_error("Error\nSO texture");
	st.addr = (int *)mlx_get_data_addr(st.img, &st.bits_per_pixel,
			&st.line_lenght, &st.endian);
	if (!(wt.img))
		ft_error("Error\nWE texture");
	wt.addr = (int *)mlx_get_data_addr(wt.img, &wt.bits_per_pixel,
			&wt.line_lenght, &wt.endian);
	if (!(et.img))
		ft_error("Error\nEA texture");
	et.addr = (int *)mlx_get_data_addr(et.img, &et.bits_per_pixel,
			&et.line_lenght, &et.endian);
	if (!(sp.img))
		ft_error("Error\nS texture");
	sp.addr = (int *)mlx_get_data_addr(sp.img, &sp.bits_per_pixel,
			&sp.line_lenght, &sp.endian);
}

int	assign_text(int i, ray_struct *rays)

{
	int	*data[5];
	int	dst;

	data[0] = nt.addr;
	data[1] = st.addr;
	data[2] = wt.addr;
	data[3] = et.addr;
	if (rays[i].isRayFacingUp && !rays[i].wasHitVertical)
		dst = data[1][64 * dtx.offY + dtx.offX];
	if (rays[i].isRayFacingLeft && rays[i].wasHitVertical)
		dst = data[0][64 * dtx.offY + dtx.offX];
	if (rays[i].isRayFacingDown && !rays[i].wasHitVertical)
		dst = data[3][64 * dtx.offY + dtx.offX];
	if (rays[i].isRayFacingRight && rays[i].wasHitVertical)
		dst = data[2][64 * dtx.offY + dtx.offX];
	return (dst);
}
