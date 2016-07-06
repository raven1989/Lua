#include<iostream>
#include"../src/SogouLabDic.h"
#include<vector>
#include<map>
#include"../src/Util.h"
// #include"../src/CharsetCnvtr.h"
#include<string.h>
#include<sstream>
#include<iomanip>
#include"../src/TrainDataVector.h"

using namespace std;

class SogouLabDic{
public:
  static SogouLabDic& instance(){
    if(instance_==NULL){
      instance_ = new SogouLabDic;
    }
    return *instance_;
  }
  long operator[](const string& word);
private:
  SogouLabDic();
  ~SogouLabDic();
  SogouLabDic(const SogouLabDic&);
  SogouLabDic& operator=(const SogouLabDic&);
private:
  static SogouLabDic * instance_;
  map<string, long> dict_;
};

SogouLabDic * SogouLabDic::instance_ = NULL;

SogouLabDic::SogouLabDic(){
  vector<string> pairs;
  // CharsetCnvtr trans("utf-8", "ucs-2le");
  for(int i=0; i< SOGOULABDIC_SIZE; i++){
    pairs.clear();
    string it(sogouLabDic[i]);
    split(pairs, it, ":");
    if(pairs.size()<2){ continue; }
    long freq = atol(pairs[1].c_str());
    if(freq<=0L){ continue; }
    dict_[pairs[0]] = freq;
  }
}

long SogouLabDic::operator[](const string& word){
  map<string, long>::iterator it = dict_.find(word);
  long res = 1L;
  if(it!=dict_.end()){
    res = it->second;
  }
  cout << "SogouLabDic::operator[] --> word:" << word << " freq:" << res << endl;
  return res;
}

int main(){
  for(int i=0; i<SOGOULABDIC_SIZE; i++){
    // cout << sogouLabDic[i] << endl;
  }

  vector<string> pairs;
  string str(sogouLabDic[50]);
  split(pairs, str, ":");
  cout << pairs[0] << " : " << pairs[1] << endl;
  
  string u = "板";
  string uu = "板阀";
  cout << SogouLabDic::instance()[u] << endl;
  cout << SogouLabDic::instance()[uu] << endl;

  for(int i=0; i<TAG_VECTOR_SIZE; i++){
    const double* vector = VECTORS[i];
    for(int j=0; j< VECTOR_SIZE; j++){
      cout << vector[j] << " ";
    }
    cout << endl;
  }
}
