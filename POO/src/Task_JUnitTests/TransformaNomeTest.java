package Task_JUnitTests;

import static org.junit.Assert.*;
import org.junit.Test;

public class TransformaNomeTest {
    @Test
    public void testMaiusculo() {
        TransformaNome tnome = new TransformaNome("Maria");
        assertEquals("MARIA",tnome.maiusculo());
    }

    @Test
    public void testMinusculo() {
        TransformaNome tnome = new TransformaNome("Maria");
        assertEquals("maria",tnome.minusculo());
    }

    @Test
    public void testBuscarBranco() {
        TransformaNome tnome = new TransformaNome("Maria Clara Machado");
        assertEquals(2,tnome.buscarBranco());
    }

    @Test
    public void testNomeInvertido(){
        TransformaNome tnome = new TransformaNome("Maria Clara Machado");
        assertEquals("odahcaM aralC airaM", tnome.nomeInvertido());
    }

    @Test
    public void testQuantidadePalavras(){
        TransformaNome tnome = new TransformaNome("Maria Clara Machado");
        assertEquals(3, tnome.quantidadePalavras());
        TransformaNome tnome1 = new TransformaNome("Igor");
        assertEquals(1, tnome1.quantidadePalavras());
    }
}