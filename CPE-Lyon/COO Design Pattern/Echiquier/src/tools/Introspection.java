package tools;

import java.lang.reflect.Method;
import java.util.Arrays;

import org.apache.commons.lang3.reflect.ConstructorUtils;

/**
 * @author francoise.perrin - 
 * Inspiration : http://www.jmdoudoux.fr/java/dej/chap-introspection.htm
 * 
 */
public class Introspection {

	/**
	 * private pour emp�cher de cr�er des instances de la classe
	 */
	private Introspection() {

	}

	/**
	 * Invocation d'une m�thode connaissant son nom sur un objet o
	 * en lui passant les bons param�tres
	 * 
	 * @param o - l'objet sur lequel agit la m�thode
	 * @param args - la liste des param�tres de la m�thode
	 * @param nomMethode - le nom de la m�thode
	 * @return la m�thode invoqu�e
	 * @throws Exception
	 */
	public static Object invoke(Object o, Object[] args, String nomMethode ) throws Exception	{
		Class<? extends Object>[] paramTypes = null;
		if(args != null){
			paramTypes = new Class<?>[args.length];
			for(int i=0;i<args.length;++i)	{
				paramTypes[i] = args[i].getClass();
			}
		}
		Method m = o.getClass().getMethod(nomMethode,paramTypes);
		return m.invoke(o,args);
	}


	/**
	 * @param className
	 * @param args
	 * @param nomMethode
	 * @return la méthode static invoquée
	 * @throws Exception
	 */
	public static Object invokeStatic(String className, Object[] args, String nomMethode)  throws Exception	{
		Class<? extends Object>[] paramTypes = null;
		if(args != null){
			paramTypes = new Class<?>[args.length];
			for(int i=0;i<args.length;++i)	{
				paramTypes[i] = args[i].getClass();
			}
		}
		return Class.forName(className).getMethod(nomMethode, paramTypes).invoke(null, args);
	}


	/**
	 * cr�ation d'un objet connaissant le nom de la classe
	 * utilise un constructeur sans param�tre
	 * 
	 * @param className
	 * @return le nouvel objet cr�e
	 */
	public static Object newInstance(String className) {
		Object o = null;
		try	    {
			o = Class.forName (className).newInstance ();
		}
		catch (ClassNotFoundException e)	    {
			// La classe n'existe pas
			e.printStackTrace();
		}
		catch (InstantiationException e)	    {
			// La classe est abstract ou est une interface ou n'a pas de constructeur accessible sans param�tre
			e.printStackTrace();
		}
		catch (IllegalAccessException e)	    {
			// La classe n'est pas accessible
			e.printStackTrace();
		}
		return o;
	}



	/**
	 * construction � partir du nom de la classe et des param�tres du constructeur
	 * 
	 * @param className
	 * @param args - la liste des arguments du constructeur
	 * @return le nouvel objet cr�e
	 */
	public static Object newInstance(String className, final Object... args) {
		Object o = null;
		try {
			Class<?> c = Class.forName(className);
			o = ConstructorUtils.invokeConstructor(c, args);
		} catch (Exception ex) {
			try {
				throw new InstantiationException(
						"Type '" + className +
						"' with arguments " + Arrays.asList(args) +
						" could not be instantiated: " + ex.getMessage());
			} catch (InstantiationException e) {
				// La classe est abstract ou est une interface 
				// ou n'a pas de constructeur accessible avec ces paramètres
				e.printStackTrace();
			}
		}
		return o;
	}

}
