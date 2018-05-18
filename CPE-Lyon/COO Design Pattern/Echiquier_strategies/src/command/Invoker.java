package command;

public class Invoker {
	public void execute(Command command) {
		command.execute();
	}
	
	public void undo(Command command) {
		command.unexecute();
	}
}