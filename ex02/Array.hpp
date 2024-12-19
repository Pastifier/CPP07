#pragma once

#include <exception>

template <typename T> class Array {
public:
  Array() : _nmemb(1) {
    _memb = new T[1];
    _myBzero(_memb, 1);
  }

  ~Array() { delete[] _memb; }

  Array(unsigned int n_) : _nmemb(n_) {
    _memb = new T[n_];
    _myBzero(_memb, n_);
  }

  Array(Array const &other) {
    _nmemb = other.size();
    _memb = new T[_nmemb];
    _myMemcpy(other.getAddr(), _memb, _nmemb);
  }

  Array &operator=(Array const &rhs) {
    if (this != &rhs) {
      _nmemb = rhs.size();
      delete[] _memb;
      _memb = new T[_nmemb];
      _myMemcpy(rhs.getAddr(), _memb, _nmemb);
    }
    return *this;
  }

  T &operator[](unsigned int idx_) {
    if (idx_ >= _nmemb)
      throw ArraySegmentationFault();
    return _memb[idx_];
  }

  unsigned int size() const { return _nmemb; }
  const T *getAddr() const { return _memb; }

private:
  T *_memb;
  unsigned int _nmemb;

  void _myBzero(T *dst, unsigned int nbytes_) {
    char *cdst = reinterpret_cast<char *>(dst);
    for (unsigned int i = 0; i < nbytes_; i++) {
      unsigned int idx = i * sizeof(T);
      new (cdst + idx) T();
    }
  }
  void _myMemcpy(const T *src, T *dst, unsigned int nmemb_) {
    char *cdst = reinterpret_cast<char *>(dst);

    for (unsigned int i = 0; i < nmemb_; i++) {
      unsigned int idx = i * sizeof(T);
      new (cdst + idx) T(src[i]);
    }
  }

  class ArraySegmentationFault : public std::exception {
  public:
    ArraySegmentationFault() {}
    ~ArraySegmentationFault() throw() {}
    const char *what() const throw() { return "ERROR: Index out-of-bounds"; }
  };
};
