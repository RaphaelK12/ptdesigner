#include <stdio.h>
#include <string.h>
#include "colorbuffer.h"
#include "proctextures.h"
#include "matrix.h"
#include "colortransition.h"
#include "kdtree.h"
#include "general.h"
#include "grammar.h"

int main()
  {
    t_square_mosaic mosaic;
    t_color_buffer buffer;

    color_buffer_init(&buffer,512,512);

    mosaic.side_shape[0] = "0.1 -0.2 0.5 0.15";
                     //     |       |       |
    mosaic.side_shape[1] = "0.7 -0.3";
    mosaic.side_shape[2] = "";
    mosaic.side_shape[3] = "";

    mosaic.transformation[0] = MOSAIC_TRANSFORM_ROTATE_VERTICE;
    mosaic.transformation[1] = MOSAIC_TRANSFORM_ROTATE_VERTICE;
    mosaic.transformation[2] = MOSAIC_TRANSFORM_ROTATE_VERTICE;
    mosaic.transformation[3] = MOSAIC_TRANSFORM_ROTATE_VERTICE;

    mosaic.tiles_x = 4;
    mosaic.tiles_y = 4;

    pt_mosaic_square(&buffer,FILL_KEEP_BORDERS,NULL,&mosaic);

    color_buffer_save_to_png(&buffer,"pic.png");

    color_buffer_destroy(&buffer);

    return 0;
  }
