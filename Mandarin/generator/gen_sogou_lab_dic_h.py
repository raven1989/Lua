dic = file('SogouLabDic.utf8.dic', 'r')
to = file('../src/SogouLabDic.h', 'w')

l = []
cnt = 0
while True:
  line = dic.readline()
  if not line:
    break
  word, freq = line.split('\t')[0:2]
  l.append("\"%s:%s\""%(word, freq))
  cnt+=1

s = "#ifndef __SOGOULABDIC_H__\n#define __SOGOULABDIC_H__\n#define SOGOULABDIC_SIZE %d\nconst char* sogouLabDic[SOGOULABDIC_SIZE] = {\n"%cnt + ',\n'.join(l) + "\n};\n#endif" 
print s
to.write(s)

to.close()
dic.close()

