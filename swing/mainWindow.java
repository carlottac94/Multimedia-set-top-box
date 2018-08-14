//package window;
import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;

public class mainWindow extends JFrame{

	JButton b1,b2,b3,b4;
	JTextArea textArea;
	JPanel p;
	JScrollPane sp;
	JMenuBar mb;
	JTextField textField;
	private static Client client = null;
	private static final long serialVersionUID = 1L;
	static final String HOST = "localhost";
	static final int PORT = 3331;

	public static void main(String argv[]) {
		new mainWindow();
		String host = HOST;
		int port = PORT;
		if (argv.length >= 1) host = argv[0];
		if (argv.length >= 2) port = Integer.parseInt(argv[1]);

		try {
			client = new Client(host, port);
		} catch (Exception e) {
			System.err.println("Client: Couldn't connect to "+host+":"+port);
			System.exit(1);
		}

		System.out.println("Client connected to "+host+":"+port);
	}

	public mainWindow() {
		p = new JPanel();
		sp= new JScrollPane(textArea=new JTextArea(5,5));
		textField=new JTextField("Insert name of the file",20);

		add(p,BorderLayout.SOUTH);
		add(sp);
		add(textField,BorderLayout.NORTH);

		p.add(b1=new JButton("Info"));
		p.add(b2=new JButton("Play"));
		p.add(b4=new JButton("Group Info"));
		p.add(b3=new JButton("exit"));

		b1.addActionListener(new b1Listener());
		b2.addActionListener(new b2Listener());
		b4.addActionListener(new b4Listener());
		b3.addActionListener(new b3Listener());

		mb=createMenuBar();
		setJMenuBar(mb);

		setDefaultCloseOperation(EXIT_ON_CLOSE);
		pack();
		setVisible(true);
	}

	protected JMenuBar createMenuBar() {
		JMenuBar mb= new JMenuBar();
		JMenu menu = new JMenu("Menu");
		JToolBar tb=new JToolBar("Tools");

		/**
		 * AbstractAction qui permet de spécifier toutes les caractéristiques du bouton
		 * Close (le nom et la méthode actionPerformed()) et peut être inclue simultanément
		 * dans plusieurs composants graphiques, JToolBar tb et JMenu menu.
		 */
		Action actionClose = new AbstractAction("Close") {

			private static final long serialVersionUID = 1L;

			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		};

		/*Action actionNewLine= new AbstractAction("NewLine") {


			private static final long serialVersionUID = 1L;

			public void actionPerformed(ActionEvent e) {
				   t.append("New line \n");
			      }
			    };
		 */

		/**
		 * AbstractAction qui permet de spécifier toutes les caractéristiques du bouton
		 * Info (le nom et la méthode actionPerformed()) et peut être inclue simultanément
		 * dans plusieurs composants graphiques, JToolBar tb et JMenu menu. Cela permet
		 * d'envoyer au server une requête du type "print multimedia name_of_file". 
		 */
		Action actionInfo= new AbstractAction("Info") {
			private static final long serialVersionUID = 1L;

			public void actionPerformed(ActionEvent arg0) {
				String command= "print multimedia " + textField.getText();
				String s = client.send(command) + "\n";
				textArea.append(s);
			}
		};
		/**Action actionNewNewLine= new AbstractAction("NewNewLine") {

		 *

		private static final long serialVersionUID = 1L;

			public void actionPerformed(ActionEvent e) {
				  t.append("New new line \n");
					      }
					    };
		 */

		/**
		 * AbstractAction qui permet de spécifier toutes les caractéristiques du bouton
		 * Play (le nom et la méthode actionPerformed()) et peut être inclue simultanément
		 * dans plusieurs composants graphiques, JToolBar tb et JMenu menu. Cela permet
		 * d'envoyer au server une requête du type "play name_of_file". 
		 */

		Action actionPlay= new AbstractAction("Play") {

			private static final long serialVersionUID = 1L;
			public void actionPerformed(ActionEvent e) {
				String command = "play " + textField.getText();
				String s = client.send(command) + "\n";
				textArea.append(s);
				if(!(s.equals("The file is not found\n")))
					textArea.append("playing file...\n");
			}
		};

		/**
		 * AbstractAction qui permet de spécifier toutes les caractéristiques du bouton
		 * GroupInfo (le nom et la méthode actionPerformed()) et peut être inclue simultanément
		 * dans plusieurs composants graphiques, JToolBar tb et JMenu menu. Cela permet
		 * d'envoyer au server une requête du type "print group name_of_file". 
		 */
		Action actionGroup= new AbstractAction("Group Info") {

			private static final long serialVersionUID = 1L;
			public void actionPerformed(ActionEvent e) {
				String command = "print group " + textField.getText();
				String s = client.send(command) + "\n";
				s=s.replace(";","\n");
				textArea.append(s);
			}
		};

		JMenuItem item = menu.add(actionClose);
		menu.add(item);

		JButton item1 = tb.add(actionClose);
		tb.add(item1);

		item = menu.add(actionPlay);
		menu.add(item);

		item1 = tb.add(actionPlay);
		tb.add(item1);

		item = menu.add(actionInfo);
		menu.add(item);

		item1 = tb.add(actionInfo);
		tb.add(item1);

		item = menu.add(actionGroup);
		menu.add(item);

		item1 = tb.add(actionGroup);
		tb.add(item1);

		mb.add(menu);
		mb.add(tb);
		return mb;
	}

	/**
	 * version plus simple pour créer un listener pour chaque bouton: créer des classes imbriquées.
	 * Les actions et les noms des boutons sont les mêmes expliquées avant.
	 */
	class b1Listener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			String command= "print multimedia " + textField.getText();
			String s = client.send(command) + "\n";
			textArea.append(s);
		}
	}

	class b2Listener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			String command = "play " + textField.getText();
			String s = client.send(command) + "\n";
			textArea.append(s);
			if (!(s.equals("The file is not found\n")))
				textArea.append("playing file...\n");
		}
	}

	class b3Listener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
		}
	}

	class b4Listener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			String command = "print group " + textField.getText();
			String s = client.send(command) + "\n";
			s=s.replace(";","\n");
			textArea.append(s);
		}
	}

}
