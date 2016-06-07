import java.io.*;
import java.util.*;
import java.net.*;
import java.io.File;
import java.io.FileWriter;
import java.util.regex.*;
import java.net.InetAddress;
import static java.lang.System.out;

public class  Server
{
  Vector<String> users = new Vector<String>();
  Vector<HandleClient> clients = new Vector<HandleClient>();

  int MaxClients = 10;

  public void process(int PORT) throws Exception  
  {
    ServerSocket server = new ServerSocket(PORT,MaxClients);
    while(true) 
    {
      Socket client = server.accept();
      HandleClient c = new HandleClient(client);
      clients.add(c);
    }
  }

  public static void main(String [] args) throws Exception 
  {
      int port = Integer.parseInt(args[0]);
      new Server().process(port);
  }

  public void bcast(String user, String message,String sendTo)  
  {
    // send message to all connected users
    for (HandleClient c : clients)
    {
      if (!c.getUsername().equals(user))
      {
        //send to the specific recepient's user or broadcast to all
        if(sendTo.equals("broadcast"))
        {
          if(!c.getUsername().equals(user))
          {
            c.sendMessage(user,message);
          }
        }
        else if(c.getUsername().equals(sendTo))
        {
          c.sendMessage(user,message);
        }
      }
    }
  }

  class HandleClient extends Thread 
  {
    String name = "";
    String sTo;
    Vector<String> sendTo = new Vector<String>();
    int recTotal;
    BufferedReader buffReader;
    PrintWriter output;
    File file = new File("db.txt");
    InetAddress ipAddr = InetAddress.getLocalHost();

    public HandleClient(Socket client) throws Exception 
    {
      // get input and output streams
      buffReader = new BufferedReader(new InputStreamReader(client.getInputStream())) ;
      output = new PrintWriter (client.getOutputStream(),true);

      // get username from client
      output.println("\n\tEnter receiver's username in paranthesis to initiate communication");
      output.println("\te.g. (Fadzil) or (broadcast) to all.\n\n");
      output.println("Enter a User Name.. ");
      name  = buffReader.readLine();
      output.println("Enter your receivers in paranthesis.. E.g (ali)(abu)\n");
      sTo  = buffReader.readLine();
      
      Matcher m = Pattern.compile("\\(([^)]+)\\)").matcher(sTo);
      while(m.find()) 
      {
        sTo = m.group(1);
        sendTo.add(sTo);
        //output.println(sTo);
      }
      if(!file.exists())
      {
        file.createNewFile();
      }

      FileWriter fileWritter = new FileWriter(file.getName(),true);
      BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
      bufferWritter.write(name);
      bufferWritter.write(",");
      bufferWritter.write(ipAddr.getHostAddress());
      bufferWritter.newLine();
      bufferWritter.close();

      users.add(name); // add to vector
      output.println("--------------------[ Welcome "+name+" ]--------------------\n");
      start();
    }

    public void sendMessage(String uname,String  msg)  
    {
      output.println( uname + " : " + msg);
    }

    public String getUsername() 
    {  
      return name; 
    }

    public void run()  
    {
      String line;
      
      try    
      {
        while(true)   
        {
          line = buffReader.readLine();
          if("EXIT".equals(line))
          {
            output.println("\nGoodbye and see you soon");
            clients.remove(this);
            users.remove(name);
            buffReader.close();
            break;
          }
          
          //String sendTo ="";
          /*
          Matcher m = Pattern.compile("\\(([^)]+)\\)").matcher(line);
          while(m.find()) 
          {
            sendTo = m.group(1);
            line = line.replaceAll("\\(.*\\)", "");
            bcast(name,line,sendTo);   
          }
          */
          for(int i=0; i<sendTo.size(); i++)
          {
            bcast(name,line,sendTo.get(i));
          }
          
        }
      }
      catch(Exception e) 
      {
        System.out.println(e.getMessage());
      }
    } // end of run()
  }
}