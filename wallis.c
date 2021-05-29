#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int iter)
{
  float prod=1;
  float term=0;
    for(int i=1;i<=iter;i++)
    {
        //general term in product of wallis formula is (4n^2)/(4n^2-1)
        //iteration should be started with 1 since n varies from 1 to infinity
        term=(4*pow(i,2));//4n^2 term in wallis formula
        prod*=(term/(term-1));//wallis formula
    }
    //prod is pi/2
    //pi=prod*2
    return 2*prod;
}

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

