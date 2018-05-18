package controler.controlerLocal;

import model.Coord;
import model.ChessGame;
import model.Couleur;
import controler.ChessGameControlers;

public class ChessGameControler implements ChessGameControlers {
	
	public ChessGameControler(ChessGame chessGame) {
		this.chessGame = chessGame;
	}
	/**
	 * @param initCoord
	 * @param finalCoord
	 * @return true si le déplacement s'est bien passé
	 */
	public boolean move(Coord initCoord, Coord finalCoord) {
		return chessGame.move(initCoord.x, initCoord.y, finalCoord.x, finalCoord.y);
	}

	/**
	 * @return message relatif aux déplacement, capture, etc.
	 */
	public String getMessage() {
		return chessGame.getMessage();
	}
	
	/**
	 * @return true si fin de partie OK (echec et mat, pat, etc.)
	 */
	public boolean isEnd() {
		return chessGame.isEnd();
	}

	/**
	 * @param initCoord
	 * @return une info dont la vue se servira 
	 * pour empêcher tout déplacement sur le damier
	 */
	public boolean isPlayerOK(Coord initCoord) {
		if(initCoord != null) {
			Couleur colorCurrentPlayer = this.chessGame.getColorCurrentPlayer();
			Couleur colorTargetPlayer = this.chessGame.getPieceColor(initCoord.x, initCoord.y);
			
			if(colorCurrentPlayer.equals(colorTargetPlayer)) {
				return true;
			}
		}
		return false;
	}
	
	public boolean isMoveOk(Coord initCoord, Coord finalCoord) {
		return this.chessGame.isMoveOk(initCoord, finalCoord);
	}
	
	public void undoMove() {
		this.chessGame.undoMove();
	}
	
	private ChessGame chessGame;
}
