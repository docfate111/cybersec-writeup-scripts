int main(int param_1,char *param_2){
  int diff;
  uint i;
  uint uVar1;
  char *pcVar2;
  long lVar3;
  char **ppcVar4;
  long in_FS_OFFSET;
  int flagIsRead;
  long *flagbuf;
  char *ptrarr [16];
  char buf [136];
  long local_20;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = 0x10;
  ppcVar4 = ptrarr;
  while (lVar3 != 0) {
    lVar3 = lVar3 + -1;
    *ppcVar4 = (char *)0x0;
    ppcVar4 = ppcVar4 + 1;
  }
  if (0 < param_1) {
    puts("###");
    printf("### Welcome to %s!\n",*param_2);
    puts("###");
    puts(
        "This challenge allows you to perform various heap operations, some of which may involvethe flag."
        );
    puts(
        "Through this series of challenges, you will become familiar with the concept of heapexploitation.\n"
        );
    printf("This challenge can manage up to %d unique allocations.\n\n",0x10);
    while( true ) {
      while( true ) {
        printf("[*] Function (malloc/free/puts/read_flag/puts_flag/quit): ");
        scanf("%127s",buf);
        diff = strcmp(buf,"malloc");
        if (diff == 0) break;
        diff = strcmp(buf,"free");
        if (diff == 0) {
          printf("Index: ");
          scanf("%127s",buf);
          i = atoi(buf);
          if (0xf < i) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("allocation_index < 16","<stdin>",0x44,(char *)&__PRETTY_FUNCTION__.4424);
          }
          printf("[*] free(allocations[%d])\n",(ulong)i);
          free(ptrarr[i]);
        }
        else {
          diff = strcmp(buf,"puts");
          if (diff == 0) {
            printf("Index: ");
            scanf("%127s",buf);
            i = atoi(buf);
            if (0xf < i) {
                    /* WARNING: Subroutine does not return */
              __assert_fail("allocation_index < 16","<stdin>",0x4f,(char *)&__PRETTY_FUNCTION__.4424
                           );
            }
            printf("[*] puts(allocations[%d])\n",(ulong)i);
            printf("Data: ");
            puts(ptrarr[i]);
          }
          else {
            diff = strcmp(buf,"read_flag");
            if (diff == 0) {
              flagIsRead = 0;
              while (flagIsRead < 1) {
                printf("[*] flag_buffer = malloc(%d)\n",456);
                flagbuf = (long *)malloc(456);
                *flagbuf = 0;
                printf("[*] flag_buffer = %p\n",flagbuf);
                flagIsRead = flagIsRead + 1;
              }
              diff = open("/flag",0);
              read(diff,flagbuf + 2,0x80);
              puts("[*] read the flag!");
            }
            else {
              diff = strcmp(buf,"puts_flag");
              if (diff == 0) {
                if (*flagbuf == 0) {
                  puts("Not authorized!");
                } else {
                  puts((char *)(flagbuf + 2));
                }
              }
              else {
                diff = strcmp(buf,"quit");
                if (diff == 0) {
                  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
                    return 0;
                  }
                    /* WARNING: Subroutine does not return */
                  __stack_chk_fail();
                }
                puts("Unrecognized choice!");
              }
            }
          }
        }
      }
      printf("Index: ");
      scanf("%127s",buf);
      i = atoi(buf);
      if (0xf < i) break;
      printf("Size: ");
      scanf("%127s",buf);
      uVar1 = atoi(buf);
      printf("[*] allocations[%d] = malloc(%d)\n",(ulong)i,(ulong)uVar1);
      pcVar2 = (char *)malloc((ulong)uVar1);
      ptrarr[i] = pcVar2;
      printf("[*] allocations[%d] = %p\n",(ulong)i,ptrarr[i]);
    }
                    /* WARNING: Subroutine does not return */
    __assert_fail("allocation_index < 16","<stdin>",0x34,(char *)&__PRETTY_FUNCTION__.4424);
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("argc > 0","<stdin>",0x1f,(char *)&__PRETTY_FUNCTION__.4424);
}