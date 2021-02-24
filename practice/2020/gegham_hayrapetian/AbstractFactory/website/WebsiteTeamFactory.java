package com.rau.website;

import com.rau.interfaces.Developer;
import com.rau.interfaces.ProjectManager;
import com.rau.interfaces.ProjectTeamFactory;
import com.rau.interfaces.Tester;

public class WebsiteTeamFactory implements ProjectTeamFactory {
    @Override
    public Developer getDeveloper() {
        return new PhpDeveloper();
    }

    @Override
    public Tester getTester() {
        return new ManualTester();
    }

    @Override
    public ProjectManager getProjectManager() {
        return new WebsitePM() ;
    }
}
