package model;


import java.util.List;

import tools.ChessPiecesFactory;

/**
 * @author francoise.perrin
 * Inspiration Jacques SARAYDARYAN, Adrien GUENARD *
 */
public class Jeu implements Game {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	protected List<Pieces> pieces;
	protected Couleur couleur;

	// Toutes les variables suivantes sont partagées
	// entre les 2 instances de jeu (noir et blanc)	
	private static boolean isMoveOk;
	private static boolean isPieceToCatch;
	private static boolean isLastPion;
	private static boolean isPromotion;
	private boolean isCastling;

	// en cas d'annulation si le déplacement met le roi en échec
	private static Pieces pieceToMoveUndo; 
	private static int xInitUndo;
	private static int yInitUndo;
	private static Pieces pieceToCatchUndo; 
	private static int xFinalUndo;
	private static int yFinalUndo;


	
	/**
	 * Le constructeur de jeu fait appel � la fabrique de pi�ces
	 * @param couleur
	 * 
	 */
	public Jeu(Couleur couleur){
		this.pieces = ChessPiecesFactory.newPieces(couleur);
		this.couleur = couleur;
		isPieceToCatch = isMoveOk = false;
	}


	/**
	 * @param x
	 * @param y
	 * @return true si une pièce se trouve aux coordonnées indiquées
	 */
	public boolean isPieceHere(int x, int y) {
		boolean ret = false;

		if(this.findPiece(x, y) != null){
			ret = true;
		}
		return ret;
	}

	/**
	 * @param xInit
	 * @param yInit
	 * @param xFinal
	 * @param yFinal
	 * @param isCastlingPossible 
	 * @param isCatchOk 
	 * @return true si  piece du jeu peut être déplacée aux coordonnées finales,
	 *  false sinon
	 */
	public boolean isMoveOk(int xInit, int yInit, int xFinal, int yFinal, boolean isCatchOk, boolean isCastlingPossible){

		Pieces pieceToMove = null;
	
		isMoveOk = false;
	
		pieceToMove = this.findPiece(xInit, yInit);

		// verif déplacement autorisé 
		if (pieceToMove != null && pieceToMove.isMoveOk(xFinal, yFinal, isCatchOk, isCastlingPossible)) {
			isMoveOk = true;
		}

		
		return isMoveOk;
	}

	/**
	 * @param xInit
	 * @param yInit
	 * @param xFinal
	 * @param yFinal
	 * @return true si déplacement pièce effectué
	 */
	public boolean move(int xInit, int yInit, int xFinal, int yFinal) {
		boolean ret = false;
		Pieces pieceToMove = null;

		pieceToMove = this.findPiece(xInit, yInit);
		if (pieceToMove!=null){
			ret = pieceToMove.move(xFinal, yFinal);

			// Sauvegarde dans l'hypothèse où déplacement 
			// mettrait le roi en échec par exemple
			pieceToMoveUndo = pieceToMove;
			xInitUndo = xInit;
			yInitUndo = yInit;
			
			// Pour anticiper la promotion du pion
			isLastPion = false;			
			if(pieceToMove.getName().startsWith("Pion") ) {
				isLastPion = true;	
			}
		}
		
		
		isMoveOk = false;
		isPieceToCatch = false;
		isPromotion = false;
		
		return ret;
	}

	/**
	 * Si une capture d'une pièce de l'autre jeu est possible
	 * met à jour 1 booléen
	 */
	public void setPossibleCapture() {
		isPieceToCatch = true;
	}

	/**
	 * @param xCatch
	 * @param yCatch
	 * @return true si la piece aux coordonnées finales
	 * a été capturée
	 */
	public boolean capture(int xCatch, int yCatch) {
		boolean ret = false;
		Pieces pieceToCatch;

		pieceToCatch = this.findPiece(xCatch, yCatch);
		
		// Pour rembobiner si le roi opposé est mis en échec par exemple
		pieceToCatchUndo = pieceToCatch; 
		xFinalUndo = pieceToCatch.getX();
		yFinalUndo = pieceToCatch.getY();
		
		ret = pieceToCatch.capture();
		isPieceToCatch = false;	

		return ret;
	}



	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 * Invoque la méthode toString de chaque Pieces
	 */
	public String toString() {
		String st = "";
		st += "(";
		for (Pieces piece : pieces) {			
			st=st.concat(piece.toString());
			st += " - ";	
		}
		st += " )";
		return st;
	}


	
	/**
	 * @param x
	 * @param y
	 * @return couleur de la pièce aux coordonnées x, y
	 */
	public Couleur getPieceColor(int x, int y) {
		Couleur ret = null;
		Pieces piece = this.findPiece(x, y);
		if(piece != null){
			ret = piece.getCouleur();
		}
		return ret;
	}
	
	/**
	 * @param x
	 * @param y
	 * @return type de la pi�ce aux coordonn�es x,y
	 * c'est � dire le nom de la classe : 
	 * maPiece.getClass().getSimpleName();
	 */
	public String getPieceName(int x, int y) {
		String ret = null;
		Pieces piece = this.findPiece(x, y);
		if(piece != null){
			ret =  piece.getName();
		}
		return ret;
	}
	
	/**
	 * @return couleur du jeu
	 */
	public Couleur getCouleur() {
		return couleur;
	}
	
	

	/**
	 * @param x
	 * @param y
	 * @return la référence vers la pièce cherchée, null sinon
	 */
	private Pieces findPiece(int x, int y){
		Pieces pieceToFind = null;

		for (Pieces piece : pieces){
			if (piece.getX()==x && piece.getY()==y){
				pieceToFind = piece;
			}
		}
		return pieceToFind;
	}

	/**
	 * met à jour un booléen pour activer l'hypothèse d'un roque du roi
	 */
	public void setCastling() {
		this.isCastling = true;

	}
	

//		public static void main(String[] args) {
//			Jeu jeu = new Jeu(Couleur.BLANC);
//			System.out.println(jeu);
//		}

}

