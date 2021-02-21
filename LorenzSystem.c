#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//Constants
#define sigma 10.
#define r 28.
#define b (8/3.)
//Coordinate functions of the ODE flow, y'=f(t,y)
double f1(double x, double y, double z);
double f2(double x, double y, double z);
double f3(double x, double y, double z);

//Straightforward implementation of Rk4 to Lorenz System
int main()
{
  int j;
  double x=1.,y=0.,z=0.,h; //Initial conditions
  double kx1,ky1,kz1,kx2,ky2,kz2,kx3,ky3,kz3,kx4,ky4,kz4,t=0.;  //RK4 variables
  h=1E-4; //Time step
  FILE *archivo=fopen("lorenz.csv","w");
  for (j=0; j<1E6; j++)
  {
    //Rk4
    fprintf(archivo, "%.15lf %.15lf\n",x,z); //To get x and z
    kx1=f1(x,y,z);
    ky1=f2(x,y,z);
    kz1=f3(x,y,z);

    kx2=f1(x+0.5*h*kx1,y+0.5*h*ky1,z+0.5*h*kz1);
    ky2=f2(x+0.5*h*kx1,y+0.5*h*ky1,z+0.5*h*kz1);
    kz2=f3(x+0.5*h*kx1,y+0.5*h*ky1,z+0.5*h*kz1);

    kx3=f1(x+0.5*h*kx2,y+0.5*h*ky2,z+0.5*h*kz2);
    ky3=f2(x+0.5*h*kx2,y+0.5*h*ky2,z+0.5*h*kz2);
    kz3=f3(x+0.5*h*kx2,y+0.5*h*ky2,z+0.5*h*kz2);

    kx4=f1(x+h*kx3,y+h*ky3,z+h*kz3);
    ky4=f2(x+h*kx3,y+h*ky3,z+h*kz3);
    kz4=f3(x+h*kx3,y+h*ky3,z+h*kz3);

    x=x+(1./6.)*h*(kx1+2.0*kx2+2.0*kx3+kx4);
    y=y+(1./6.)*h*(ky1+2.0*ky2+2.0*ky3+ky4);
    z=z+(1./6.)*h*(kz1+2.0*kz2+2.0*kz3+kz4);
  }
  fclose(archivo);
  
  //Plot with GNUPlot
  FILE*gp=popen("gnuplot","w");
  fprintf(gp,"set terminal png large size 800,680\n");
  fprintf(gp,"set output \"Lorenz.png\" \n");
  fprintf(gp,"set xlabel \"x\" \n");
  fprintf(gp,"set ylabel \"z\" \n");
  fprintf(gp,"set title \"Lorenz system x vs z, sigma = 10, r=28, b=8/3\" \n");
  fprintf(gp, "plot \"lorenz.csv\" w l linestyle 7 linewidth 0.8 title \"x(t), z(t)\" \n");
  fprintf(gp,"quit\n");
  fclose(gp);
}

//Coordinate functions of the ODE flow, y'=f(t,y)
double f1(double x, double y, double z)
{
  double a;
  a=sigma*(y-x);
  return a;
}
double f2(double x, double y, double z)
{
  double a;
  a=-x*z+r*x-y;
  return a;
}
double f3(double x, double y, double z)
{
  double a;
  a=x*y-b*z;
  return a;
}