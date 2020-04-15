        .arch msp430g2553
        .p2align 1,0


        .data
State:
	.word 1

jt: 
        .word default
	.word Case0
	.word Case1
	.word Case2
	.word Case3

	.text
        .global toggle
toggle:
	mov &State,r12
	cmp #5,r12     		;State-5
	jc default		
	add r12,r12		;2*State
	mov jt(r12),r0

Case0:
	mov.b #0, &red_on
	mov.b #0, &green_on
	mov.b #1, &State
	jmp end

Case1:	mov.b #0, &red_on
	mov.b #1, &green_on
	mov.b #2, &State
	jmp end

Case2:	mov.b #1, &red_on
	mov.b #0, &green_on
	mov.b #3, &State
	jmp end

Case3:	mov.b #1, &red_on
	mov.b #1, &green_on
	mov.b #1, &State
	jmp end
	
default:
	mov.b #0, &red_on
	mov.b #0, &green_on
	mov.b #1, &State
	jmp end
end:	
	pop r0
