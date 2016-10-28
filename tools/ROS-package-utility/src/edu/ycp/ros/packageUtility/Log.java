package edu.ycp.ros.packageUtility;

import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.apache.commons.io.FileUtils;

public class Log {
	public static String logFilePath = "./logs/RosPackageUtil.log";
	private static String Now(){
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
		Date now = new Date();
		return format.format(now);
	}

	public static void report(String message){
		if(Flags.DEBUG_MODE) return;
		File logFile = new File(logFilePath);
		message = "\n" + Now() + ":" + message;
		if(!logFile.exists())
			try {
				logFile.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		
		try {
			FileUtils.writeStringToFile(logFile, message, Charset.defaultCharset());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
