#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592653589793
/*Codigo creado para resolver la ecuacion de Schroedinger dependiente del tiempo.
Se toma como condicion inicial una curva gaussiana centrada en x = 5. Para la solucion se usa el algoritmo de diferencia finita (Landau, Paez, Bordeianu, pag. 493).
Los datos de probabilidad seran enviados a un archivo llamada proba.dat. Los datos de onda seran enviados a un archivo llamado onda.dat. La primera fila de cada aechivo contendra los puntos en x.
*/


int main (){
  int i, j, k;
  int n_points, tiempo;
  float dx, dt, alpha, sigma, ko;
  float  *x, *rnew, *rcurrent, *inew, *icurrent, *potencial, *rho;
  FILE *onda, *proba; 


  onda = fopen("onda.dat","w");
  proba = fopen ("proba.dat", "w");
  n_points = 500;
  dx = 0.02;

  /*Se realiza la reserva de memoria*/
  x = malloc(n_points*sizeof(float));
  rcurrent = malloc(n_points*sizeof(float));
  rnew = malloc(n_points*sizeof(float));
  icurrent = malloc(n_points*sizeof(float));
  inew = malloc(n_points*sizeof(float));
  potencial = malloc(n_points*sizeof(float));
  rho = malloc (n_points*sizeof(float));
  /*Se crean los puntos en x*/
  
  x[0] = -5.0;

  for (i=1;i<n_points;i++){
    x[i]=x[i-1] + dx;
  }
  /*Se crea el potencial*/
 
  for (i=0;i<n_points;i++){
    potencial[i] = 5.0 * pow(x[i],2);
  }

  /*Se crean los diferenciales que determinan la solucion*/

  dx = x[1]-x[0];
  dt = 0.1*pow(dx,2);
  alpha = dt/(2*pow(dx,2));
  sigma = 0.5;
  ko = 17*PI;
  tiempo = 2000;

  /*Se crea el estado inicial*/

  for (i=0;i<n_points;i++){
    rcurrent[i] = exp(-0.5*pow(((x[i])/sigma),2))*cos(ko*x[i]);
    icurrent[i] = exp(-0.5*pow(((x[i])/sigma),2))*sin(ko*x[i]);
  }

/*Se imprimen los puntos en x.*/

for(i=0;i<n_points;i++){
    fprintf(onda,"%f\t", x[i]);
    fprintf(proba,"%f\t", x[i]);
    if(i == n_points-1){
      fprintf(onda,"\n");
      fprintf(proba,"\n");
    }
  }

  /*Se imprime el estado inicial.*/

 for(i=0;i<n_points;i++){
   fprintf(onda,"%f\t", rcurrent[i]);
   if(i == n_points-1){
     fprintf(onda,"\n");
   }
 }
 for(i=0;i<n_points;i++){
   fprintf(onda,"%f\t", icurrent[i]);
   if(i == n_points-1){
     fprintf(onda,"\n");
   }
 }
 /*Se crea un loop que realice la solucion.*/
 for (j=0;j<tiempo;j++){
   for (i=1;i<n_points-1;i++){
     rnew[i] = rcurrent[i]- dt*(icurrent[i+1]+icurrent[i-1] - 2*icurrent[i]);
     rho[i] = (rcurrent[i]*rnew[i]) + (pow(icurrent[i],2));
   }
   for (i=1;i<n_points-1;i++){
     inew[i] =  icurrent[i] + dt*(rcurrent[i+1]+rcurrent[i-1] - 2*rcurrent[i]);
   }
   /*Se imprimen los datos.*/
   for(i=0;i<n_points;i++){
     fprintf(onda,"%f\t", rcurrent[i]);
     if(i == n_points-1){
       fprintf(onda,"\n");
     }
   }
   for(i=0;i<n_points;i++){
     fprintf(onda,"%f\t", icurrent[i]);
     if(i == n_points-1){
       fprintf(onda,"\n");
     }
   }

   for(i=0;i<n_points;i++){
     fprintf(proba,"%f\t", rho[i]+ 0.0015*potencial[i]);
     if(i == n_points-1){
       fprintf(proba,"\n");
     }
   }
   /*Se actualiza la onda.*/

   for(i=1;i<n_points-1;i++){
     rcurrent[i] = rnew[i];
     icurrent[i] = inew[i];
   }
 }

   fclose(onda);
   fclose(proba);
   return 0;

 }
