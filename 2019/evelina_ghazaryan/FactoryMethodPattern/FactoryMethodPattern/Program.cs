using System;
using System.Collections.Generic;

namespace FactoryMethod
{
    class Program
    {
        static void Main(string[] args)
        {
            var teams = new List<Team>();
            teams.Add(new WebPageTeam());
            teams.Add(new MobileAppTeam());

            foreach (var team in teams)
            {
                Console.WriteLine();
                Console.WriteLine("Team: " + team.GetType().Name + " ");
                foreach (var employee in team.Employees)
                {
                    Console.WriteLine("Employee: " + employee.GetType().Name);
                }
            }
            
        }
    }
}