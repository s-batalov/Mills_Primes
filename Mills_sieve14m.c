/**************************************************************/
/* a Mills #14 simple sieve, v.1.1  (copyleft) 2014 S.Batalov */
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <primesieve.h>
#include <inttypes.h>

#define T1   1000000000000ULL
#define CLIMIT    15000000ULL

uint64_t mulmod(uint64_t a, uint64_t b, uint64_t c) {
  uint64_t d; /* to hold the result of a*b mod c */
  /* calculates a*b mod c, stores result in d */
  asm ("movq %1, %%rax;"       /* put a into rax */
       "mulq %2;"              /* mul a*b -> rdx:rax */
       "divq %3;"              /* (a*b)/c -> quot in rax remainder in rdx */
       "movq %%rdx, %0;"       /* store result in d */
       :"=r"(d)                /* output */
       :"r"(a), "r"(b), "r"(c) /* input */
       :"%rax", "%rdx"         /* clobbered registers */
      );
  return d;
}

int main(int argc,char **argv) {
  uint64_t f,i,j,l,l2,p; char buf[64], *s, *S;
  primesieve_iterator it;
  primesieve_init(&it);
  if(argc<2 ) { printf(" Use: %s from_T to_T > output_file\n"
		       "\t a Mills #14 simple sieve, v.1.1\n"
		       "\t (copyleft) 2014 S.Batalov\n",argv[0]); exit(0); }
  l = atoll(argv[1]);
  l2= atoll(argv[2]);
  printf("# from %lld to %lld T\n",l,l2); fflush(stdout);
  l  *= T1; if(l==0) l=3;
  l2 *= T1;
  S=calloc(CLIMIT/2,1); if(!S) {printf("### no RAM\n"); exit(-1); }
  if(l > 5ULL) { 
    FILE *fp=fopen("SI1411","r"); // save sieved values from 0-1T run here
    for(i=0;i<CLIMIT/2;i++) S[i]=1;
    while((s=fgets(buf,64,fp))) S[strtol(s,NULL,10)/2-1]=0;
    fclose(fp);
  }
  primesieve_jump_to(&it, l, l2);
  while ((p = primesieve_next_prime(&it)) < l2) {
#define CUBE(c) i=mulmod(i,mulmod(i,i,p),p)+c
    uint64_t i=2521008887ULL;
    CUBE(80);
    CUBE(12);
    CUBE(450);
    CUBE(894);
    CUBE(3636);
    CUBE(70756);
    CUBE(97220);
    CUBE(66768);
    CUBE(300840);
    CUBE(1623568);
    i=p-mulmod(i,mulmod(i,i,p),p);
    if(i&1) i+=p;
    for(i=i/2-1;i<CLIMIT/2;i+=p) if(!S[i]) {
      S[i]=1; printf("# %llu | %llu\n",p,i*2+2);
    }
  }
  // for(j=0;j<CLIMIT/2;j++) if(!S[j]) printf("%llu\n",j*2+2);
  exit(0);
}
