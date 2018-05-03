package launcher.localLauncher;

import java.awt.Dimension;
import java.util.Observer;

import javax.swing.JFrame;

import vue.ChessGameGUI;
import controler.ChessGameControlers;
import model.Echiquier;



/**
 * @author francoise.perrin
 * Lance l'exécution d'un jeu d'échec en mode graphique.
 * La vue (ChessGameGUI) observe le modèle (ChessGame)
 * les échanges passent par le contrôleur (ChessGameControlers)
 * 
 */
public class LauncherGUI {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		Echiquier chessGame;	
		ChessGameControlers chessGameControler;
		JFrame frame;	
		Dimension dim;
	
		dim = new Dimension(700, 700);
		
		chessGame = new Echiquier();	
		chessGameControler = new ChessGameControler(chessGame);
		
		frame = new ChessGameGUI("Jeu d'échec", chessGameControler,  dim);
		chessGame.addObserver((Observer) frame);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLocation(600, 10);
		frame.setPreferredSize(dim);
		frame.pack();
		frame.setVisible(true);
	}
}
