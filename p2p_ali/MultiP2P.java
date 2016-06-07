import java.net.*;
import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MultiP2P
{
	public static void main(String[] args)
	{
		try
		{
			Connection connection =  new Connection();

			//Stablish the new server socket
			ServerSocket server = new ServerSocket(8888);
			
			while(true)
			{
				//Accepting incoming communication
				Socket socket = server.accept();
				ChatFrame chat = new ChatFrame(socket);
				chat.start();
			}
		}catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}
}

class Connection 
{
	String ip;
	int port = 8888;
	JFrame frame = new JFrame("Connection");
	JPanel panel = new JPanel();
	JLabel ipLabel = new JLabel("IP:");
	JTextField ipField = new JTextField();
	JButton button = new JButton("Connect");

	public Connection()
	{
		try
		{
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

			button.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent evt)
				{
					try
					{
						ip = ipField.getText();
						System.out.println(ip.getClass().getName());
						Socket socket = new Socket(ip, port);
						ChatFrame chat = new ChatFrame(socket);
						chat.start();
					}catch(Exception ex)
					{
						ex.printStackTrace(); 
					}
					
				}
			}
			);

			panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
			panel.add(ipLabel);
			panel.add(ipField);
			panel.add(button);
			frame.add(panel);
			frame.setSize(300 , 100);
			frame.setVisible(true);

		}catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}





class ChatFrame extends Thread
{
	Socket socket=null;
	BufferedReader buffReader=null;
	PrintStream prtStream=null;
	JFrame frame = new JFrame();
	JPanel panel = new JPanel();
	JTextArea txtArea = new JTextArea(25, 27);
	JTextField txtField = new JTextField();
	JButton button = new JButton("Send");

	public ChatFrame(Socket socket)
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
						prtStream.println("Over");	
						buffReader.close();
						prtStream.close();
						buffReader=null;
					}catch(Exception e){}
					frame.dispose();
				}
			}
			);

			button.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent evt)
				{
					try
					{
						String line = txtField.getText();
						txtArea.append("You: " + line + "\n");
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
			panel.add(button);
			frame.setTitle("Chating with: " + socket.getInetAddress().getHostName());
			frame.add(panel);
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
				if(line.compareTo("Over")==0)
				{
					txtArea.append("Exiting the communication...");
					prtStream.println("Exiting the communication...");
					buffReader.close();
					prtStream.close();
					break;
				}
				txtArea.append(socket.getInetAddress().getHostName() + ": " + line + "\n");
			}
		}catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}


