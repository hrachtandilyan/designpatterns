package com.rau.banking;

import com.rau.interfaces.Developer;
import com.rau.interfaces.ProjectManager;
import com.rau.interfaces.ProjectTeamFactory;
import com.rau.interfaces.Tester;

public class BankingTeamFactory implements ProjectTeamFactory {
    @Override
    public Developer getDeveloper() {
        return new JavaDeveloper();
    }

    @Override
    public Tester getTester() {
        return new QATester();
    }

    @Override
    public ProjectManager getProjectManager() {
        return new BankingPM();
    }
}
