#include "tests.h"

#define SIZE_X 640
#define SIZE_Y 360

typedef	double matrix[2][2];	// do we need floats? just use integers and save pixel values directly: 
typedef double vector[2];		// if we want single x unit to be 10 pixels wide, it would be
typedef int pixel[2];			// (10, 0)
								// on the other hand, we need still to scale sizes for zoom in/zoom out:
								// might be easier to have an abstract one unit for i, j, k hats and save
								// the scaling factors elsewhere

								// of course, we could always scale the pixel values when reading...
								// would that cause issues when doing really far out zooms

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		bytes_per_line;
	int		endian;
} t_image;

typedef struct s_param
{
	void	*win;
	void	*mlx;
	t_image	*bufs[2];
	matrix	*m;
} t_param;

void vector2pixel(vector v, pixel result)
{
	result[0] = (int) v[0];
	result[1] = (int) v[1];
}

void pixel2vector(pixel pixel, vector result)
{
	result[0] = (double) p[0];
	result[1] = (double) p[1];
}

void vectorproduct(vector a, vector b, vector result)
{
	result[0] = a[0] + b[0];
	result[1] = a[0] + b[0];
}

void matrixcomposition(vector v, matrix m, matrix output)
{
	output[0][0] = v[0] * m[0][0];
	output[0][1] = v[0] * m[0][1];
	output[1][0] = v[1] * m[1][0];
	output[1][1] = v[1] * m[1][1];
}

// origin is the pixel coordinates where the line starts
// endpoint is the pixel coordinate of the point where line ends
// vector is the line that is drawn from the origin
// matrix is the transformation matrix
pixel	*draw_line(pixel origo, vector start, vector end, matrix m)
{

	while (progress < 1.0) {
		progress += 0.1;
	} return();
}

int main (void)
{
	void	*mlx;
	void	*win;
	t_param	params;
	t_image	img1;
	t_image	img2;
	matrix	m1 = {
		{ 1.0, 0.0 }, 
		{ 0.0, 1.0 } 
	};

	mlx = mlx_init();
	win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "tutorial2");
	img1.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, 
			&img1.bytes_per_line, &img1.endian);
	img2.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, 
			&img2.bytes_per_line, &img2.endian);
	printf("bits per pixel: %d, line length: %d, endian: %d\n", 
			img1.bits_per_pixel, img1.bytes_per_line, img1.endian);
	params.mlx = mlx;
	params.win = win;
	params.bufs[0] = &img1;
	params.bufs[1] = &img2;
	params.m = &m1;
	
	return(0);
}
