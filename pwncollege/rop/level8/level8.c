int main(int param_1,char *param_2){
  ssize_t sVar1;
  undefined buf[28];
  undefined4 local_c;
  puts("###");
  printf("### Welcome to %s!\n",*param_2);
  puts("###\n");
  sVar1 = read(0,buf,0x1000);
  local_c = (undefined4)sVar1;
  puts("Exiting!");
  return 0;
}
