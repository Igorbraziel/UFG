package Task_JavaFiles;

import java.util.Scanner;
import java.util.Locale;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.Reader;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.Writer;

import java.io.FileInputStream;
import java.io.InputStream;

import java.io.FileOutputStream;
import java.io.OutputStream;

import java.io.File;
import java.io.IOException;

public class Main {
    public static void showLine(){
        System.out.println("--------------------------------------------");
    }

    public static void readAndWriteByteToByte(File inputFile, File outputFile){
        try {
            if(inputFile.length() == 0){
                throw new EmptyFile();
            }

            InputStream inputStreamFile = new FileInputStream(inputFile);
            OutputStream outputStreamFile = new FileOutputStream(outputFile);

            int c = inputStreamFile.read();
            showLine();
            System.out.println("Arquivo em bytes a seguir:");
            while(c != -1){
                System.out.printf("%d", c);
                outputStreamFile.write(c);
                c = inputStreamFile.read();
            }
            System.out.println();

            inputStreamFile.close();
            outputStreamFile.close();
        } catch (IOException e){
            e.printStackTrace();
        } catch (EmptyFile emptyFileException){
            System.out.println(emptyFileException.getMessage());
        } 
    }

    public static void readAndWriteLineToLine(File inputFile, File outputFile) throws EmptyFile, IOException {
        if(inputFile.length() == 0){
            throw new EmptyFile();
        }

        Reader reader = new FileReader(inputFile);
        Writer writer = new FileWriter(outputFile);
        BufferedReader br = new BufferedReader(reader);
        BufferedWriter bw = new BufferedWriter(writer);

        String line = br.readLine();
        showLine();
        System.out.println("Arquivo em linhas a seguir:");
        while(line != null){
            System.out.println(line);
            bw.write(line);
            bw.newLine();
            line = br.readLine();
        }

        br.close();
        bw.close();
    }

    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Digite o nome do arquivo original a ser lido e copiado: ");
            String originalFilePath = sc.next();
            originalFilePath = "src/Task_JavaFiles/" + originalFilePath;
            String[] fields = originalFilePath.split("\\.");
            String newFilePath1 = fields[0] + "copia1";
            String newFilePath2 = fields[0] + "copia2";

            if(fields.length == 2){
                newFilePath1 += "." + fields[1];
                newFilePath2 += "." + fields[1];
            }

            File inputFile = new File(originalFilePath);
            File outputFile1 = new File(newFilePath1);
            File outputFile2 = new File(newFilePath2);

            readAndWriteByteToByte(inputFile, outputFile1);
            readAndWriteLineToLine(inputFile, outputFile2);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (EmptyFile emptyFileException){
            System.out.println(emptyFileException.getMessage());
        } catch(Exception e){
            System.out.println(e.getMessage());
        }

        sc.close();
    }
}