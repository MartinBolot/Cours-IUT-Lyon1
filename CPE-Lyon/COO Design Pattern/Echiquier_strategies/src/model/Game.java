package model;



/**
 * @author francoise.perrin
 * Inspiration Jacques SARAYDARYAN, Adrien GUENARD *
 * 
 * Interface de toutes les implémentation de jeu de plateau
 * un objet Game sera l'implémentation d'un objet BoardGames
 * = mise en oeuvre du DP Bridge
 */
public interface Game  {

	
	/**
	 * @param x
	 * @param y
	 * @return true si une pièce se trouve aux coordonnées indiquées
	 */
	public boolean isPieceHere(int x, int y) ;

	/**
	 * @param xInit
	 * @param yInit
	 * @param xFinal
	 * @param yFinal
	 * @return true si  piece du jeu peut être déplacée aux coordonnées finales,
	 *  false sinon
	 */
	public boolean isMoveOk(int xInit, int yInit, int xFinal, int yFinal, boolean isCatchOk,
			boolean isCastlingPossible);

	/**
	 * @param xInit
	 * @param yInit
	 * @param xFinal
	 * @param yFinal
	 * @return true si déplacement pièce effectué
	 */
	public boolean move(int xInit, int yInit, int xFinal, int yFinal) ;


	/**
	 * @param xCatch
	 * @param yCatch
	 * @return true si la piece aux coordonnées finales
	 * a été capturée
	 */
	public boolean capture(int xCatch, int yCatch) ;



}

