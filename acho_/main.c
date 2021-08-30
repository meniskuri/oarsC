#include "aradani.h"
#include <stdio.h>
#include <stdlib.h>
N(talloc);
N(nt3);
N(narS) { printf("narS\n"); }
N(narY) { printf("narY\n"); }
N(narN) { printf("narN\n"); }
N(narA) { printf("narA\n"); }
N(narC) { printf("narC\n"); }
N(narK) { printf("narK\n"); }
N(tik) { A5(, narS, narY, narN, 32, nt3) Dot(); }
N(tak) { A5(, narA, narC, narK, 32, nt3) Dot(); }
N(toe) {
  RT(b);
  RT(a);
  // printf("%d\n", aο[aρ] == narS);
  At(a, b) A(a, aο[aρ]) Dot(a);
}
N(arlog);
N(dalog);
N(anlog);
int main() {
  Nt(o, malloc(512 * sizeof(void *)), 512);
  P3(o, anlog, dalog, arlog) A5(o, tik, tak, da, toe, da) Dot(o);
  free(oο);
  return 0;
}
N(arlog) { printf("ara"); }
N(dalog) { printf("da %p", ο[--α]); }
N(anlog) { printf("an"); }
N(talloc) {
  long ws = (long)ο[--α];
  if (ρ < α + ws) {
    C(, 2);
  } else {
    long n = α;
    while (n--)
      ο[ws + n] = ο[n];
    void **nο = &ο[ws];
    long nα = α, nρ = ρ - ws, nσ = σ - ws;
    A(n, ws) C(n, 1);
  }
}
N(nt3_1) {
  R(unsigned long, ws);
  R(void *, r2);
  R(void *, r1);
  R(void *, r0);
  Nt(n, ο - ws, ws);
  P3(n, r0, r1, r2)
  At(, n) C(, 1);
}
N(nt3) { A3(, talloc, nt3_1, da) Dot(); }