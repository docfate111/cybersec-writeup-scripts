int main(int param_1,undefined8 *param_2){
  int __in_fd;
  uint i;
  uint uVar2;
  char *pcVar3;
  long lVar4;
  char **ppcVar5;
  long in_FS_OFFSET;
  int local_12c;
  char *arr [16];
  char n [136];
  long local_10;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar4 = 0x10;
  ppcVar5 = arr;
  while (lVar4 != 0) {
    lVar4 = lVar4 + -1;
    *ppcVar5 = (char *)0x0;
    ppcVar5 = ppcVar5 + 1;
  }
  local_12c = 0;
  while (local_12c < 0x10) {
    __in_fd = rand();
    *(char *)((long)local_12c + 0x428a68) = (char)__in_fd + (char)(__in_fd / 0x1a) * -0x1a + 'a';
    local_12c = local_12c + 1;
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
    printf("In this challenge, there is a secret stored at %p.\n",0x428a68);
    puts(
        "If you attempt to malloc an address near where the secret is stored, it will bediscarded.\n"
        );
    while( true ) {
      while( true ) {
        printf("[*] Function (malloc/free/puts/scanf/send_flag/quit): ");
        __isoc99_scanf("%127s",n);
        __in_fd = strcmp(n,"malloc");
        if (__in_fd == 0) break;
        __in_fd = strcmp(n,"free");
        if (__in_fd == 0) {
          printf("Index: ");
          __isoc99_scanf("%127s",n);
          i = atoi(n);
          if (0xf < i) {
            __assert_fail("allocation_index < 16","<stdin>",0x60,(char *)&__PRETTY_FUNCTION__.4437);
          }
          printf("[*] free(allocations[%d])\n",(ulong)uVar1);
          free(arr[i]);
        }
        else {
          __in_fd = strcmp(n,"puts");
          if (__in_fd == 0) {
            printf("Index: ");
            __isoc99_scanf("%127s",n);
            i = atoi(n);
            if (0xf < i) {
                    /* WARNING: Subroutine does not return */
              __assert_fail("allocation_index < 16","<stdin>",0x6b,(char *)&__PRETTY_FUNCTION__.4437
                           );
            }
            printf("[*] puts(allocations[%d])\n",(ulong)uVar1);
            printf("Data: ");
            puts(arr[i]);
          }
          else {
            __in_fd = strcmp(n,"scanf");
            if (__in_fd == 0) {
              printf("Index: ");
              __isoc99_scanf("%127s",n);
              i = atoi(n);
              if (0xf < i) {
                    /* WARNING: Subroutine does not return */
                __assert_fail("allocation_index < 16","<stdin>",0x77,
                              (char *)&__PRETTY_FUNCTION__.4437);
              }
              __in_fd = malloc_usable_size(arr[i]);
              if (__in_fd != 0) {
                uVar2 = malloc_usable_size(arr[i]);
                sprintf(n,"%%%ds",(ulong)uVar2);
                printf("[*] scanf(\"%s\", notebook[%d])\n",n,(ulong)uVar1);
                __isoc99_scanf(n,arr[i],arr[i]);
              }
            }
            else {
              __in_fd = strcmp(n,"send_flag");
              if (__in_fd == 0) {
                printf("Secret: ");
                __isoc99_scanf("%127s",n);
                __in_fd = strncmp(n,(char *)0x428a68,0x10);
                if (__in_fd == 0) {
                  puts("Authorized!");
                  __in_fd = open("/flag",0);
                  sendfile(1,__in_fd,(off_t *)0x0,0x80);
                }
                else {
                  puts("Not authorized!");
                }
              }
              else {
                __in_fd = strcmp(n,"quit");
                if (__in_fd == 0) {
                  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
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
      __isoc99_scanf("%127s",n);
      i = atoi(n);
      if (0xf < i) break;
      printf("Size: ");
      __isoc99_scanf("%127s",n);
      uVar2 = atoi(n);
      printf("[*] allocations[%d] = malloc(%d)\n",(ulong)uVar1,(ulong)uVar2);
      pcVar3 = (char *)malloc((ulong)uVar2);
      arr[i] = pcVar3;
      if (arr[i] < (char *)0x430000) {
        puts("Invalid allocation detected: discarded!");
        arr[i] = (char *)0x0;
      }
      else {
        printf("[*] allocations[%d] = %p\n",(ulong)uVar1,local_118[uVar1]);
      }
    }
                    /* WARNING: Subroutine does not return */
    __assert_fail("allocation_index < 16","<stdin>",0x4a,(char *)&__PRETTY_FUNCTION__.4437);
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("argc > 0","<stdin>",0x32,(char *)&__PRETTY_FUNCTION__.4437);
}