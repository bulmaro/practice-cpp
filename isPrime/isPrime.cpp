#include <math.h>

int isPrime(int number) {
  if(number <= 0) {
    return 0;
  }

  if(number <= 2) {
    return -1;
  } 

  for(int i=2; i<=sqrt(number); i++) {
    if(number%i == 0) {
      return 0;
    }
  }

  return -1;
}
