package vue;

import model.Coord;
import controler.controlerLocal.ChessGameControler;



/**
 * @author francoise.perrin
 * Inspiration Jacques SARAYDARYAN, Adrien GUENARD *
 * 
 * Vue console d'un jeu d'échec
 * Cette classe est un observateur et le damier est mis à jour à chaque changement dans la classe métier
 */
public class ChessGameCmdLine  {

	ChessGameControler chessGameControler;

	public   ChessGameCmdLine(ChessGameControler chessGameControler) {
		this.chessGameControler = chessGameControler;
	}


	public void go() {

		System.out.print("\n Déplacement de 3,6 vers 3,4 = ");
		chessGameControler.move(new Coord(3,6), new Coord(3, 4));	// true
		System.out.println(chessGameControler.getMessage() + "\n");	
		System.out.println(chessGameControler);
		
		System.out.print("\n Déplacement de 3,4 vers 3,6 = ");		
		chessGameControler.move(new Coord(3,4), new Coord(3, 6));	// false 
		System.out.println(chessGameControler.getMessage() + "\n");	
		System.out.println(chessGameControler);
		
		System.out.print("\n Déplacement de 4,1 vers 4,3 = ");
		chessGameControler.move(new Coord(4, 1), new Coord(4, 3));	// true
		System.out.println(chessGameControler.getMessage() + "\n");	
		System.out.println(chessGameControler);
		
		System.out.print("\n Déplacement de 3,4 vers 3,4 = ");
		chessGameControler.move(new Coord(3, 4), new Coord(3, 4));	// false
		System.out.println(chessGameControler.getMessage() + "\n");	
		System.out.println(chessGameControler);
		
		System.out.print("\n Déplacement de 3,4 vers 4,3 = ");
		chessGameControler.move(new Coord(3, 4), new Coord(4, 3));	// true		
		System.out.println(chessGameControler.getMessage() + "\n");	
		System.out.println(chessGameControler);
	}

}
