import java.net.*;
import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class p2p
{
	public static void main(String[] args)
	{
		try
		{
			String ipAddress = args[0];
			int port = Integer.parseInt(args[1]);

			Conn connection =  new Conn(ipAddress,port);

			//server socket
			ServerSocket server = new ServerSocket(port);
	
			while(true)
			{
				//Server
				Socket socket = server.accept();
				chatFrame chat = new chatFrame(socket);
				chat.start();
			}

		}catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}
}

class Conn
{

	JFrame frame = new JFrame();
	JPanel panel = new JPanel();
	JButton start = new JButton("Start Session");

	public Conn(String ipADD,int ID)
	{
		String ip = ipADD;
		int port = ID;
		try
		{
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

			start.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent evt)
				{
					try
					{
						Socket socket = new Socket(ip, port);
						chatFrame chat = new chatFrame(socket);
						chat.start();
					}catch(Exception ex)
					{
						ex.printStackTrace(); 
					}
					
				}
			}
			);

			panel.setLayout(new BoxLayout(panel, BoxLayout.X_AXIS));
			panel.add(start);
			frame.add(panel);
			frame.setBounds(600 , 50 , 70, 70);
			frame.setVisible(true);

		}catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}


class chatFrame extends Thread
{
	Socket socket=null;
	BufferedReader buffReader=null;
	PrintStream prtStream=null;
	JFrame frame = new JFrame();
	JPanel panel = new JPanel();
	JTextArea txtArea = new JTextArea(25, 50);
	JTextField txtField = new JTextField();
	JButton bSend = new JButton("Send");

	public chatFrame(Socket socket)
	{
		try
		{
			this.socket = socket;
			buffReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			prtStream = new PrintStream(socket.getOutputStream());

			frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
			frame.addWindowListener(new WindowAdapter()
			{
				public void windowClosing(WindowEvent ev)
				{
					try
					{
						prtStream.println("exit");	
						buffReader.close();
						prtStream.close();
						buffReader=null;
					}catch(Exception e){}
					frame.dispose();
				}
			}
			);

			bSend.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent evt)
				{
					try
					{
						String line = txtField.getText();
						txtArea.append("Me : " + line + "\n");
						prtStream.println(line);
						txtField.setText("");
					}catch(Exception ex)
					{
						ex.printStackTrace(); 
					}
					
				}
			}
			);

			panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
			panel.add(txtArea);
			panel.add(txtField);
			panel.add(bSend,BorderLayout.WEST);
			frame.setTitle("Messenger");
			frame.add(panel);
			frame.setBounds(400 , 150 , 70, 70);
			frame.setResizable(false);
			frame.pack();
			frame.setVisible(true);

		}catch(Exception e)
		{
			e.printStackTrace();
		}
	}

	public void run()
	{
		try
		{
			String line = null;
			while((line=buffReader.readLine())!=null)
			{
				if(line.compareTo("exit")==0)
				{
					txtArea.append("Connection closed");
					prtStream.println("Connection closed");
					buffReader.close();
					prtStream.close();
					break;
				}
				txtArea.append(line + "\n");
			}
		}catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}


