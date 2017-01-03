/* This is an Intel 8080 Emulator under Construction */

#include <stdio.h>
#include "disassembler.h"

int main (void) {
    printf ("Nothing here yet\n");
    return 0;
}

/*
 * codebuffer is a valid pointer to 8080 assembly code
 * pc is the current offset into the code
 *
 * returns the number of bytes of the op
 */

int Disassemble8080 (unsigned char *codebuffer, int pc)
{
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;

    /*The value is formatted as a hexadecimal integer with four digits and leading zeros*/
    printf ("%04x ", pc);
    switch (*code)
    {
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LXI    B,#$%02x%02x", code[2], code[1]); opbytes=3; break;
        case 0x02: printf("STAX   B"); break;
        case 0x03: printf("INX    B"); break;
        case 0x04: printf("INR    B"); break;
        case 0x05: printf("DCR    B"); break;
        case 0x06: printf("MVI    B,#$%02x", code[1]); opbytes=2; break;
        case 0x07: printf("RLC"); break;
        case 0x08: printf("NOP"); break;
	    /* Ab hier von mir hinzugefügt */	   
	case 0x09: printf("DAD	  B"); break;
	case 0x0a: printf("LDAX   B"); break;
	case 0x0b: printf("DCX    B"); break;
	case 0x0c: printf("INCR   C"); break;
	case 0x0d: printf("DECR   D"); break;
	case 0x0e: printf("MVI    C,#$%02x", code[1]); opbytes=2; break;
	case 0x0f: printf("RRC"); break;
	case 0x10: printf("NOP"); break;
	case 0x11: printf("LXI    D,#$%02x%02x", code[2], code [1]); opbytes=3; break; 
	case 0x12: printf("STAX   D"); break;      
	case 0x13: printf("INX    D"); break;
	case 0x14: printf("INR    D"); break;
        case 0x15: printf("DCR    D"); break; 
	case 0x16: printf("MVI    D,#$%02x", code[1]); opbytes=2; break;      
	case 0x17: printf("RAL"); break;
	case 0x18: printf("NOP"); break;
	case 0x19: printf("DAD    D"); break; 
	case 0x1a: printf("LDAX   D"); break;      
	case 0x1b: printf("DCX    D"); break;
	case 0x1c: printf("INR    E"); break;      
	case 0x1d: printf("DCR    E"); break; 
	case 0x1e: printf("MVI    E,#$%02x", code[1]); opbytes=2; break;      
	case 0x1f: printf("RAR"); break;
	case 0x20: printf("RIM"); break;
	
	
		   /* ........ */
        case 0x3e: printf("MVI    A,#0x%02x", code[1]); opbytes = 2; break;
            /* ........ */
        case 0xc3: printf("JMP    $%02x%02x",code[2],code[1]); opbytes = 3; break;
            /* ........ */
    }

    printf("\n");

    return opbytes;
}
