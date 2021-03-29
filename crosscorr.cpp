/* autocorrelation for audio signals */


/* libraries */
#include <iostream>
#include <math.h> 
#include <cmath>
#include <complex>
#include <iostream>
#include <valarray>
 

 
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
const double PI  =3.141592653589793238463;
class DFT_Coeff {
   public:
   double real, img;
   DFT_Coeff() {
      real = 0.0;
      img = 0.0;
   }
};

/* mean function */
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

/* median function */
template <class T >
T fmedian( T arr[],int size){
  T median;
  if(size % 2 == 0){
    median =(size/2)-1;
   }else if( size % 2 !=0)
   {
      median =size/2;
   }else {
   median =(size-1)/2;
   }
   cout << "medyan değeri:"<< median;
   return median;
}

/* maximum value function */
template <class T >
T maxval( T arr[],int size){
   T maxvalue ;
    for (size_t i = 0; i < size; i++)
   {
     for (size_t j = 0; j < size; j++)
     {
        if(arr[i] > arr[j]){
         maxvalue=arr[i];
        }
     }
     
   }
   cout << "max value:"<< maxvalue;
     return maxvalue;

}

/* variance function */
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

/* covariance  function */
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



/* pearson correlation function */
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


/*lag operator*/
template <class T>
T lagoperator(T size,T delaytime){
size=size-delaytime;
}

/*https://www.alanzucconi.com/2016/06/06/autocorrelation-function/ */
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


/*this function implemented from  https://www.tutorialspoint.com/cplusplus-program-to-compute-dft-coefficients-directly
arr1[t] can be change another function arr1[t] equal to f(x)=x  we seperate cos and sinx from euler inequality*/
template <class T,class Y>
T Dft(T arr1[] ,int size,Y maxvalue){
   cout << "uzunluk"<< size;
  T  cosine[size];
  T  sine[size];
   for (int i = 0; i < size; i++) {
      cosine[i] += cos((2 * i * maxvalue * PI) / size);
      sine[i] += sin((2 * i * maxvalue* PI) / size);
   }
   DFT_Coeff dft_value;
   cout << "The coeffs are: ";
   for (int t = 0; t < size; t++) {
      dft_value.real += arr1[t] * cosine[t];
      dft_value.img += arr1[t] * sine[t];
   }
   cout << "(" << dft_value.real << ") - " << "(" << dft_value.img << " i)";
}



/* this function implemented from https://rosettacode.org/wiki/Fast_Fourier_transform#C.2B.2B
its help to transformation audio to signal */
void fft(CArray& x)
{
    const size_t N = x.size();
    if (N <= 1) return;
 
    // divide
    CArray even = x[std::slice(0, N/2, 2)];
    CArray  odd = x[std::slice(1, N/2, 2)];
 
    // conquer
    fft(even);
    fft(odd);
 
    // combine
    for (size_t k = 0; k < N/2; ++k)
    {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
   std::cout << "fft" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::cout <<x[i] << std::endl;
    }
}

int main() 
{ 
   /* example datasets (you can put audios )*/
   int  a[] = {1, 2, 3, 4, 5, 6,7,8,99}; 
   float  b[] = {1, 2, 3, 4,3, 5, 6,7,8,99}; 
   int len = sizeof(a)/sizeof(a[0]);
   int len1 = sizeof(b)/sizeof(b[0]);
   int md =   fmedian(a,len);
    float maxx=maxval(a,len);

    const Complex test[] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };
    CArray data(test, 8);
 
    // forward fft
    fft(data);
    return 0; 
}


