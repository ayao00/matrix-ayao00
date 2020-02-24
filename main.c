#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = 255;
  c.blue = 0;

  clear_screen(s);

  struct matrix *edges;
  struct matrix *test;
  struct matrix *test2;

  edges = new_matrix(4, 4);
  ident(edges);
  test = new_matrix(4,2);
  add_point(test,1,2,3);
  add_point(test,4,5,6);
  printf("printing test\n");
  print_matrix(test);

  printf("testing identity\n");
  print_matrix(edges);
  printf("testing identity multiplication\n");
  matrix_mult(edges, test);
  print_matrix(test);

  printf("testing multiplication\n");
  test2 = new_matrix(4,4);
  add_point(test2,1,2,3);
  add_point(test2,4,5,6);
  add_point(test2,7,8,9);
  add_point(test2,10,11,12);
  print_matrix(test2);
  matrix_mult(test2, test);
  print_matrix(test);

  free_matrix(edges);

  edges = new_matrix(4, 100);
  for(int i = 0; i < 50; i++){
    add_edge(edges, (i * 10 + 20),(YRES - i * 10), 0, (i*20%XRES),(YRES- i*15),0);
  }

  draw_lines(edges,s,c);

  free_matrix(edges);
  free_matrix(test);
  free_matrix(test2);
  display(s);
  save_extension(s, "matrix.png");
  save_ppm(s, "binarymatrix.ppm");
  save_ppm_ascii(s, "asciimatrix.ppm");
}
