#include<iostream>
#include"../src/SogouLabDic.h"
#include<vector>
#include"../src/Util.h"
#include"../src/CharsetCnvtr.h"

using namespace std;

int main(){
  for(int i=0; i<SOGOULABDIC_SIZE; i++){
    // cout << sogouLabDic[i] << endl;
  }

  vector<string> pairs;
  string str(sogouLabDic[50]);
  split(pairs, str, ":");
  cout << pairs[0] << " : " << pairs[1] << endl;

  CharsetCnvtr trans("utf-8", "unicode");
  cout << trans.cnvt(pairs[0]) << endl;
}
