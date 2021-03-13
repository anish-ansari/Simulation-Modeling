#include <stdio.h>
#include <conio.h>

void main()
{
  int xo = 117, a = 43, m = 1000, i, j, xi;
  float dplus[5], dminus[5], N[5], max1, max2, max, dalpha = 0.565, num[5], temp;
  clrscr();

  //generating random numbers:
  printf("i    x(i+1)    ui\n");
  for (i = 0; i < 5; i++)
  {
    printf("%d", i + 1);
    xi = (a * xo) % m;
    printf("    %d", xi);
    xo = xi;
    num[i] = (float)xi / m;
    printf("    %.3f\n", num[i]);
  }

  //sorting random numbers:
  for (i = 0; i < 5; i++)
  {
    for (j = i + 1; j <= i; j++)
    {
      if (num[i] > num[j])
      {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
      }
    }
  }

  printf("\nSorted:\n");
  for (i = 0; i < 5; i++)
    printf("%.3f\n", num[i]);

  for (i = 0; i < 5; i++)
  {
    N[i] = (i + 1) / 5;
    dplus[i] = N[i] - num[i];
    dminus[i] = num[i] - (i / 5);
  }

  printf("\ndplus:\n");
  for (i = 0; i < 5; i++)
    printf("%.3f   ", dplus[i]);

  printf("\ndminus:\n");
  for (i = 0; i < 5; i++)
    printf("%.3f   ", dminus[i]);

  max1 = dplus[0];
  max2 = dminus[0];
  for (i = 1; i < 5; i++)
  {
    if (dplus[i] > max1)
      max1 = dplus[i];
    if (dminus[i] > max2)
      max2 = dminus[i];
  }

  printf("\n\nmax1 = %.3f\nmax2 = %.3f", max1, max2);

  max = max1 < max2 ? max2 : max1;
  printf("\n\nmax = %.3f", max);
  max < dalpha ? printf("\n\nUniform") : printf("\n\nNot Uniform");

  getch();
}