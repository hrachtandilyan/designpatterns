public class FileAdapter implements FileReader {
    AdvancedFileReader advancedReader;
    FileAdapter(String fileType){
        if(fileType.equalsIgnoreCase("Word")){
            advancedReader =  new WordReader();
        }
        else if(fileType.equalsIgnoreCase("PDF")) {
            advancedReader = new PdfReader();
        }
    }
    @Override
    public void read(String fileType, String fileName) {
        if(fileType.equalsIgnoreCase("Word")){
            advancedReader.wordReader(fileName);
        }
        else if(fileType.equalsIgnoreCase("PDF")) {
            advancedReader.pdfReader(fileName);
        }
    }
}
