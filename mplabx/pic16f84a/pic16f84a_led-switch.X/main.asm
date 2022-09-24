#include "p16f84a.inc"

; CONFIG
; __config 0xFFF9
__CONFIG _FOSC_XT & _WDTE_OFF & _PWRTE_OFF & _CP_OFF

led	equ	0
switch	equ	0

	
	org	0x00
	goto	inicio

inicio
	bsf	STATUS,RP0
	movlw	b'11111'
	movwf	TRISA
	movlw	b'11111110'
	movwf	TRISB
	bcf	STATUS,RP0
	bcf	PORTA,led

ciclo
	btfsc	PORTA,switch
	goto	apagar
	bsf	PORTB,led
	goto	ciclo
	
apagar
	bcf	PORTB,led
	goto	ciclo
	
	end