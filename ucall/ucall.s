.text
  .global _start
_start:
  .quad  ._start,.TOC.@tocbase,0
  .previous

  .global ._start
._start:

li      3,0
ori     3,3,0xf110
sc      2

#exit
li      0,1
li      3,4
sc
