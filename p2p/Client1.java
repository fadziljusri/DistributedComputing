import java.net.*;
import java.io.*;

class Client1 extends Thread{
public static int buffer_size = 1024;
public static DatagramSocket ds3,ds4;
public static byte buffer[] =new byte[buffer_size];
public static String msg;

public static void TheServer() throws Exception {
while(true)
{
System.out.println("");
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
msg=br.readLine();
buffer=msg.getBytes();
ds4.send(new DatagramPacket(buffer,msg.length(),InetAddress.getLocalHost(),1888));
}
}
public void run() 
{
try
{
ds3=new DatagramSocket(1777);
System.out.println("holdin the port");
while(true) {
DatagramPacket p = new DatagramPacket(buffer, buffer.length);
ds3.receive(p);
System.out.println(new String(p.getData(), 0, p.getLength()));
}
}
catch(Exception e)
{
}
}
public static void main(String args[]) throws Exception {
Thread t=new Client1();
t.start();
ds4 = new DatagramSocket(1555);
TheServer();
}
}