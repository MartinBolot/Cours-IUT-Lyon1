package tools;

import strategies.ComportementPieces;

public interface ModeFactory {
	public ComportementPieces getComportement(int x, int y, String ownClass);
	public ComportementPieces getInitialComportement(String ownClass);
}
