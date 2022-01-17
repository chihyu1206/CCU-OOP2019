#ifndef _INTSET_H
#define _INTSET_H

class IntSet {
 private:
  int set[101];
 public:
  IntSet();
  IntSet(int);
  IntSet setUnion(const IntSet& );
  IntSet setIntersection(const IntSet& );
  bool isEmpty(void);
  const int size(void) const;
  IntSet relativeComplement(const IntSet& );  
  IntSet symmetricDifference(const IntSet& );
  void setPrint(void) const;
  bool isEqualTo(const IntSet& ) const;
};
#endif
