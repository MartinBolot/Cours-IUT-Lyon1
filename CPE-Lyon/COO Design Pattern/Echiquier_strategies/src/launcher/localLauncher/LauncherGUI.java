package launcher.localLauncher;

import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

import tools.ModeFactory;
import tools.NormalStrategieFactory;
import tools.Observers;
import tools.TempeteStrategyFactory;
import model.ChessGame;
import vue.ChessGameGUI;
import controler.ChessGameControlers;
import controler.controlerLocal.ChessGameControler;



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

		ChessGame chessGame;	
		ChessGameControlers chessGameControler;
		JFrame frame;	
		Dimension dim;
	
		dim = new Dimension(700, 700);
		
		String[] modes = {"Normal", "Tempete"};
		//JOptionPane jop = new JOptionPane(), jop2 = new JOptionPane();
		String modeChoisi = (String) JOptionPane.showInputDialog(
			null, 
			"Veuillez choisir un mode de jeu",
			"Choix du mode",
			JOptionPane.QUESTION_MESSAGE,
			null,
			modes,
			modes[0]);
		
		ModeFactory modeFactory = null;
		
		if(modeChoisi.equalsIgnoreCase("Tempete")) {
			modeFactory = new TempeteStrategyFactory();
		}
		else {
			modeFactory = new NormalStrategieFactory();
		}
		
		chessGame = new ChessGame(modeFactory);
		chessGameControler = new ChessGameControler(chessGame);
		
		frame = new ChessGameGUI("Jeu d'échec", chessGameControler,  dim);
		chessGame.attach((Observers) frame);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLocation(600, 10);
		frame.setPreferredSize(dim);
		frame.pack();
		frame.setVisible(true);
	}
}
