# master_test

## object
c/c++(c 80%) socket programing

## how to use(memo 4 me)
  socket class
  1.make socket instance  
   Client_sock sock;
  2.Make socket
   sock.MakeSocket();
  3.add host and port
   sock.SetOpt("host(IPv4)",port);
  4.connect:
   sock.Connect();
  5.send:
   sock.Send(payload);

  payload class
  1.make payload instance
   payload payl;
  2.add string 
   payl<<"somestring";
  3.u can use p32 or p64;
   payl.p32(0xdeadbeef,little endian flag);
  4.check payload
   payl.print_all();
 
## bug 
heap overflow...

