import java.net.*;
import java.io.*;

class Client2 extends Thread{
public static int buffer_size = 1024;
public static DatagramSocket ds1,ds2;
public static byte buffer[] =new byte[buffer_size];
public static String msg;

public static void TheServer() throws Exception {
while(true)
{
System.out.println("");
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
msg=br.readLine();
buffer=msg.getBytes();
ds2.send(new DatagramPacket(buffer,msg.length(),InetAddress.getLocalHost(),1777));
}
}
public void run()
{
try
{
ds1=new DatagramSocket(1888);
System.out.println("holdin the port");
while(true) {
DatagramPacket p = new DatagramPacket(buffer, buffer.length);
ds1.receive(p);
System.out.println(new String(p.getData(), 0, p.getLength()));
}
}
catch(Exception e)
{
}
}
public static void main(String args[]) throws Exception {
Thread t=new Client2();
t.start();
ds2= new DatagramSocket(1666);
TheServer();
}
}