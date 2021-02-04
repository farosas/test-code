li 	3,4352
mtspr 	153,3
# r3 = char, r4 = hvtermno */
li      3,42
li      4,0
sldi    6,3,(24+32)
li      3,88 # H_PUT_TERM_CHAR
li      5,1
.long 0x44000022
b -0x18
#blr
#b .
