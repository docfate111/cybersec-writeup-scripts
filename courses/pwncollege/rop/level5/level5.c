undefined8 main(undefined4 param_1,undefined8 *param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  undefined auStack104[8];
  undefined8 local_60;
  undefined8 *local_58;
  undefined4 local_4c;
  undefined buf[60];
  int local_c;
  
  local_60 = param_3;
  local_58 = param_2;
  local_4c = param_1;
  puts("###");
  printf("### Welcome to %s!\n",*local_58);
  puts("###\n");
  puts(
      "This challenge reads in some bytes, overflows its stack, and allows you to perform a ROPattack."
      );
  puts("Through this series of challenges, you will become painfully familiar with the concept of");
  puts("Return Oriented Programming!\n");
  sz = 0xe;
  sp = auStack104;
  rp = (undefined *)register0x00000020;
  bp = &stack0xfffffffffffffff8;
  uVar2 = read(0,buf,0x1000);
  local_c = (int)uVar2;
  printf("Received %d bytes! This is potentially %d gadgets.\n",uVar2 & 0xffffffff,
         (ulong)(buf + -(long)rp + local_c) >> 3,buf + -(long)rp);
  puts(
      "Let\'s take a look at your chain! Note that we have no way to verify that the gadgets areexecutable"
      );
  puts("from within this challenge. You will have to do that by yourself.");
  uVar1 = (int)((ulong)(buf + -(long)rp + local_c) >> 3) + 1;
  print_chain(rp,(ulong)uVar1,(ulong)uVar1,buf + -(long)rp);
  puts("Exiting!");
  return 0;
}