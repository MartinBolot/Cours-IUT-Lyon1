package model;


/**
 * @author francoise.perrin
 * * Inspiration Jacques SARAYDARYAN, Adrien GUENARD
 */
public class Roi extends AbstractPiece {
	

	/**
	 * @param name
	 * @param couleur_de_piece
	 * @param coord
	 */
	public Roi( Couleur couleur_de_piece, Coord coord) {
		super(couleur_de_piece, coord);
	}

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
			false
		);
	}

	

	
}
