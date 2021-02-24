public class TextReader  implements FileReader{
FileAdapter fileAdapter;
    @Override
    public void read(String fileType, String fileName) {
        if (fileType.equalsIgnoreCase("txt")){
            System.out.println("Reading TXT file: " + fileName);
        }
        else if(fileType.equalsIgnoreCase("Word")|| fileType.equalsIgnoreCase("PDF")){
            fileAdapter = new FileAdapter(fileType);
            fileAdapter.read(fileType,fileName);
        }
    }
}
