package strategies;

import model.Couleur;

public class ComportementPion implements ComportementPieces{
	public boolean isMoveOk(int xInit, int yInit, int xFinal, int yFinal, boolean isCatchOk,
			boolean isCastlingPossible, Couleur couleur, boolean premierCoup) {

		boolean ret = false;

		// Déplacement vertical
		if (!isCatchOk && !isCastlingPossible){

			if ((xFinal == xInit)
					&& (Math.abs(yFinal - yInit) <= 1 || 
					(Math.abs(yFinal - yInit) <= 2 && premierCoup==true))) {
				
				if ((Couleur.NOIR.equals(couleur) && (yFinal - yInit > 0))
						|| (Couleur.BLANC.equals(couleur) 
								&& (yFinal - yInit < 0))) {
					ret = true;
				}
			}
		}
		// Déplacement diagonal
		else {
			if (Couleur.NOIR.equals(couleur)) {
				if ((yFinal == yInit+1 && xFinal == xInit+1) 
						|| (yFinal == yInit+1 && xFinal == xInit-1)) {
					ret = true;
				}
			}

			if (Couleur.BLANC.equals(couleur)) {
				if ((yFinal == yInit-1 && xFinal == xInit+1) 
						|| (yFinal == yInit-1 && xFinal == xInit-1)) {
					ret = true;
				}
			}
		}

		return ret;
	}

}
