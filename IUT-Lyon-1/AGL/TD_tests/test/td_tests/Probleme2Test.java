/**
 * Tests problem 2
 */
package td_tests;

import junit.framework.TestCase;
import static junit.framework.TestCase.assertEquals;
import org.junit.Test;

/**
 *
 * @author Martin Bolot & Fanny Rottée
 */
public class Probleme2Test extends TestCase {
    
    @Override
    protected void setUp() throws Exception {
        super.setUp();
    }
    
    @Override
    protected void tearDown() throws Exception {
        super.tearDown();
    }
    
    public Probleme2Test(String testName) {
        super(testName);
    }

    /**
    *   Test constructor
    */
    @Test
    public void testConstructor() {
        Probleme2 pb = new Probleme2();
    }
    
    /**
    *   Test with "a" letter on first position
    */
    @Test
    public void testAFirst() {
        assertEquals("bcd",Probleme2.removeA("abcd"));
    }
    
    /**
    *   Test without "a" letter on first position
    */
    @Test
    public void testNoAFirst() {
        assertEquals("bbaa",Probleme2.removeA("bbaa"));
    }
    
    /**
    *   Test with two "a" letters on first position
    */
    @Test
    public void testTwoAFirst() {
        assertEquals("cd",Probleme2.removeA("aacd"));
    }
    
    /**
    *   Test with "a" letter on second postion
    */
    @Test
    public void testASecond() {
        assertEquals("bcd",Probleme2.removeA("bacd"));
    }
    
    /**
    *   Test with two "a" letters on first and last position
    */
    @Test
    public void testTwoAFirstAndTwoALast() {
        assertEquals("baa",Probleme2.removeA("aabaa"));
    }

    /**
    *   Test with "a" letter on first position on a two-letter string
    */
    @Test
    public void testAFirstTwoLetters() {
        assertEquals("b",Probleme2.removeA("ab"));
    }
    
    /**
    *   Test without the "a" letter
    */
    @Test
    public void testNoA() {
        assertEquals("b",Probleme2.removeA("b"));
    }
    
    /**
    *   Test with only an "a" letter
    */
    @Test
    public void testAOnly() {
        assertEquals("",Probleme2.removeA("a"));
    }
    
    /**
    *   Test with an empty string
    */
    @Test
    public void testEmptyString() {
        assertEquals("",Probleme2.removeA(""));
    }
}
