package edu.ycp.ros.packageUtility;


import javax.swing.*;
import java.io.File;

public class GuiUtils {
    public static File selectDirectory(){
        JFileChooser fc = new JFileChooser();
        fc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
        int returnVal = fc.showOpenDialog(null);
        if(returnVal == JFileChooser.APPROVE_OPTION){
            return fc.getSelectedFile();
        } else return null;
    }

    public static File selectFile(){
        JFileChooser fc = new JFileChooser();
        fc.setFileSelectionMode(JFileChooser.FILES_ONLY);
        int returnVal = fc.showOpenDialog(null);
        if(returnVal == JFileChooser.APPROVE_OPTION){
            return fc.getSelectedFile();
        } else return null;
    }

    public static File selectFileOrDirectory(){
        JFileChooser fc = new JFileChooser();
        fc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
        int returnVal = fc.showOpenDialog(null);
        if(returnVal == JFileChooser.APPROVE_OPTION){
            return fc.getSelectedFile();
        } else return null;
    }
}
