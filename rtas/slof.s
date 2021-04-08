li	3,0
ori	3,3,61440       # H_RTAS
li      4,argbuf
.long 0x44000022
b .

argbuf:
.long 0x201f 	# ibm,os-term
