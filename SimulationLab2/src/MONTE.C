#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

void main() {
  int r, N, xc = 325, yc = 225, gd = DETECT, gm, n = 0;

  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  printf("Enter radius of circle:  ");
  scanf("%d", &r);
  printf("Enter number of lines to be generated:  ");
  scanf("%d", &N);

  circle(xc, yc, r);
  line(xc - r - 50, yc, xc + r + 50, yc); // horizontal line
  line(xc, yc - r - 50, xc, yc + r + 50); // vertical line
  int tan1 = yc - r,
  tan2 = xc + r;
  line(xc, tan1, tan2, tan1); // horizontal tangent
  line(tan2, tan1, tan2, yc); // vertical tangent

  for(int i = 0; i < N; i++) {
    int xr = rand() % r,
    yr = rand() % r;
    setcolor((i+1) % 8);
    line(xc, yc	, xc + xr, yc - yr);
    int d = sqrt(pow((xc + xr - xc), 2) + pow((yc - yr - yc), 2));
    if(d < r)  n++;
  }

  printf("\nn: %d", n);
  float PI = (4 * n) / N;
  printf("\nValue of PI:  %.2f", PI);
  float error = abs(((3.1416 - PI) / 3.1416) * 100);
  printf("\nError = %.2f %", error);

  getch();
  closegraph();
}