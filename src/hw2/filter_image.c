#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "image.h"
#define TWOPI 6.2831853

void l1_normalize(image im)
{
    float sum = 0;

    for(int c = 0; c < im.c; c++) {
        for(int x = 0; x < im.w; x++) {
            for(int y = 0; y < im.h; y++) {
                sum += get_pixel(im, x, y, c);
            }
        }
    }

    for(int c = 0; c < im.c; c++) {
        for(int x = 0; x < im.w; x++) {
            for(int y = 0; y < im.h; y++) {
                float value = get_pixel(im, x, y, c) / sum;
                set_pixel(im, x, y, c, value);
            }
        }
    }
}

image make_box_filter(int w)
{
    image box_filter = make_image(w, w, 1);

    for(int x = 0; x < w; x++) {
        for(int y = 0; y < w; y++) {
            set_pixel(box_filter, x, y, 1, 1);
        }
    }

    return box_filter;
}

image convolve_image(image im, image filter, int preserve)
{
    image new_img = make_image(im.w, im.h, im.c);

    if(im.c == filter.c) {
        for(int c = 0; c < im.c; c++) {
            for(int x = 0; x < im.w; x++) {
                for(int y = 0; y < im.h; y++) {
                    set_pixel(new_img, x, y, c, get_pixel(im, x-1, y-1, c) * get_pixel(filter, x-1, y-1, c) +
                                        get_pixel(im, x-1, y,   c) * get_pixel(filter, x-1, y,   c) +
                                        get_pixel(im, x-1, y+1, c) * get_pixel(filter, x-1, y+1, c) +
                                        get_pixel(im, x,   y-1, c) * get_pixel(filter, x,   y-1, c) +
                                        get_pixel(im, x,   y,   c) * get_pixel(filter, x,   y,   c) +
                                        get_pixel(im, x,   y+1, c) * get_pixel(filter, x,   y+1, c) +
                                        get_pixel(im, x+1, y-1, c) * get_pixel(filter, x+1, y-1, c) +
                                        get_pixel(im, x+1, y,   c) * get_pixel(filter, x+1, y,   c) +
                                        get_pixel(im, x+1, y+1, c) * get_pixel(filter, x+1, y+1, c));
                }
            }
        }
        return new_img;
    }
    else if(preserve == 1) {
        for(int c = 0; c < im.c; c++) {
            for(int x = 0; x < im.w; x++) {
                for(int y = 0; y < im.h; y++) {
                    set_pixel(new_img, x, y, c, get_pixel(im, x-1, y-1, c) * get_pixel(filter, x-1, y-1, 0) +
                                        get_pixel(im, x-1, y,   c) * get_pixel(filter, x-1, y,   0) +
                                        get_pixel(im, x-1, y+1, c) * get_pixel(filter, x-1, y+1, 0) +
                                        get_pixel(im, x,   y-1, c) * get_pixel(filter, x,   y-1, 0) +
                                        get_pixel(im, x,   y,   c) * get_pixel(filter, x,   y,   0) +
                                        get_pixel(im, x,   y+1, c) * get_pixel(filter, x,   y+1, 0) +
                                        get_pixel(im, x+1, y-1, c) * get_pixel(filter, x+1, y-1, 0) +
                                        get_pixel(im, x+1, y,   c) * get_pixel(filter, x+1, y,   0) +
                                        get_pixel(im, x+1, y+1, c) * get_pixel(filter, x+1, y+1, 0));
                }
            }
        }
        return new_img;
    }
    else {
        for(int c = 0; c < im.c; c++) {
            for(int x = 0; x < im.w; x++) {
                for(int y = 0; y < im.h; y++) {
                    set_pixel(new_img, x, y, c, get_pixel(im, x-1, y-1, c) * get_pixel(filter, x-1, y-1, 0) +
                                        get_pixel(im, x-1, y,   c) * get_pixel(filter, x-1, y,   0) +
                                        get_pixel(im, x-1, y+1, c) * get_pixel(filter, x-1, y+1, 0) +
                                        get_pixel(im, x,   y-1, c) * get_pixel(filter, x,   y-1, 0) +
                                        get_pixel(im, x,   y,   c) * get_pixel(filter, x,   y,   0) +
                                        get_pixel(im, x,   y+1, c) * get_pixel(filter, x,   y+1, 0) +
                                        get_pixel(im, x+1, y-1, c) * get_pixel(filter, x+1, y-1, 0) +
                                        get_pixel(im, x+1, y,   c) * get_pixel(filter, x+1, y,   0) +
                                        get_pixel(im, x+1, y+1, c) * get_pixel(filter, x+1, y+1, 0));
                }
            }
        }
        image gray = rgb_to_grayscale(im);
        return gray;
    }
}

image make_highpass_filter()
{
    // TODO
    return make_image(1,1,1);
}

image make_sharpen_filter()
{
    // TODO
    return make_image(1,1,1);
}

image make_emboss_filter()
{
    // TODO
    return make_image(1,1,1);
}

// Question 2.2.1: Which of these filters should we use preserve when we run our convolution and which ones should we not? Why?
// Answer: TODO

// Question 2.2.2: Do we have to do any post-processing for the above filters? Which ones and why?
// Answer: TODO

image make_gaussian_filter(float sigma)
{
    // TODO
    return make_image(1,1,1);
}

image add_image(image a, image b)
{
    // TODO
    return make_image(1,1,1);
}

image sub_image(image a, image b)
{
    // TODO
    return make_image(1,1,1);
}

image make_gx_filter()
{
    // TODO
    return make_image(1,1,1);
}

image make_gy_filter()
{
    // TODO
    return make_image(1,1,1);
}

void feature_normalize(image im)
{
    // TODO
}

image *sobel_image(image im)
{
    // TODO
    return calloc(2, sizeof(image));
}

image colorize_sobel(image im)
{
    // TODO
    return make_image(1,1,1);
}
