package command;

import model.ChessGame;

public class MoveCommand implements Command {

	public MoveCommand(ChessGame chessGame) {
		this.chessgame = chessGame;
	}
	
	@Override
	public void execute() {
		System.out.println("move");
	}
	
	@Override
	public void unexecute() {
		System.out.println("rollback");
		this.chessgame.undoMove();
	}
	
	protected ChessGame chessgame;
	
}
