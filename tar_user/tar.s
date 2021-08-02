.text
  .global _start
_start:
  .quad  ._start,.TOC.@tocbase,0
  .previous

  .global ._start
._start:

mfspr   3,815

#exit
li      0,1
li      3,4
sc
