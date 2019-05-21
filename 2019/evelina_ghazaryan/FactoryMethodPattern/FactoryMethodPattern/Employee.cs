using System.Collections.Generic;

namespace FactoryMethod
{
    interface Employee { }

    class Manager : Employee { }

    class WebDeveloper : Employee { }

    class MobileDeveloper : Employee { }

    class Designer : Employee { }

    class ContentWriter : Employee { }

    abstract class Team
    {
        public Team()
        {
            CreateTeam();
        }

        public abstract void CreateTeam();

        public List<Employee> Employees { get; } = new List<Employee>();
    }
    
    class WebPageTeam : Team
    {
        public override void CreateTeam()
        {
            Employees.Add(new WebDeveloper());
            Employees.Add(new WebDeveloper());
            Employees.Add(new WebDeveloper());
            Employees.Add(new Designer());
            Employees.Add(new Manager());
        }
    }

    class MobileAppTeam : Team
    {
        public override void CreateTeam()
        {
            Employees.Add(new MobileDeveloper());
            Employees.Add(new MobileDeveloper());
            Employees.Add(new MobileDeveloper());
            Employees.Add(new MobileDeveloper());
            Employees.Add(new Designer());
            Employees.Add(new Designer());
            Employees.Add(new Manager());
            Employees.Add(new ContentWriter());
        }
    }
}