int main(int param_1,char *param_2){
  int __in_fd;
  unsigned int index;
  unsigned int size;
  char *ptr;
  long lVar2;
  char **ppcVar3;
  long in_FS_OFFSET;
  int local_12c;
  char *allocations[16];
  char input[136];
  long local_10;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = 0x10;
  ppcVar3 = allocations;
  while (lVar2 != 0) {
    lVar2 = lVar2 + -1;
    *ppcVar3 = (char *)0x0;
    ppcVar3 = ppcVar3 + 1;
  }
  local_12c = 0;
  while (local_12c < 0x10) {
    __in_fd = rand();
    *(char *)((long)local_12c + 0x424d61) = (char)__in_fd + (char)(__in_fd / 0x1a) * -0x1a + 'a';
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
    printf("In this challenge, there is a secret stored at %p.\n",0x424d61);
    puts(
        "If you attempt to malloc an address near where the secret is stored, it will bediscarded.\n"
        );
    while(1) {
      while(1) {
        printf("[*] Function (malloc/free/puts/scanf/send_flag/quit): ");
        scanf("%127s",input);
        __in_fd = strcmp(input,"malloc");
        if (__in_fd == 0) break;
        __in_fd = strcmp(input,"free");
        if (__in_fd == 0) {
          printf("Index: ");
          scanf("%127s",input);
          index = atoi(input);
          if (0xf < index) {
                    /* WARNING: Subroutine does not return */
            perror("allocation_index < 16","<stdin>",0x61,(char *)&__PRETTY_FUNCTION__.4437);
          }
          printf("[*] free(allocations[%d])\n",(unsigned long)index);
          free(allocations[index]);
        }
        else {
          __in_fd = strcmp(input,"puts");
          if (__in_fd == 0) {
            printf("Index: ");
            scanf("%127s",input);
            index = atoi(input);
            if (0xf < index) {
                    /* WARNING: Subroutine does not return */
              perror("allocation_index < 16","<stdin>",0x6c,(char *)&__PRETTY_FUNCTION__.4437);
            }
            printf("[*] puts(allocations[%d])\n",(unsigned long)index);
            printf("Data: ");
            puts(allocations[index]);
          } else {
            __in_fd = strcmp(input,"scanf");
            if (__in_fd == 0) {
              printf("Index: ");
              scanf("%127s",input);
              index = atoi(input);
              if (0xf < index) {
                perror("allocation_index < 16");
                return 0;
              }
              size = malloc_usable_size(allocations[index]);
              sprintf(input,"%%%ds",(unsigned long)size);
              printf("[*] scanf(\"%s\", notebook[%d])\n",input,(unsigned long)index);
              scanf(input,allocations[index],allocations[index]);
            } else {
              __in_fd = strcmp(input,"send_flag");
              if (__in_fd == 0) {
                printf("Secret: ");
                scanf("%127s",input);
                __in_fd = strncmp(input,(char *)0x424d61,0x10);
                if (__in_fd == 0) {
                  puts("Authorized!");
                  __in_fd = open("/flag",0);
                  sendfile(1,__in_fd,(off_t *)0x0,0x80);
                } else {
                  puts("Not authorized!");
                }
              } else {
                __in_fd = strcmp(input,"quit");
                if (__in_fd == 0) {
                  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
                    return 0;
                  }
                }
                puts("Unrecognized choice!");
              }
            }
          }
        }
      }
      printf("Index: ");
      scanf("%127s",input);
      index = atoi(input);
      if (0xf < index) break;
      printf("Size: ");
      scanf("%127s",input);
      size = atoi(input);
      printf("[*] allocations[%d] = malloc(%d)\n",(unsigned long)index,(unsigned long)size);
      ptr = (char *)malloc((unsigned long)size);
      allocations[index] = ptr;
      if ((allocations[index] < &global) || (&_end < allocations[index])) {
        printf("[*] allocations[%d] = %p\n",(unsigned long)index,allocations[index]);
      } else {
        puts("Invalid allocation detected: discarded!");
        allocations[index] = (char *)0x0;
      }
    }
                    /* WARNING: Subroutine does not return */
    perror("allocation_index < 16","<stdin>",0x4a,(char *)&__PRETTY_FUNCTION__.4437);
  }
                    /* WARNING: Subroutine does not return */
  perror("argc > 0","<stdin>",0x32,(char *)&__PRETTY_FUNCTION__.4437);
}