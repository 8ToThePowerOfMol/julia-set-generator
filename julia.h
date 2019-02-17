//
// Created by mohwaalb on 5/18/18.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <string>
#include <sstream>

#include "constants.h"

#ifndef SEMESTRA_JULIA_H
#define SEMESTRA_JULIA_H

void calculate_julia(uint8_t picture[HEIGHT][WIDTH][3], int n, double zx, double zy, double cx, double cy, double b);
void save_image(uint8_t picture[HEIGHT][WIDTH][3]);

#endif //SEMESTRA_JULIA_H
