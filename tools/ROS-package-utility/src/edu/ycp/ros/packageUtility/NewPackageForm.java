package edu.ycp.ros.packageUtility;

import javax.swing.*;
import java.awt.*;

public class NewPackageForm {
    private JTextField tf_targetDir;
    private JTextField tf_exeName;
    private JTextField tf_pkgName;
    private JList pkgIncludesList;
    private JPanel mainPanel;

    public static void main(String[] args) {
        JFrame frame = new JFrame("ROS Package Utility - New Package");
        frame.setContentPane(new NewPackageForm().mainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
