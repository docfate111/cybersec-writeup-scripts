int main(int param_1){
  int __fd;
  uint index;
  uint uVar1;
  char *pcVar2;
  long lVar3;
  char **ppcVar4;
  long in_FS_OFFSET;
  int timesFlagIsWritten;
  void *flagbuf;
  char *ptrarray [16];
  char i [136];
  long local_10;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = 0x10;
  ppcVar4 = ptrarray;
  while (lVar3 != 0) {
    lVar3 = lVar3 + -1;
    *ppcVar4 = (char *)0x0;
    ppcVar4 = ppcVar4 + 1;
  }
  puts("###");
  printf("### Welcome to %s!\n",*param_2);
  puts("###");
  puts(
      "This challenge allows you to perform various heap operations, some of which may involve theflag."
      );
  puts(
      "Through this series of challenges, you will become familiar with the concept of heapexploitation.\n"
      );
  printf("This challenge can manage up to %d unique allocations.\n\n",0x10);
  printf("In this challenge, the flag buffer is allocated %d times before it is used.\n\n",2);
  while( true ) {
    while( true ) {
      printf("[*] Function (malloc/free/puts/read_flag/quit): ");
      scanf("%127s",i);
      __fd = strcmp(i,"malloc");
      if (__fd == 0) break;
      __fd = strcmp(i,"free");
      if (__fd == 0) {
        printf("Index: ");
        scanf("%127s",i);
        index = atoi(i);
        if (0xf < index) {
          __assert_fail("allocation_index < 16","<stdin>",0x40,(char *)&__PRETTY_FUNCTION__.4419);
        }
        printf("[*] free(allocations[%d])\n",(ulong)index);
        free(ptrarray[index]);
      } else {
        __fd = strcmp(i,"puts");
        if (__fd == 0) {
          printf("Index: ");
          scanf("%127s",i);
          index = atoi(i);
          if (0xf < index) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("allocation_index < 16","<stdin>",0x4b,(char *)&__PRETTY_FUNCTION__.4419);
          }
          printf("[*] puts(allocations[%d])\n",(ulong)index);
          printf("Data: ");
          puts(ptrarray[index]);
        } else {
          __fd = strcmp(i,"read_flag");
          if (__fd == 0) {
            timesFlagIsWritten = 0;
            while (timesFlagIsWritten < 2) {
              printf("[*] flag_buffer = malloc(%d)\n",0x2ea);
              flagbuf = malloc(0x2ea);
              printf("[*] flag_buffer = %p\n",flagbuf);
              timesFlagIsWritten += 1;
            }
            __fd = open("/flag",0);
            read(__fd,flagbuf,0x80);
            puts("[*] read the flag!");
          } else {
            __fd = strcmp(i,"quit");
            if (__fd == 0) {
              if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail();
              }
              return 0;
            }
            puts("Unrecognized choice!");
          }
        }
      }
    }
    printf("Index: ");
    scanf("%127s",i);
    index = atoi(i);
    if (0xf < index) break;
    printf("Size: ");
    scanf("%127s",i);
    uVar1 = atoi(i);
    printf("[*] allocations[%d] = malloc(%d)\n",(ulong)index,(ulong)uVar1);
    pcVar2 = (char *)malloc((ulong)uVar1);
    ptrarray[index] = pcVar2;
    printf("[*] allocations[%d] = %p\n",(ulong)index,ptrarray[index]);
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("allocation_index < 16","<stdin>",0x30,(char *)&__PRETTY_FUNCTION__.4419);
}