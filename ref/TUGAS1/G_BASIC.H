#ifndef GRAFIKA_BASIC_H
#define GRAFIKA_BASIC_H

#define round(x) ((int) (x + 0.5))

static int midx;
static int midy;

void canvas_start();

void canvas_clear();

void canvas_finish();

int get_section(int x1, int y1, int x2, int y2);

void draw_point(int x1, int x2, int color);

void draw_axes();

#endif