# include <iostream>
# include <cmath>

using namespace std;
void func(double* q, const double* const y, const double eta){

  q[0] = y[1];
  q[1] = (eta - (y[0]*y[0]))*y[0];

  
}

int main(){
  
  const double eta = 0.4;
  
  double k1[2];
  double k2[2];
  double k3[2];
  
  int N;
  double dx=0.0001;
  N=int (100/dx + 1);
  
  double kesi[2];
  double s1[2];
  double s2[2];
  
  
  kesi[0]=1e-5;
  kesi[1]=sqrt(eta)*kesi[0];
  cout << "0.0" << "\t"  << kesi[0]<< "\t" << kesi[1] << "\t" << sqrt(2*eta)<< endl;
  
  for(double x=dx; x<=100; x+=dx){
   func(k1,kesi,eta);
   
   s1[0] = kesi[0]+(dx/2.0)*k1[0];
   s1[1] = kesi[1]+(dx/2.0)*k1[1];
   
   func(k2,s1,eta);
   
   s2[0]= kesi[0]-dx*k1[0]+2*dx*k2[0];
   s2[1]= kesi[1]-dx*k1[1]+2*dx*k2[1];
   
    func(k3,s2,eta);
    
    kesi[0]+=(dx/6.0)*(k1[0]+4*k2[0]+k3[0]);
    kesi[1]+=(dx/6.0)*(k1[1]+4*k2[1]+k3[1]);
    
   cout << x << "\t"  << kesi[0]<< "\t" << kesi[1]  << "\t" << sqrt(2*eta)*(1/cosh(sqrt(eta)*x)) << endl;
  }
  
  
  return 0;
}