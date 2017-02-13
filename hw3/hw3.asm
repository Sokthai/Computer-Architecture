;; Paul Geromini Assignment 3   NOTE: AC & AX may the same thing here

loop:	lodd myCounter:		; Load the counter of numbers to Accumulator (AX)
		jzer done:		; If its zero no more nums to do, goto done (check the ax if it is 0 then jump to lebel done)
		subd constant1:		; Take one away from count (the accumuator of value counter - cons1 .  => counter - cons1)
		stod myCounter:	; Pass remianing numbers to do (store the result from substraction to counter . => count = count - cons1)
one:	lodd daddr: 	; Load pointer to array of numbers to do (load poiter array to accumuator (AX))
		pshi			; Push arg pointer onto stack
		addd constant1:		; Increment
		stod daddr:		; Store pointer for next fib number to do
		call fib:		; Call fib with arg on stack
		insp 1			; Clear stack on fib
two:	push			; Put return on stack (put the result frmo f(n) from AC/AX to stack 
		lodd raddr:		; load pointer to result array
		popi			; Pop result off stack into result array
		addd constant1:		; Increment
		stod raddr:		; store pointer for next number to do
		jump loop:		; Start loop again
fib:	lodl 1			; Load arg from stack
		jzer fibz: 		; if 0 go to fibz
		subd constant1:		; decrement argument
		jzer fibo:		; if 0 go to fibo
		push			; else push arg - 1 for recursive call
		call fib:		; Recursive call
		push			; push result onto stack
		lodl 1 			; load arg - 1 from stack
		subd constant1: 	; accumulator now arg - 2
		push 			; push arg - 2 onto stack
		call fib: 		; call fib function recursively
clear:	insp 1			; Clear arg - 2 from stack
		addl 0 			; put result in accumulator
		insp 2 			; Clear arguements from stack
		retn			; Return
fibz: 	lodd constant0: 	; set accumulator = 0
		retn 			; Return
fibo:	lodd constant1:		; set accumulaotr = 1
		retn			; Return
done:	halt			; Halt program execution

	;; Data Structures
.LOC 100			; Locate data begining at 100
data:	
	3
	9
	18
	23
	25
resultA:	
	0
	0
	0
	0
	0
daddr:	 data:
raddr:	 resultA:
constant0:	 0      ;constant 0
constant1:	 1		;constant 1
myCounter: 5
