int init_module(){
  file *fptr;
  long n;
  char *ptr;
  byte b;
  b = 0;
  fptr = (file *)filp_open("/flag",0,0);
  n = 0x10;
  ptr = flag;
  while(n != 0){
    n -= 1;
    ptr = ptr + (ulong)b * -0x10 + 8;
    *(undefined8 *)ptr = 0;
    ptr = ptr;
  }
  kernel_read(fptr,flag,0x80,&fptr->f_pos);
  filp_close(fptr,0);
  proc_entry = (proc_dir_entry *)proc_create("pwncollege",0x1b6,0,&fops);
  printk("###");
  printk("### Welcome to this kernel challenge!");
  printk("###");
  printk("This challenge will misuse the kernel in a way that will teach you about basic kernel exploitation.");
  printk("This challenge exposes a simple character device interface through `/proc/pwncollege`.");
  printk("You can open, read, write,  close this device as you would any other file.");
  printk("If you can figure out the password, the character device will allow you to read the flag.");
  printk("Good Luck");
  return 0;
}

ssize_t device_write(file *file,char *buffer,size_t length,loff_t *offset)

{
  int iVar1;
  
  printk("[device_write] file=%px, buffer=%px, length=%lu, offset=%px",file,buffer,length,offset);
  iVar1 = strncmp(buffer,"vtdwkszhbkkpjpnb",0x10);
  device_state = (iVar1 == 0) + '\x01';
  return length;
}

ssize_t device_read(file *file,char *buffer,size_t length,loff_t *offset){
  char cVar1;
  long lVar2;
  ulong uVar3;
  char *pcVar4;
  char *pcVar5;
  byte bVar6;
  bVar6 = 0;
  printk("[device_write] file=%px, buffer=%px, length=%lu, offset=%px",file,buffer,length,offset);
  pcVar4 = flag;
  if ((((device_state != '\x02') &&
       (pcVar4 = "device error: unknown state\n", device_state < '\x03')) &&
      (pcVar4 = "password:\n", device_state != '\0')) &&
     (pcVar4 = "device error: unknown state\n", device_state == '\x01')) {
    device_state = '\0';
    pcVar4 = "invalid password\n";
  }
  uVar3 = 0xffffffffffffffff;
  pcVar5 = pcVar4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + (ulong)bVar6 * -2 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  if (uVar3 <= length) {
    length = uVar3;
  }
  lVar2 = _copy_to_user(buffer,pcVar4,length);
  return uVar3 - lVar2;
}

