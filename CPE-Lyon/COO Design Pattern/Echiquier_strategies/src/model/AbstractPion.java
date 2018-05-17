package model;




/**
 * @author francoise.perrin
 * Inspiration Jacques SARAYDARYAN, Adrien GUENARD*
 */
public abstract class AbstractPion extends AbstractPiece  {

	private boolean premierCoup;

	/**
	 * @param name
	 * @param couleur_de_piece
	 * @param coord
	 */
	public AbstractPion(Couleur couleur_de_piece, Coord coord) {
		super(couleur_de_piece, coord);
		this.premierCoup = true;
	}
	
	public boolean getPremierCoup() {
		return premierCoup;
	}

	/* (non-Javadoc)
	 * @see model.AbstractPiece#isMoveOk(int, int)
	 */
	@Override
	public boolean isMoveOk(int xFinal, int yFinal, boolean isCatchOk,
			boolean isCastlingPossible) {

		return this.comportement.isMoveOk(
			this.getX(),
			this.getY(),
			xFinal,
			yFinal,
			isCatchOk,
			isCastlingPossible,
			this.getCouleur(),
			this.getPremierCoup()
		);
	}


	/* (non-Javadoc)
	 * @see model.AbstractPiece#move(int, int)
	 */
	@Override
	public boolean move(int x, int y){

		boolean ret = false;

		if(Coord.coordonnees_valides(x,y)){
			this.premierCoup = false;
			ret = super.move(x, y);
		}
		return ret;
	}



}
