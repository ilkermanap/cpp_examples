#include <iostream>
#include <math.h> 
#include <cmath>
#include <complex>
using namespace std;
const double Enumber = std::exp(1.0);
const double PI  =3.141592653589793238463;




template <class T,class Y>
T fmean(T arr1[] ,Y size){
T sum=0;
T mean;
   for(int i=0; i<size; i++){
    sum +=  arr1[i];
   }
   mean=sum/size;
   return mean;
}


template <class T,class Y>
T fvariance(T arr1[] ,Y size){
     T sum=0;T variance; 
     T mean =fmean(arr1,size);
      for(int i=0; i<size; i++){
      sum +=  pow(arr1[i]-mean,2);
   }
  variance =sum/size;
  return variance;
  

}




template <class T,class Y>
T fcovariance(T arr1[] ,T arr2[],Y size,Y size1){
T sum=0;
T covariance ;
T mean =fmean(arr1,size);
T mean1 =fmean(arr2,size1);
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
return covariance;
}




template <class T,class Y>
T fcorrelation (T arr1[] ,T arr2[],Y size,Y size1){
T corelation;
T first;
T second;
first =fcovariance( arr1 , arr2, size, size1);
second= sqrt(fvariance(arr1,size)*fvariance(arr2,size1));
corelation=first/second;
cout << "korelasyon :\n"<< corelation;
return corelation;
}


/*https://www.alanzucconi.com/2016/06/06/autocorrelation-function/ */
template <class T>
T lagoperator(T size,T delaytime){
size=size-delaytime;
}


template <class T,class Y>
T fautocorrelation (T arr1[] ,T arr2[],Y size,Y size1,Y delaytime){
  T corelation;
  T first;
  T second;
  first =fcovariance( arr1 , arr2, lagoperator(size,delaytime), lagoperator(size1,delaytime));
  second= sqrt(fvariance(arr1,lagoperator(size,delaytime))*fvariance(arr2,lagoperator(size1,delaytime)));
  corelation=first/second;
  cout << "korelasyon :\n"<< corelation;
  return corelation;
}

int main() 
{ 
   /* örnek verisetleri */
   float  a[] = {1, 2, 3, 4, 5, 6,11}; 
   float  b[] = {1, 2, 3, 4, 5, 6,12}; 

   /* örnek verisetlerinin uzunlukları */
   int len = sizeof(a)/sizeof(a[0]);
   int len1 = sizeof(a)/sizeof(a[0]);

/*
Eğer bir örneklem üzerinde çalışılıyorsa n-1 yani uzunlukları n-1 şeklinde 
yani bu kodu 
   int len = (sizeof(a)/sizeof(a[0]))-1;https://www.youtube.com/watch?v=htCj9exbGo0&t=52s

*/
fautocorrelation(a,b,len,len1,2);
 
   
    return 0; 
}



/* ayrık fourier dönüşüm fonksiyonu bitmedi daha 
float discfourier(float arr1[],int size){
    const   complex<double> i(0.0,1.0);
double g =pow(Enumber,-2*PI*size);


}
*/
