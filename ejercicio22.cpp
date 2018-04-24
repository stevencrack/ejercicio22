#include <iostream>

using namespace std;

void pos_i(double *u, double min_x, double delta_x, int n);
void pasoapaso(double *u_new, double *u_old, int n, double delta_x, double delta_t, double c);
void copia(double *u_new, double *u_old, int n);
void imprimir(double *u, double min_x, double delta_x, int n, double t);

int main(){
  double min_x=0.0, max_x=2.0, delta_x=0.01;
  int n_x = (max_x - min_x)/delta_x + 1;
  double delta_t = 0.01, t=0.0;
  double D=1.0;
  double * u_old, *u_new, *u_sol;
   
  u_old = new double[n_x];
  u_new = new double[n_x];
  u_sol = new double[n_x];
  double mitad = n_x/2;
  
  pos_i(u_old, min_x, delta_x, n_x);
  imprime(u_old, min_x, delta_x, n_x, t);
  u_sol = pasoapaso(u_new, u_old, n_x, delta_x, delta_t, c);

  for(i=0;i<n_x;i++){
 	while(u_sol[i]<=mitad){
    		pasoapaso(u_new, u_old, n_x, delta_x, delta_t, c);
    		copia(u_old, u_new, n_x);
    		t += delta_t;
		imprime(u_old, min_x, delta_x, n_x, t);
  	}
  }

  return 0;
}

void pos_i(double *u, double min_x, double delta_x, int n){
  int i;
  double x;
  double pi = 3.1415;
  for(i=0;i<n;i++){
    x = min_x +  i * delta_x;
    u[i] = (1/(0.1*pow(2*pi,0.5)))exp(-pow((x-1.0)/0.1,2)*0.5);
  }
}

void imprimir(double *u, double min_x, double delta_x, int n, double t){
  int i;
  double x;
  for(i=0;i<n;i++){
    x = min_x +  i * delta_x;
    cout << t << " " << x << " " << u[i] << endl;
  }
}


void pasoapaso(double *u_new, double *u_old, int n, double delta_x, double delta_t, double D){
  int i;
  
  for(i=1;i<n-1;i++){
    u_new[i] = D*(delta_t/pow(delta_x,2))*u_old[i-1] + (1 - 2*D*(delta_t/pow(delta_x,2)))*u_old[i] + D*(delta_t/pow(delta_x,2))*u_old[i+1]  ;
  }
}

void copia(double *u_new, double *u_old, int n){
  int i;
  for(i=0;i<n;i++){
    u_new[i] = u_old[i];
  }
}
