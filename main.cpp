
#include <cstdlib>
#include <iostream>

double getDollarExposure(double spotEntry, int noShares, double marginFactor);

int getSharesForTargetExposure(float targetExposure, float underlyingPrice, float marginFactor);

int main (int argc, char * argv[]) {
  /*
    totalSupply = 1_000_000
    wtiIndexPrice = 89.15
    targetExposureDollars = 1_000_00
   */
  float targetExposure = 1000000.00;
  float wtiIndexPrice = 89.15;
  float marginFactor = 0.05;
  int totalSupply = 1000000;
  
  int targetShares = getSharesForTargetExposure(targetExposure, wtiIndexPrice, marginFactor);
  double dollarExposure = getDollarExposure(wtiIndexPrice, targetShares, marginFactor);
  double notionalExposure = dollarExposure / marginFactor;
  double notionalTokenValue  = notionalExposure / totalSupply;
  
  printf("target shares: %d\n", targetShares);
  printf("dollar exposure: %f\n", dollarExposure);
  printf("notional exposure: %f\n", dollarExposure / marginFactor);
  printf("notional token value: %f\n", notionalTokenValue);
  return 0;
}

double getDollarExposure(double spotEntry, int noShares, double marginFactor) {
  return spotEntry * noShares * marginFactor;
}

int getSharesForTargetExposure(float targetExposure, float underlyingPrice, float marginFactor) {
  return (int) (targetExposure / underlyingPrice);// * marginFactor;
}
