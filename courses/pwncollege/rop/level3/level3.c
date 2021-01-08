void win_stage_1(int param_1){
  int __in_fd;
  size_t __count;
  off_t local_28;
  int local_1c;
  if (param_1 != 1) {
    puts("Error: Incorrect value!");
    exit(1);
  }
  __in_fd = flag_size();
  local_1c = __in_fd / 5 + 1;
  local_28 = 0;
  __count = SEXT48(local_1c);
  __in_fd = open("/flag",0);
  sendfile(1,__in_fd,&local_28,__count);
  return;
}
void win_stage_2(int param_1)

{
  int __in_fd;
  size_t __count;
  off_t local_28;
  int local_1c;
  
  if (param_1 != 2) {
    puts("Error: Incorrect value!");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __in_fd = flag_size();
  local_1c = __in_fd / 5 + 1;
  local_28 = (long)local_1c;
  __count = SEXT48(local_1c);
  __in_fd = open("/flag",0);
  sendfile(1,__in_fd,&local_28,__count);
  return;
}

void win_stage_3(int param_1)

{
  int __in_fd;
  size_t __count;
  off_t local_28;
  int local_1c;
  
  if (param_1 != 3) {
    puts("Error: Incorrect value!");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __in_fd = flag_size();
  local_1c = __in_fd / 5 + 1;
  local_28 = (long)(local_1c * 2);
  __count = SEXT48(local_1c);
  __in_fd = open("/flag",0);
  sendfile(1,__in_fd,&local_28,__count);
  return;
}
void win_stage_4(int param_1)

{
  int __in_fd;
  size_t __count;
  off_t local_28;
  int local_1c;
  
  if (param_1 != 4) {
    puts("Error: Incorrect value!");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __in_fd = flag_size();
  local_1c = __in_fd / 5 + 1;
  local_28 = (long)(local_1c * 3);
  __count = SEXT48(local_1c);
  __in_fd = open("/flag",0);
  sendfile(1,__in_fd,&local_28,__count);
  return;
}
void win_stage_5(int param_1){
  int __in_fd;
  size_t __count;
  off_t local_28;
  int local_1c;
  
  if (param_1 != 5) {
    puts("Error: Incorrect value!");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __in_fd = flag_size();
  local_1c = __in_fd / 5 + 1;
  local_28 = (long)(local_1c * 4);
  __count = SEXT48(local_1c);
  __in_fd = open("/flag",0);
  sendfile(1,__in_fd,&local_28,__count);
  return;
}
undefined8 main(undefined4 param_1,undefined8 *param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  undefined auStack152 [8];
  undefined8 local_90;
  undefined8 *local_88;
  undefined4 local_7c;
  undefined local_78 [108];
  int local_c;
  
  local_90 = param_3;
  local_88 = param_2;
  local_7c = param_1;
  puts("###");
  printf("### Welcome to %s!\n",*local_88);
  puts("###\n");
  puts(
      "This challenge reads in some bytes, overflows its stack, and allows you to perform a ROPattack."
      );
  puts("Through this series of challenges, you will become painfully familiar with the concept of");
  puts("Return Oriented Programming!\n");
  sz = 0x14;
  sp = auStack152;
  rp = (undefined *)register0x00000020;
  bp = &stack0xfffffffffffffff8;
  puts("In this challenge, there are 5 stages of win functions.");
  puts("The functions are labeled win_stage_1 through win_stage_5.");
  puts("I will leave it to you to find the functions for each one!");
  puts("In addition to going to each function in the right order (1-5),");
  puts("you must also pass an argument to each function you visit!");
  puts("The argument you pass will be stage number.");
  puts("For instance, `win_stage_1(1)` is the correct call.\n");
  uVar2 = read(0,local_78,0x1000);
  local_c = (int)uVar2;
  printf("Received %d bytes! This is potentially %d gadgets.\n",uVar2 & 0xffffffff,
         (ulong)(local_78 + -(long)rp + local_c) >> 3,local_78 + -(long)rp);
  puts(
      "Let\'s take a look at your chain! Note that we have no way to verify that the gadgets areexecutable"
      );
  puts("from within this challenge. You will have to do that by yourself.");
  uVar1 = (int)((ulong)(local_78 + -(long)rp + local_c) >> 3) + 1;
  print_chain(rp,(ulong)uVar1,(ulong)uVar1,local_78 + -(long)rp);
  puts("Exiting!");
  return 0;
}
