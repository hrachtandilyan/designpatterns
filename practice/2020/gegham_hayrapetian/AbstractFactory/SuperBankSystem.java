package com.rau;

import com.rau.banking.BankingTeamFactory;
import com.rau.interfaces.Developer;
import com.rau.interfaces.ProjectManager;
import com.rau.interfaces.ProjectTeamFactory;
import com.rau.interfaces.Tester;

public class SuperBankSystem {
    public static void main(String[] args) {
        ProjectTeamFactory projectTeamFactory = new BankingTeamFactory();
        Developer developer = projectTeamFactory.getDeveloper();
        Tester tester = projectTeamFactory.getTester();
        ProjectManager projectManager = projectTeamFactory.getProjectManager();
        System.out.println("Creating bank system...");
        developer.writeCode();
        tester.testCode();
        projectManager.manageProject();
    }
}
