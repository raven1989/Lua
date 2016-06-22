#ifndef __UTIL_H__
#define __UTIL_H__

#include<cstdlib>
#include<vector>

void split(std::vector<std::string>& res, std::string& str, const std::string& d=" "){
  size_t begin = 0;
  size_t dpos = std::string::npos;
  do{
    dpos = str.find(d, begin);
    if(dpos!=std::string::npos){
      res.push_back(str.substr(begin, dpos-begin));
      begin = dpos+1;
    }else{
      res.push_back(str.substr(begin));
      break;
    }
  }while(dpos != std::string::npos && begin<str.size());
}

#endif
