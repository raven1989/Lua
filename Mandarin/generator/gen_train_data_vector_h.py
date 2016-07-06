#coding=utf-8

dic = file('bag_vector', 'r')
mapping = file('domain2ad_tag_map', 'r')
to = file('../src/TrainDataVector.h', 'w')

first_line= dic.readline()
bag_idf = first_line.split(',')
bags = []
idfs = []
special = ['\"']
bag_idf_size = 0
for it in bag_idf:
  bag, idf = it.split('|')
  if bag in special:
    bag = '\\' + bag
  bags.append('\"'+bag.decode('utf-8').encode('utf-8')+'\"')
  idfs.append(idf)
  bag_idf_size += 1

tag_map = {}
while True:
  line = mapping.readline()
  if not line:
    break
  sub, main, tags = line.split(' ')
  # print sub, main, tags
  tag_map[sub] = tags.strip()

tags = []
vectors = []
cnt = 0
while True:
  line = dic.readline()
  if not line:
    break
  sub, main, size, vector = line.split('\t')
  tags.append("\"%s %s %s\""%(sub, main, tag_map[sub]))
  vectors.append("{%s}"%vector.strip())
  cnt+=1

vector_size = len(vectors[0].strip().split(','))

head = "#ifndef __TRAINDATAVECTOR_H__\n#define __TRAINDATAVECTOR_H__\n\n#define BAG_IDF_SIZE %d\n#define TAG_VECTOR_SIZE %d\n#define VECTOR_SIZE %d\n"%(bag_idf_size, cnt, vector_size)
tail = "#endif" 
str_bag = "const char* BAGS[BAG_IDF_SIZE] = {\n" + ','.join(bags) + "\n};\n"
str_idf = "const double IDFS[BAG_IDF_SIZE] = {\n" + ','.join(idfs) + "\n};\n" 
str_tag = "const char* TAGS[TAG_VECTOR_SIZE] = {\n" + ','.join(tags) + "\n};\n"
str_vector = "const double VECTORS[TAG_VECTOR_SIZE][VECTOR_SIZE] = {\n" + ',\n'.join(vectors) + "\n};\n"

chapters = [head, str_bag, str_idf, str_tag, str_vector, tail]
content = '\n'.join(chapters)
print str_bag
to.write(content)

to.close()
mapping.close()
dic.close()

