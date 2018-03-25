//This Program does not removed 0x00

void main()
{
        __asm__ __volatile__(
                        "push $0x0068732f       \n\t"
                        "push $0x6e69622f       \n\t"
                        "mov %esp, %ebx         \n\t"
                        "push $0x0              \n\t"
                        "push %ebx              \n\t"
                        "mov %esp, %ecx         \n\t"
                        "mov $0x0, %edx         \n\t"
                        "mov $0xb, %eax         \n\t"
                        "int $0x80              \n\t"
                        );
}
~                           
