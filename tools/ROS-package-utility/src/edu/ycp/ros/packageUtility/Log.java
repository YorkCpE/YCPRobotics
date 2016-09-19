package edu.ycp.ros.packageUtility;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.apache.commons.io.FileUtils;

public class Log {
	public static String logFilePath = "./RosPackageUtil.log";
	private static String Now(){
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
		Date now = new Date();
		return format.format(now);
	}
	
	@SuppressWarnings("deprecation")
	public static void report(String message){
		File logFile = new File(logFilePath);
		message = "\n" + Now() + ":" + message;
		if(!logFile.exists())
			try {
				logFile.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		
		try {
			FileUtils.writeStringToFile(logFile, message, true);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
