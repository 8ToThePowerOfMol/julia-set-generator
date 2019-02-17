//
// Created by mohwaalb on 5/18/18.
//

#include "julia.h"

void calculate_julia(uint8_t picture[HEIGHT][WIDTH][3], int n, double zx, double zy, double cx, double cy, double b)
{
	int counter = 0;
	double newRe, newIm, oldRe, oldIm;

	for (int x = 0; x < HEIGHT; x++)
		for (int y = 0; y < WIDTH; y++)
		{
			counter = 0;	

			newRe = (double)x / HEIGHT * (2*zx) - zx;
			newIm = (double)y / WIDTH * (2*zy) - zy;

			while (newRe*newRe + newIm*newIm < 4 && counter < n)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe*oldRe - oldIm*oldIm + cx;
				newIm = 2*oldRe*oldIm + cy;
				counter++;
			}
			
			double t = (double) counter/(double)n;
			double R = 9 * (1-t) * t*t*t * 255 * b;
			double G = 15 * (1-t) * (1-t) * t*t * 255 * b;
			double B = 8.5 * (1-t) * (1-t) * (1-t) * t * 255 * b;
			picture[x][y][0] = (uint8_t)R;
			picture[x][y][1] = (uint8_t)G;
			picture[x][y][2] = (uint8_t)B;
		}
}

void save_image(uint8_t picture[HEIGHT][WIDTH][3])
{
	int fd = open("juliaset.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0777);

	write(fd, "P6\n900 900\n255\n", 15);
	write(fd, picture, WIDTH*HEIGHT*3);

	close(fd);
}


int main(int args, char* argv[])
{
    if(args < 6)
    {
        printf("Missing args!");
        return 1;
    }

    int n = (int)strtol(argv[1], NULL, 10);
    double zx = strtod(argv[2], NULL);
    double zy = strtod(argv[3], NULL);
    double cx = strtod(argv[4], NULL);
    double cy = strtod(argv[5], NULL);
    double d = strtod(argv[6], NULL);

    uint8_t picture[HEIGHT][WIDTH][3];
    calculate_julia(picture, n, zx, zy, cx, cy, d);

    save_image(picture);

    return 0;
}

