package com.rau;

public class ProgramLogger {
    private static volatile ProgramLogger instance;
    private static String logFile = "This is log file \n\n";

    private ProgramLogger() {
    }

    public static ProgramLogger getInstance() {
        if (instance == null)
            synchronized (ProgramLogger.class) {
                if (instance == null)
                    instance = new ProgramLogger();
            }
        return instance;
    }

    public void addLogInfo(String logInfo) {
        logFile += logInfo + "\n";
    }

    public void showLogFile() {
        System.out.println(logFile);
    }


}
