interface Contenu
{
	void encode(String texte);
	String toString();
}
class ContenuTexte implements Contenu
{
	protected String texte;
	public void encode(String texte)
	{
		this.texte = texte;
	}
	public String toString()
	{
		return (texte);
	}
}
class ContenuHtml implements Contenu
{
	protected String codeHtml;
	public void encode(String texte)
	{
		codeHtml = "<HTML>" + texte + "</HTML>";
	}
	public String toString()
	{
		return (codeHtml);
	}
}

class Courrier
{
	public Courrier(String contentType) {
		if(contentType.equalsIgnoreCase("texte")) {
			try{
				contenu = (Contenu) Class.forName("ContenuTexte").newInstance();
			} catch(Exception e) {
				System.out.println(e.getClass() + "-" + e.getMessage());
			}
		}
		else if(contentType.equalsIgnoreCase("html")) {
			try{
			contenu = (Contenu) Class.forName("ContenuHtml").newInstance();
			} catch(Exception e) {
				System.out.println(e.getClass() + "-" + e.getMessage());
			}
		}
	}
	
	protected Contenu contenu;
	protected String destinataire;

	//protected Contenu nouveauContenu();	// Factory Method

	public void prepare(String destinataire, String texte)
	{
		this.destinataire = destinataire;
		try {
			//contenu = nouveauContenu();
			contenu.encode(texte);
		} catch(Exception e) {
			System.out.println(e.getClass());
			contenu = null;
		}
	}
	public String toString()
	{
		String st = "destinataire : " + destinataire + "\n";
		st += "contenu : " + contenu.toString();
		return st;
	}
	
	public enum contentType {
		texte,
		html
	}
}

/*
class CourrierTexte extends Courrier
{
	protected Contenu nouveauContenu()
	{
		return new ContenuTexte();
	}
}
class CourrierHtml extends Courrier
{
	protected Contenu nouveauContenu()
	{
		return new ContenuHtml();
	}
}
*/

public class TestCourrier
{

	public static void main(String[] args)
	{
		Courrier courrierHtml = new Courrier("html");
		courrierHtml.prepare("adresse1@domaine", "texte1");
		System.out.println(courrierHtml);
		Courrier courrierTexte = new Courrier("texte");
		courrierTexte.prepare("adresse2@domaine", "texte2");
		System.out.println(courrierTexte);
	}

}