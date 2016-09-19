package edu.ycp.ros.packageUtility;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class MainMenu extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainMenu frame = new MainMenu();
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
	public MainMenu() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 286, 56);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JLabel lblRosPackageUtility = new JLabel("ROS Package Utility");
		contentPane.add(lblRosPackageUtility, BorderLayout.NORTH);
		
		JButton btnNewPackage = new JButton("New Package");
		btnNewPackage.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				NewPackageMenu.main(null);
				destroy();
			}
		});
		contentPane.add(btnNewPackage, BorderLayout.WEST);
		
		JButton btnOpenPackage = new JButton("Open Package");
		contentPane.add(btnOpenPackage, BorderLayout.EAST);
	}
	
	private void destroy(){
		this.dispose();
	}
}
