package model;

import tools.ModeFactory;


/**
 * @author francoise.perrin
 * Inspiration Jacques SARAYDARYAN, Adrien GUENARD *
 */
public class Reine extends AbstractPiece {
	

	/**
	 * @param name
	 * @param couleur_de_piece
	 * @param coord
	 */
	public Reine(Couleur couleur_de_piece, Coord coord, ModeFactory modefactory) {
		super(couleur_de_piece, coord, modefactory);
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
			false
		);
	}

}
