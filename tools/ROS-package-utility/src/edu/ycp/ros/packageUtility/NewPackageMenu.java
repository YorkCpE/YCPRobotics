package edu.ycp.ros.packageUtility;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.io.File;
import java.io.IOException;

import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import com.jgoodies.forms.layout.FormLayout;
import com.jgoodies.forms.layout.ColumnSpec;
import com.jgoodies.forms.layout.RowSpec;
import com.jgoodies.forms.layout.FormSpecs;
import javax.swing.JButton;
import javax.swing.JSplitPane;
import javax.swing.SwingConstants;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.LayoutStyle.ComponentPlacement;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class NewPackageMenu extends JFrame {

	private JPanel contentPane;
	private static String DefaultRosInstallDir = "/opt/ros/";
	private static String RosInstallDir;
	private JTextField tbDestDir;
	private JTextField tbExeName;
	private JTextField tbPkgName;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					NewPackageMenu frame = new NewPackageMenu();
					if(!checkForRosInstall()){
						Log.report(ErrorStrings.ROS_INSTALL_NOT_FOUND);
						LocateRosInstall();
					}
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public NewPackageMenu() {
		setTitle("New ROS Package");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		tbDestDir = new JTextField();
		tbDestDir.setColumns(10);
		
		JButton btnBrowse = new JButton("Browse...");
		btnBrowse.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				File selectedDir = selectDirectory();
				try {
					tbDestDir.setText(selectedDir != null ? selectedDir.getCanonicalPath() : "");
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		
		tbExeName = new JTextField();
		tbExeName.setColumns(10);
		
		JLabel lblExecutableName = new JLabel("Executable Name:");
		
		tbPkgName = new JTextField();
		tbPkgName.setColumns(10);
		
		JLabel lblPackageName = new JLabel("Package Name:");
		
		JLabel lblSelectDestinationDirectory = new JLabel("Select Destination Directory:");
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.TRAILING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(Alignment.TRAILING, gl_contentPane.createSequentialGroup()
							.addComponent(tbDestDir, GroupLayout.DEFAULT_SIZE, 308, Short.MAX_VALUE)
							.addGap(18)
							.addComponent(btnBrowse))
						.addComponent(tbExeName, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblExecutableName)
						.addComponent(tbPkgName, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblPackageName)
						.addComponent(lblSelectDestinationDirectory))
					.addContainerGap())
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addComponent(lblSelectDestinationDirectory)
					.addPreferredGap(ComponentPlacement.RELATED)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(tbDestDir, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(btnBrowse))
					.addPreferredGap(ComponentPlacement.UNRELATED)
					.addComponent(lblExecutableName)
					.addGap(3)
					.addComponent(tbExeName, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
					.addGap(17)
					.addComponent(lblPackageName)
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(tbPkgName, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
					.addContainerGap(138, Short.MAX_VALUE))
		);
		contentPane.setLayout(gl_contentPane);
	}
	
	public static Boolean checkForRosInstall(){
		File defaultRosDir = new File(DefaultRosInstallDir);
		if(defaultRosDir.exists()){
			RosInstallDir = DefaultRosInstallDir;
			return true;
		} else return false;
	}
	
	public static void LocateRosInstall() throws IOException{
		int reply = JOptionPane.showConfirmDialog(null, "Unable to find ROS in the default install location. Would you like to specify the location of your ROS install?", "ROS Install Directory Not Found", JOptionPane.YES_NO_OPTION);
		if(reply == JOptionPane.YES_OPTION){
			JFileChooser fc = new JFileChooser();
			fc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
			int returnVal = fc.showOpenDialog(null);
			if(returnVal == JFileChooser.APPROVE_OPTION){
				File rosDir = fc.getSelectedFile();
				RosInstallDir = rosDir.getCanonicalPath();
				if(!new File(RosInstallDir.endsWith("/") ? RosInstallDir + "ros" : RosInstallDir + "/ros").exists()){
					JOptionPane.showConfirmDialog(null, "This directory does not appear to contain a ROS install!", "ROS Install Not Recognized", JOptionPane.OK_OPTION);
					LocateRosInstall();
				}
			} else{
				Log.report(ErrorStrings.OPERATION_CANCELLED);
				System.exit(0);
			}
		} else{
			Log.report(ErrorStrings.OPERATION_CANCELLED);
			System.exit(0);
		}
	}
	
	private File selectDirectory(){
		JFileChooser fc = new JFileChooser();
		fc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		int returnVal = fc.showOpenDialog(null);
		if(returnVal == JFileChooser.APPROVE_OPTION){
			return fc.getSelectedFile();
		} else return null;
	}
}
