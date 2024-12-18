#pragma once

// template <typename P> void iter(P addr[], int len, void (*func)(P *)) {
//   for (int i = 0; i < len; i++) {
//     func(addr + i);
//   }
// }

template <typename T, typename F> void iter(T addr[], int len, F func) {

  for (int i = 0; i < len; i++) {
    func(addr[i]);
  }
}
