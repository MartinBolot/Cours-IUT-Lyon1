/**
 * Tests problem 1
 */
package td_tests;

import junit.framework.TestCase;
import static junit.framework.TestCase.assertEquals;
import org.junit.Test;

/**
 *
 * @author Martin Bolot & Fanny Rottée
 */
public final class Probleme1Test extends TestCase {
    
    @Override
    protected void setUp() throws Exception {
        super.setUp();
    }
    
    @Override
    protected void tearDown() throws Exception {
        super.tearDown();
    }
    
    public Probleme1Test(String testName) {
        super(testName);
    }

    /**
    *   Test constructor
    */
    @Test
    public void testConstructor() {
        Probleme1 pb = new Probleme1();
    }

    /**
    *   Test with two letters
    */
    @Test
    public void testTwoLetters() {
        assertEquals("ba",Probleme1.invertLastTwoLetters("ab"));
    }
    
    /**
    *   Test with four letters
    */
    @Test
    public void testFourLetters() {
        assertEquals("rani",Probleme1.invertLastTwoLetters("rain"));
    }
    
    /**
    *   Test with more than four letters
    */
    @Test
    public void testManyLetters() {
        assertEquals("tenrani",Probleme1.invertLastTwoLetters("tenrain"));
    }
    
    /**
    *   Test with more one letter
    */
    @Test
    public void testOneLetters() {
        assertEquals("a",Probleme1.invertLastTwoLetters("a"));
    }
    
    /**
    *   Test with an empty string
    */
    @Test
    public void testEmptyString() {
        assertEquals("",Probleme1.invertLastTwoLetters(""));
    }
}