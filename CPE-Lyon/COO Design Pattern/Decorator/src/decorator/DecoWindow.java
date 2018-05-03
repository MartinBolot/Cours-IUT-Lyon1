package decorator;
/*
The Design Patterns Java Companion

Copyright (C) 1998, by James W. Cooper

IBM Thomas J. Watson Research Center

http://www.java2s.com/Code/Java/Design-Pattern/DecoratorpatterninJava.htm

 */



import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class DecoWindow extends JFrame  {

	public DecoWindow() {
		super("Deco Button");
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});

		JPanel jp = new JPanel();
		getContentPane().add(jp);


		jp.add(new CoolDecorator(new JButton("Cool")));

		jp.add(new SlashDecorator(new JButton("Slash")));
		jp.add(new SlashDecorator(new CoolDecorator(new JButton("CoolSlash"))));

		Decorator Enabled1;
		jp.add(Enabled1 = new EnabledDecorator( new JButton("Enabled1")));
		((EnabledDecorator) Enabled1).setDisabled();
		jp.add( new EnabledDecorator(new JButton("Enabled2")));//
		jp.add( new CoolDecorator(new EnabledDecorator(new JButton("EnabledCool"))));
		jp.add( new SlashDecorator( new CoolDecorator(new EnabledDecorator(new JButton("EnabledCoolSlash")))));


		setSize(new Dimension(600, 100));
		setLocation(800, 200);
		setVisible(true);   

	}

	static public void main(String argv[]) {
		new DecoWindow();
	}
}

