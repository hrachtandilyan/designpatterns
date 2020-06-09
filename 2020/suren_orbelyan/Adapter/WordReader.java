public class WordReader implements AdvancedFileReader {
    @Override
    public void pdfReader(String fileName) {

    }

    @Override
    public void wordReader(String fileName){
        System.out.println("Reading WORD file: " + fileName);
    }
}
