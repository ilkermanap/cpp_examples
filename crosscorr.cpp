#include <iostream>
#include <math.h> 
#include <cmath>
#include <complex>
using namespace std;
const double Enumber = std::exp(1.0);
const double PI  =3.141592653589793238463;

/*https://www.statisticshowto.datasciencecentral.com/cross-correlation/*/
/*https://www.drdobbs.com/cpp/a-simple-and-efficient-fft-implementatio/199500857?pgno=1  */


float fmean(float arr1[] ,int size);
float fvariance(float arr1[] ,int size);
float fcovariance(float arr1[] ,float arr2[],int size,int size1);
float fcorrelation (float arr1[] ,float arr2[],int size,int size1);




int main() 
{ 
   float  a[] = {1, 2, 3, 4, 5, 6,11}; 
    float  b[] = {1, 2, 3, 4, 5, 6,12}; 
    int len = sizeof(a)/sizeof(a[0]);
     int len1 = sizeof(b)/sizeof(b[0]);
    fcorrelation(a,b,len,len1);
    
    return 0; 
}


/* ortalama fonksiyonu*/
float fmean(float arr1[] ,int size){
float sum=0;
float mean;
   for(int i=0; i<size; i++){
    sum +=  arr1[i];
   }
   mean=sum/size;
   return mean;
}

float fvariance(float arr1[] ,int size){
     float mean;float sum=0;float variance;
     mean = fmean(arr1,size);
      for(int i=0; i<size; i++){
      sum +=  pow(arr1[i]-mean,2);
   }
  variance =sum/size;
  return variance;

}


/* kovaryans fonksiyonu*/
float fcovariance(float arr1[] ,float arr2[],int size,int size1){
float sum;
float mean=fmean(arr1,size);
float mean1=fmean(arr2,size1);
float covariance ;

if ( size != size1)
{
    cout << "verisetlerindeki eleman sayısı eşit değil";
    return 0;
}else{
   for(int i=0; i<size; i++){
   sum +=  ((arr1[i]-mean)*(arr2[i]-mean1));
   }
 covariance=sum /size;
   

   }
}

/* korelasyon fonksiyonu*/
float fcorrelation (float arr1[] ,float arr2[],int size,int size1){
float corelation;
float first;
float second;

first =fcovariance( arr1 , arr2, size, size1);
second= sqrt(fvariance(arr1,size)*fvariance(arr2,size1));
corelation=first/second;
cout << "korelasyon :"<< corelation;
return corelation;
}


/* ayrık fourier dönüşüm fonksiyonu bitmedi daha */
float discfourier(float arr1[],int size){
    const   complex<double> i(0.0,1.0);
double g =pow(Enumber,-2*PI*size);


}