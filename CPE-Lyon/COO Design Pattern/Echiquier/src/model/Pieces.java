package model;

/**
 * @author francoise.perrin
 * Inspiration Jacques SARAYDARYAN, Adrien GUENARD *
 */
public interface Pieces {

	/**
	 * @return indice de la colonne où est positionnée la piece
	 */
	public int getX();
	
	/**
	 * @return indice de la ligne où est positionnée la piece
	 */
	public int getY();
	
	/**
	 * @return couleur de la piece
	 */
	public Couleur getCouleur();
	
	/**
	 * @return le nom de la pièce (Tour, Cavalier, etc.)
	 * attention le type ne correspond pas forcément au nom de la classe
	 */
	public String getName();

	/**
	 * @param xFinal
	 * @param yFinal
	 * @param isCastlingPossible 
	 * @param isCatchOk 
	 * @return true si déplacement légal en fonction des algo
	 * de déplacement spécifique de chaque pièce
	 */
	public  boolean isMoveOk(int xFinal, int yFinal, boolean isCatchOk, boolean isCastlingPossible) ;
	
	/**
	 * @param xFinal
	 * @param yFinal
	 * @return true si d�placement effectu�
	 */
	public boolean move(int xFinal, int yFinal);
	
	/** 
	 * @return true si piece effectivement captur�e
	 * Positionne x et y à -1
	 */
	public boolean capture();
};

