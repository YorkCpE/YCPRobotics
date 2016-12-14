package edu.ycp.ros.packageUtility;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class MainForm {
    private JButton createNewPackageButton;
    private JButton openPackageButton;
    private JPanel mainPanel;
    private static String DefaultRosInstallDir = "/opt/ros/";
    public static String RosInstallDir;

    public MainForm() {
        createNewPackageButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                NewPackageForm newPkgFrm = new NewPackageForm();
                SwingUtilities.getWindowAncestor(createNewPackageButton).dispose();
                newPkgFrm.main(null);
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("ROS Package Utility");
        frame.setContentPane(new MainForm().mainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
        if(!checkForRosInstall() && !Flags.DEBUG_MODE){
            Log.report(LogStrings.ROS_INSTALL_NOT_FOUND);
            try {
                LocateRosInstall();
            } catch (IOException e) {
                e.printStackTrace();
                JOptionPane.showMessageDialog(null, "Unhandled exception occurred while attempting to locate ROS installation. Stack trace:\n\n" + e.getStackTrace());
                System.exit(-1);
            }
        }
    }

    public static void LocateRosInstall() throws IOException {
        int reply = JOptionPane.showConfirmDialog(null, "Unable to find ROS in the default install location. Would you like to specify the location of your ROS install?", "ROS Install Directory Not Found", JOptionPane.YES_NO_OPTION);
        if(reply == JOptionPane.YES_OPTION){
            File rosDir = GuiUtils.selectDirectory();
            if(!rosDir.getCanonicalPath().contains("/ros")){
                JOptionPane.showMessageDialog(null, "This directory does not appear to contain a ROS install.");
                LocateRosInstall();
            } else{
                Log.report(LogStrings.OPERATION_CANCELLED);
                System.exit(0);
            }
        } else{
            Log.report(LogStrings.OPERATION_CANCELLED);
            System.exit(0);
        }
    }

    public static Boolean checkForRosInstall(){
        File defaultRosDir = new File(DefaultRosInstallDir);
        if(defaultRosDir.exists()){
            RosInstallDir = DefaultRosInstallDir;
            return true;
        } else return false;
    }
}
