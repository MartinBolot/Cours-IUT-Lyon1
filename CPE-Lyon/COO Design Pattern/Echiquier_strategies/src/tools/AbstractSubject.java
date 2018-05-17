package tools;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public abstract class AbstractSubject implements Subject {

	public void attach(Observers o) {
		this.observers.add(o);
	}
	public void detach(Observers o) {
		this.observers.remove(o);
	}
	public void notifyObservers(Object o) {
		// version for
		/*
		for(Observers obs : observers) {
			if(obs != null) {
				obs.update(o);
			}
		}
		*/
		
		// version iterator
		Iterator<Observers> it = observers.listIterator();
		Observers obs;
		
		if(it != null) {
			while(it.hasNext()){
				obs = it.next();
				if(obs != null) {
					obs.update(o);
				}
			}
		}
	}
	
	private List<Observers> observers = new LinkedList<Observers>();
	
}
