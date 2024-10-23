package DBMS;
import java.io.File;
import java.io.FileInputStream;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.apache.poi.ss.usermodel.Cell; 
import org.apache.poi.ss.usermodel.Row;  

public class ReadExcel {
    public static void main(String[] args) {
        try {
            FileInputStream file = new FileInputStream(new File("studentDetails.xlsx"));
            XSSFWorkbook workbook = new XSSFWorkbook(file);
            XSSFSheet sheet = workbook.getSheetAt(0);
            
            for(Row row : sheet) {
            	for(Cell cell : row) {    
                    switch (cell.getCellType()) {
                        case NUMERIC:
                            System.out.print(cell.getNumericCellValue() + "\t");
                            break;
                        case STRING:
                            System.out.print(cell.getStringCellValue() + "\t\t");
                            break;
                        default:
                            System.out.print("Unknown type\t");
                            break;
                    }
                }
            	System.out.println();
            }
 
            file.close();
            workbook.close();
 
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}