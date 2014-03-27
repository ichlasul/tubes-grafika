#ifndef GRAFIKA_LINE_H
#define GRAFIKA_LINE_H

void draw_line_FPC(int x1, int y1, int x2, int y2);

void draw_line_DDA(int x1, int y1, int x2, int y2);

void draw_line_Bres(int x1, int y1, int x2, int y2);

void draw_line_vertical(int x, int y1, int y2, int color);

void draw_line_horizontal(int x1, int x2, int y, int color);

#endif