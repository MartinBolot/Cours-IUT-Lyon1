package model;

import java.util.LinkedList;
import java.util.List;


/**
 * @author francoise.perrin - 
 * Inspiration Jacques SARAYDARYAN, Adrien GUENARD
 * 
 * <p>La clase Echiquier sert de facade aux jeux et piéces
 * qui ne sont pas accessibles de l'extérieur
 * C'est elle qui gére toute la logique métier des déplacements </p>
 *
 */
/**
 * @author francoise.perrin
 *
 */

public class Echiquier implements BoardGames {

	private Jeu jeuBlanc;
	private Jeu jeuNoir;
	private Jeu jeuCourant, jeuOppose;
	private String message;
	 
	private boolean isMoveOk ;
	private boolean isCatchOk;
	private boolean isPieceToMoveOk;

	private boolean isForMove;
	private boolean isCastlingPossible; 


	public Echiquier() {
		super();
		this.jeuBlanc = new Jeu(Couleur.BLANC);
		this.jeuNoir = new Jeu(Couleur.NOIR);
		this.jeuCourant = this.jeuBlanc;
		this.jeuOppose = this.jeuNoir;
		this.setMessage("Les blancs doivent commencer");
		this.isCatchOk = false;
		this.isMoveOk = false;
		this.isPieceToMoveOk = false;
		this.isCastlingPossible = false;
	}


	/**
	 * Permet de changer le joueur courant.
	 */
	public void switchJoueur() {
		if (this.jeuCourant == this.jeuBlanc) {
			this.jeuCourant = this.jeuNoir;
			this.jeuOppose = this.jeuBlanc;
		} else {
			this.jeuCourant = this.jeuBlanc;
			this.jeuOppose = this.jeuNoir;
		}
	}


	/**
	 * Permet de vérifier si une piéce peut être déplacée.
	 * <p>L'algo est le suivant : <br>
	 * 		s'il n'existe pas de piece du jeu courant aux coordonnées initiales --> false, <br>
	 * 		si les coordonnées finales ne sont pas valides ou égales aux initiales --> false, <br>
	 * 		si position finale ne correspond pas à algo de déplacement piece --> false, <br> 
	 * 		s'il existe une piéce intermédiaire sur la trajectoire --> false (sauf cavalier), <br> 
	 * 		s'il existe une piéce positionnées aux coordonnées finales :<br>
	 * 			si elle est de la méme couleur --> false ou tentative roque du roi, <br>
	 * 			sinon  :	prendre la piéce intermédiaire (vigilance pour le cas du pion)
	 * 			 			et déplacer la piéce -->true,<br>
	 * 		sinon déplacer la piéce -->true</p>
	 * @param xInit position initiale
	 * @param yInit
	 * @param xFinal
	 * @param yFinal
	 * @return true si le déplacement est effectué, false sinon
	 * 
	 */
	public boolean isMoveOk(int xInit, int yInit, int xFinal, int yFinal) {

		this.isMoveOk = false;
		this.isForMove = true;	

		//	s'il n'existe pas de piece du jeu courant aux coordonnées initiales --> false
		this.isPieceToMoveOk = jeuCourant.isPieceHere(xInit, yInit)	;
		if (!this.isPieceToMoveOk) {
			this.isMoveOk = false;
			this.setMessage("KO : c'est au tour de l'autre joueur");
		}
		else {
			this.isMoveOk = isMoveLegal(xInit,  yInit,  xFinal,  yFinal);
			
			if(!this.isMoveOk){ 
				this.setMessage("KO : la position finale ne correspond pas à "
						+ "algo de déplacement légal de la piece ");

			}
		}
		
		

		return this.isMoveOk;
	}

	private boolean isMoveLegal(int xInit, int yInit, int xFinal, int yFinal) {

		boolean isPieceOnPath = false;
		Coord coordPieceInter = null;

		this.isCatchOk = false;
		this.isMoveOk = false;
		this.isCastlingPossible = false;

		// si coordonnées finales == coordonnées initiales --> false
		if (!(xInit == xFinal &&  yInit == yFinal)){		

			//  s'il existe une pièce intermédiaire sur la trajectoire --> false (sauf cavalier)
			coordPieceInter = this.pieceOnTraject(xInit, yInit, xFinal, yFinal);
			if (coordPieceInter != null) {

				// s'il existe une piéce positionnées aux coordonnées finales :
				if (coordPieceInter.x == xFinal && coordPieceInter.y == yFinal){

					//	si elle est de la méme couleur --> false ou potentiel "roque du roi"
					if (this.jeuCourant.isPieceHere(xFinal, yFinal) ){
						this.isCastlingPossible = true;
						this.jeuCourant.setCastling();
						isPieceOnPath = true;
					}
					// si elle n'est pas de la méme couleur, elle pourrait être prise 
					else {
						this.isCatchOk = true;
						if (this.isForMove == true){
							this.jeuCourant.setPossibleCapture();
						}
					}			
				}
				// pièce intermédiaire sur la trajectoire qui empêche déplacement
				else {
					isPieceOnPath = true;
				}
			}

			//	si position finale ne correspond pas à algo de déplacement piece --> false		 
			boolean isMoveJeuOk = jeuCourant.isMoveOk(xInit, yInit, xFinal, yFinal, this.isCatchOk, this.isCastlingPossible);

			this.isMoveOk = this.isPieceToMoveOk && !isPieceOnPath && isMoveJeuOk;	
		}
		
		return this.isMoveOk;
	}

	/**
	 * Permet de déplacer une piéce connaissant ses coordonnées initiales vers ses
	 * coordonnées finales.
	 * l'algo vérifie que le déplacement est légal, 
	 * effectue ce déplacement avec l'éventuelle capture,
	 * rembobine si le déplacement et la capture ont mis le roi en échec
	 * @param xInit position initiale
	 * @param yInit
	 * @param xFinal
	 * @param yFinal
	 * @return true si le déplacement est effectué, false sinon
	 * 
	 */
	public boolean move (int xInit, int yInit, int xFinal, int yFinal){

		boolean ret = false;

		// effectuer le déplacement
		ret = this.jeuCourant.move(xInit, yInit, xFinal, yFinal);
		this.setMessage("OK : déplacement sans capture "); // message sera annulé si capture

		// effectuer l'éventuelle capture
		if (ret && this.isCatchOk) {
			this.jeuOppose.capture(xFinal, yFinal);
			this.setMessage("OK : déplacement  + capture  ");			
		}


		

		this.isCatchOk = false;
		this.isMoveOk = false;

		return ret;
	}


	/**
	 * Permet de vérifier s'il existe une piece sur la trajectoire
	 * et retourne ses coordonnées si oui.
	 * @param xInit
	 * @param yInit
	 * @param xFinal
	 * @param yFinal
	 * @return coordonnées de la 1ére piece intermédiaire rencontrée
	 * aprés scan dans toutes les directions
	 */
	private Coord pieceOnTraject(int xInit, int yInit, int xFinal, int yFinal) {
		Coord pieceOnTrajectCoord = null;

		// Mouvement rectiligne le long de l'axe Y
		if (xInit == xFinal) {

			// si vers Y croissants
			if (yFinal > yInit) {
				for (int i = yInit + 1; i <= yFinal; i++) {
					if (jeuBlanc.isPieceHere(xInit, i) || jeuNoir.isPieceHere(xInit, i)) {
						pieceOnTrajectCoord = new Coord(xInit,i);
						break;
					}
				}
			}
			// si vers Y decroissants
			if (yFinal < yInit) {				
				for (int i = yInit - 1; i >= yFinal; i--) {
					if (jeuBlanc.isPieceHere(xInit, i) || jeuNoir.isPieceHere(xInit, i)) {
						pieceOnTrajectCoord = new Coord(xInit,i);
						break;
					}
				}
			}
		} 
		else {
			// Mouvement rectiligne le long de l'axe X
			if (yInit == yFinal) { 
				// si vers X croissants
				if (xFinal > xInit) {
					for (int i = xInit + 1; i <= xFinal; i++) {
						if (jeuBlanc.isPieceHere(i, yInit) || jeuNoir.isPieceHere(i, yInit)) {
							pieceOnTrajectCoord = new Coord(i,yInit);
							break;
						}
					}
				}
				// si vers X decroissants
				if (xFinal < xInit) {
					for (int i = xInit - 1; i >= xFinal; i--) {
						if (jeuBlanc.isPieceHere(i, yInit) || jeuNoir.isPieceHere(i, yInit)) {
							pieceOnTrajectCoord = new Coord(i,yInit);
							break;
						}
					}
				}
			} 
			else {
				// Mouvement en diagonale 
				if (Math.abs(yInit - yFinal) == Math.abs(xInit - xFinal)) {
					int ecart = Math.abs(yInit - yFinal);

					// X croissant, Y croissant
					if ((xFinal - xInit > 0) && (yFinal - yInit > 0)) {
						for (int i = 1; i <= ecart; i++) {
							if (jeuBlanc.isPieceHere(xInit + i, yInit + i) || jeuNoir.isPieceHere(xInit + i, yInit + i)) {
								pieceOnTrajectCoord = new Coord(xInit + i, yInit + i);
								break;
							}						
						}
					}
					// X croissant, Y decroissant
					if ((xFinal - xInit > 0) && (yFinal - yInit < 0)) {
						for (int i = 1; i <= ecart; i++) {
							if (jeuBlanc.isPieceHere(xInit + i, yInit - i) || jeuNoir.isPieceHere(xInit + i, yInit - i)) {
								pieceOnTrajectCoord = new Coord(xInit + i, yInit - i);
								break;
							}						
						}
					}
					// X decroissant, Y decroissant
					if ((xFinal - xInit < 0) && (yFinal - yInit < 0)) {
						for (int i = 1; i <= ecart; i++) {
							if (jeuBlanc.isPieceHere(xInit - i, yInit - i) || jeuNoir.isPieceHere(xInit - i, yInit - i)) {
								pieceOnTrajectCoord = new Coord(xInit - i, yInit - i);
								break;
							}							
						}
					}					

					// X decroissant, Y croissant
					if ((xFinal - xInit < 0) && (yFinal - yInit > 0)) {
						for (int i = 1; i <= ecart; i++) {
							if (jeuBlanc.isPieceHere(xInit - i, yInit + i) || jeuNoir.isPieceHere(xInit - i, yInit + i)) {
								pieceOnTrajectCoord = new Coord(xInit - i, yInit + i);
								break;
							}							
						}
					}
				} 
				else {
					// Dans tous les autres cas de mouvement
					// la piece au coordonnées initiale est un cavalier
					if (jeuBlanc.isPieceHere(xFinal, yFinal) || jeuNoir.isPieceHere(xFinal, yFinal)) {
						pieceOnTrajectCoord = new Coord(xFinal, yFinal);			
					}	
				}
			}
		}
		return pieceOnTrajectCoord;
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 * invoque la méthode toString des 2 jeux
	 */

	public String toString() {		
		String st = "";
		st += "Jeu Blanc " + this.jeuBlanc.toString() + "\n";
		st += "Jeu Noir " + this.jeuNoir.toString() + "\n";
		return st;
	}

	/**
	 * @return couleur du jeu courant
	 */
	public Couleur getColorCurrentPlayer() {
		return this.jeuCourant.getCouleur();
	}

	public Couleur getPieceColor(int x, int y){
		return jeuCourant.getPieceColor(x, y);
	}

	/**
	 * @return message relatif aux déplacement, capture, etc.
	 */
	public String getMessage() {
		return this.message;
	}

	/**
	 * @param message
	 * ne doit pas étre accessible de l'extérieur
	 */
	private void setMessage(String message) {
		this.message = message;
	}



	public boolean isEnd() {
		// TODO Auto-generated method stub
		return false;
	}


	public static void main(String[] args) {
		Echiquier e = new Echiquier();
		boolean isMoveOK = false;
		
		System.out.println("Test classe Echiquier\n");
		
		System.out.println(e);
	
		System.out.print("\n Déplacement de 3,6 vers 3,4 = ");
		if (e.isMoveOk(3, 6, 3, 4))
			isMoveOK = e.move(3, 6, 3, 4);		// true
		System.out.println(e.getMessage() + "\n");	
		System.out.println(e);
		if (isMoveOK)
			e.switchJoueur();
		
		System.out.print("\n Déplacement de 3,4 vers 3,6 = ");		
		if (e.isMoveOk(3, 4, 3, 6))
			isMoveOK = e.move(3, 4, 3, 6); 	// false : autre joueur
		System.out.println(e.getMessage() + "\n");	
		System.out.println(e);
		e.switchJoueur();
		
		System.out.print("\n Déplacement de 3,4 vers 3,6 = ");		
		if (e.isMoveOk(3, 4, 3, 6))
			isMoveOK = e.move(3, 4, 3, 6); 	// false : algo KO
		System.out.println(e.getMessage() + "\n");	
		System.out.println(e);
		if (isMoveOK)
			e.switchJoueur();
		
		// ...
	
		
	
		
		
	}
}
