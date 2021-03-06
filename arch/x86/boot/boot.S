.set Load,0x7c00
.set CODE_SEG,0x8
.set DATA_SEG,0x10
#print:
#        movw $debug,%si
#        movw %si,%ax 
#        testb $0x0,%al 
#        je return
#        movb $0x0E,%ah
#        movw $0x7,%bx 
#        int $0x10 
#        jmp print
#return:
#	ret
.global start
start:
	.code16
	cli
	cld
	xorw %ax,%ax
	movw %ax,%ds
	movw %ax,%es
	movw %ax,%ss

	movw $start,%sp
#	movw %si,%sp
#	movw $start,%di
#	movw $0x100,%cx
#	rep
#	movsw
#	movw %di,%bp
#	movb $CODE_SEG,%cl

A20.1:
	inb     $0x64,%al
        testb   $0x2,%al
#	cmovz	$0xd1,%al
        jnz     A20.1
        movb    $0xd1,%al
        outb    %al,$0x64
A20.2:
	inb 	$0x64,%al
	testb 	$0x2,%al
#	cmovz	$0xdf,%al
	jnz 	A20.2
	movb 	$0xdf,%al
	outb	%al,$0x60
switch_mode:
	lgdt 	gdt_table
	mov 	%cr0,%eax
	orl 	$1,%eax
	mov 	%eax,%cr0
	ljmp 	$CODE_SEG,$protseg

protseg:
	.code32
	movw $DATA_SEG,%ax
	movw %ax,%ds
	movw %ax,%ss
	movw %ax,%es
	movw %ax,%fs
	movw %ax,%gs
	xor %eax,%eax
#	mov $0x1, %eax
#	CPUID
#	jmp spin
	call cmain
#	jmp print
spin:
	jmp spin
.p2align 2
gdt_table:
	.word gdt-gdt_end-1
	.long gdt
gdt:
	.long 0,0
	.byte 0xff,0xff,0,0,0,0x9A,0xCF,0
	.byte 0xff,0xff,0,0,0,0x92,0xCF,0
gdt_end:

