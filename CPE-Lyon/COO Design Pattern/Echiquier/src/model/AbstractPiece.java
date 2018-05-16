package model;



/**
 * @author francoise.perrin
 * Inspiration Jacques SARAYDARYAN, Adrien GUENARD
 * G�re le comportement commun � toutes les pi�ces
 * Chaque classe d�riv�e (Pion, etc.) sera capable de dire 
 * si le d�placement est OK.
 */
public abstract class AbstractPiece implements Pieces {

	private int x, y;
	private Couleur couleur;
	

	/**
	 * @param name
	 * @param couleur
	 * @param coord
	 */
	public AbstractPiece(Couleur couleur, Coord coord){
		this.x = coord.x;
		this.y = coord.y;
		this.couleur=couleur;
	}

	/* (non-Javadoc)
	 * @see model.Pieces#getX()
	 */
	public int getX(){
		return this.x;
	}

	/* (non-Javadoc)
	 * @see model.Pieces#getY()
	 */
	public int getY(){
		return this.y;
	}

	/* (non-Javadoc)
	 * @see model.Pieces#getCouleur()
	 */
	public Couleur getCouleur(){
		return this.couleur;
	}

	/* (non-Javadoc)
	 * @see model.piece.Pieces#getType()
	 */
	public String getName() {
		return getClass().getSimpleName();
	}
	
	/* (non-Javadoc)
	 * @see model.Pieces#move(int, int)
	 * 
	 * Déplace une pièce
	 */
	public boolean move(int x, int y){
		boolean ret = false;
		if(Coord.coordonnees_valides(x,y)){
			this.x=x;
			this.y=y;
			ret = true;
		}
		return ret;

	}
	
	/* (non-Javadoc)
	 * @see model.Pieces#capture()
	 * 
	 * Capture une piece : 
	 * passer ses coordonn�es � -1
	 */
	public boolean capture(){
		this.x=-1;
		this.y=-1;
		return true;
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 * 
	 */
	public String toString(){	
		String S = (this.getClass().getSimpleName()).substring(0, 2) 
				+ " " + this.x + " " + this.y;
		
		return S;
	}


	/* (non-Javadoc)
	 * @see model.Pieces#isMoveOk(int, int)
	 * 
	 * En fonction du type de pièce (Pion, etc.)
	 * est capable de dire si le déplacement est OK
	 */
	public abstract boolean isMoveOk(int xFinal, int yFinal, boolean isCatchOk,
			boolean isCastlingPossible) ;

}

