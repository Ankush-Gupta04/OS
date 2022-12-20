Strings are generated using 

![image](https://user-images.githubusercontent.com/100823564/208731889-57db5de9-057c-4bda-b901-bfbdb7994f0c.png)

socket :

![image](https://user-images.githubusercontent.com/100823564/208732389-db9bd4a8-a338-45bf-b4c6-69ce44ae60eb.png)

creation

![image](https://user-images.githubusercontent.com/100823564/208732496-bfe02935-dca0-44ee-8a9a-63fdfb7f4a4d.png)

connect

![image](https://user-images.githubusercontent.com/100823564/208732579-9adb7ea6-6b87-4634-b4c3-82186bd04c27.png)

write

![image](https://user-images.githubusercontent.com/100823564/208732648-530572cc-b38b-4f3b-a885-7737287eac92.png)

read

![image](https://user-images.githubusercontent.com/100823564/208732699-e41e8e47-8b71-4e5d-b42b-dd3ea50a07e6.png)

close


fifo:

mkfifo(fifo,0666); :: creation

fd = open(fifo,O_WRONLY); :: open

write(fd,list[index + 1 + i],str_len+1); :: write

read(fd,&index,sizeof(int)); :: read

close(fd); :: close


shared memory:

![image](https://user-images.githubusercontent.com/100823564/208733457-4af0a793-172e-468b-a731-b676b05f2057.png)

creation, attaching

![image](https://user-images.githubusercontent.com/100823564/208733575-c9f6ef3a-2e6a-4f96-9033-582b2b30c90a.png)

writing and waiting
