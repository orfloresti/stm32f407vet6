;blink_led.asm

list P = 16F877A
include P16F877A.inc


STATUS EQU 0x03
PORTB EQU 0x06
TRISB EQU 0x86
PORTD EQU 0x08
TRISD EQU 0x88

CBLOCK 0x20
		Kount120us ;Delay count (number of instr cycles for Delay)
		Kount100us
		Kount1ms
		Kount10ms
		Kount1s
		Kount10s
		Kount1m
ENDC


org 0x0000 ;line 1
		goto START ;line 2 ($0000)
org 0x05
START
		banksel TRISD
	
		movlw 0x00
		movwf TRISD
		movwf TRISB 
		banksel PORTB
		clrf PORTB
		clrf PORTD 
		call Delay100ms
		
repeat	movlw 0xFF
		movwf PORTB
		Call Delay1s
		movlw 0x00
		movwf PORTB
		Call Delay1s
		goto repeat

;==========================================================
;DELAY SUBROUTINES
Delay120us
		banksel Kount120us
		movlw H'C5' ;D'197'
		movwf Kount120us
R120us
		decfsz Kount120us
		goto R120us
		return
;
Delay100us
		banksel Kount100us
		movlw H'A4'
		movwf Kount100us
R100us
		decfsz Kount100us
		goto R100us
		return
;
;1ms Delay
Delay1ms
		banksel Kount1ms
		movlw 0x0A ;10
		movwf Kount1ms
R1ms 
		call Delay100us
		decfsz Kount1ms
		goto R1ms
		return
;
;10ms Delay
; call 100 times of 100 us Delay (with some time discrepancy)
Delay10ms
		banksel Kount10ms
		movlw H'64' ;100
		movwf Kount10ms
R10ms 
		call Delay100us
		decfsz Kount10ms
		goto R10ms
		return
;;
;1 sec Delay
;call 100 times of 10ms Delay
Delay1s
		banksel Kount1s
		movlw H'64'
		movwf Kount1s
R1s 
		call Delay10ms
		decfsz Kount1s
		goto R1s
		return
;;
;10 s Delay
;call 10 tiems of 1 s Delay
Delay10s
		banksel Kount10s
		movlw H'0A' ;10
		movwf Kount10s
R10s 
		call Delay1s
		decfsz Kount10s
		goto R10s
		return
;
;1 min Delay
;call 60 times of 1 sec Delay
Delay1m
		banksel Kount1m
		movlw H'3C' ;60
		movwf Kount1m
R1m 
		call Delay1s
		decfsz Kount1m
		goto R1m
		return

;;
;100 msec Delay
;call 10 times of 10ms Delay
Delay100ms
		banksel Kount1s
		movlw H'0A' ;10
		movwf Kount1s
R100ms 
		call Delay10ms
		decfsz Kount1s
		goto R100ms
		return
;;
;======================================================
END

;Increase delay at instw and dataw to 100ms and start up to 100ms (2014-1-7)